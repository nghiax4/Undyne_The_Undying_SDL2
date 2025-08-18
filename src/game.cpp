/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

enum class Turn { PlayerTurn, EnemyTurn };

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path) {
    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

struct Player {
    SDL_Texture *player_texture;
    SDL_Renderer *renderer;
    int x_center, y_center, width, height;

    Player(int width, int height, int x_center, int y_center, SDL_Renderer *renderer, std::string path) : width(width), height(height), x_center(x_center), y_center(y_center), renderer(renderer) {
        player_texture = loadTexture(renderer, path.c_str());
    }

    void render() {
        int left_x = x_center - width / 2;
        int top_y = y_center - height / 2;

        SDL_Rect *player_rect = new SDL_Rect({left_x, top_y, width, height});

        SDL_RenderCopy(renderer, player_texture, NULL, player_rect);
    }
};

struct Game {
    const int screen_width;
    const int screen_height;
    const int player_width;
    int selected_menu_button = 0;
    bool running = false;

    SDL_Window *window;
    SDL_Renderer *renderer;
    Player *player;
    Turn current_turn = Turn::PlayerTurn;
    SDL_Rect *battleBox;

    std::vector<SDL_Rect> menu_buttons;

    const int STEP_PER_FRAME = 1;
    const int ENEMY_TURN_FRAMES = 180;
    const float MENU_BUTTON_WIDTH_FACTOR = 0.2;
    const float MENU_BUTTON_HEIGHT = 60;
    const int BATTLEBOX_NEG_WIDTH = 50;
    const float BATTLEBOX_HEIGHT_FACTOR = 0.3;

    enum class MenuButtons { FIGHT, ACT, ITEM, MERCY };

    std::vector<SDL_Rect> makeMenuButtons(int width, int height) {
        int Y_POS = screen_height - height - height / 3;
        int NUM_BUTTONS = 4;
        int gap_between_button_edges = (screen_width - NUM_BUTTONS * width) / (NUM_BUTTONS + 1);
        std::vector<SDL_Rect> result;

        int cur_left_x = gap_between_button_edges;
        for (int i = 0; i < NUM_BUTTONS; i++) {
            result.push_back(SDL_Rect{cur_left_x, Y_POS, width, height});
            cur_left_x += width + gap_between_button_edges;
        }

        return result;
    }

    Game(int screen_width, int screen_height) : screen_width(screen_width), screen_height(screen_height), player_width(screen_width * 0.03) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            throw;
        }

        // The window we'll be rendering to
        window = SDL_CreateWindow("Undyne SDL2 wip", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

        player = new Player(player_width, player_width, 1, 1, renderer, "sprites/soul.png");

        menu_buttons = makeMenuButtons(MENU_BUTTON_WIDTH_FACTOR * screen_width, MENU_BUTTON_HEIGHT);

        battleBox = new SDL_Rect{};
        battleBox->w = screen_width - BATTLEBOX_NEG_WIDTH;
        battleBox->h = BATTLEBOX_HEIGHT_FACTOR * screen_height;
        battleBox->y = menu_buttons.at(0).y - battleBox->h * 1.1f;
        battleBox->x = (screen_width - battleBox->w) / 2;

        running = true;
    }

    void update() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_KEYDOWN && current_turn == Turn::PlayerTurn) {
                if (event.key.keysym.sym == SDLK_LEFT) {
                    selected_menu_button = (selected_menu_button - 1 + menu_buttons.size()) % menu_buttons.size();
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    selected_menu_button = (selected_menu_button + 1) % menu_buttons.size();
                } else if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_z) {
                    current_turn = Turn::EnemyTurn;
                }
            }
        }

        player->x_center = menu_buttons[selected_menu_button].x + player->width;
        player->y_center = menu_buttons[selected_menu_button].y + menu_buttons[selected_menu_button].h / 2;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer, battleBox);

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);
        for (auto &button : menu_buttons) {
            SDL_RenderFillRect(renderer, &button);
        }

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);

        player->render();

        SDL_RenderPresent(renderer);

        printf("Turn: %d\n", static_cast<int>(current_turn));
    }
};