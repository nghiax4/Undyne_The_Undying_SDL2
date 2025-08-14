/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int STEP_PER_FRAME = 1;

enum class Turn { PlayerTurn, EnemyTurn };

const int ENEMY_TURN_FRAMES = 180;
const int PLAYER_WIDTH = SCREEN_WIDTH * 0.03;

const float MENU_BUTTON_WIDTH_FACTOR = 0.2;
const float MENU_BUTTON_HEIGHT = 60;

const int BATTLEBOX_NEG_WIDTH = 50;
const float BATTLEBOX_HEIGHT_FACTOR = 0.3;

enum class MenuButtons { FIGHT, ACT, ITEM, MERCY };

std::vector<SDL_Rect> makeMenuButtons(int width, int height) {
    int Y_POS = SCREEN_HEIGHT - height - height / 3;
    int NUM_BUTTONS = 4;
    int gap_between_button_edges = (SCREEN_WIDTH - NUM_BUTTONS * width) / (NUM_BUTTONS + 1);
    std::vector<SDL_Rect> result;

    int cur_left_x = gap_between_button_edges;
    for (int i = 0; i < NUM_BUTTONS; i++) {
        result.push_back(SDL_Rect{cur_left_x, Y_POS, width, height});
        cur_left_x += width + gap_between_button_edges;
    }

    return result;
}

int main(int argc, char *args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // The window we'll be rendering to
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    SDL_Rect player_rect{(SCREEN_WIDTH - PLAYER_WIDTH) / 2, (SCREEN_HEIGHT - PLAYER_WIDTH) / 2, PLAYER_WIDTH, PLAYER_WIDTH};

    std::vector<SDL_Rect> menu_buttons = makeMenuButtons(MENU_BUTTON_WIDTH_FACTOR * SCREEN_WIDTH, MENU_BUTTON_HEIGHT);
    int selected_menu_button = 0;

    Turn turn = Turn::PlayerTurn;

    SDL_Rect battleBox;
    battleBox.w = SCREEN_WIDTH - BATTLEBOX_NEG_WIDTH;
    battleBox.h = BATTLEBOX_HEIGHT_FACTOR * SCREEN_HEIGHT;
    battleBox.y = menu_buttons.at(0).y - battleBox.h * 1.1f;
    battleBox.x = (SCREEN_WIDTH - battleBox.w) / 2;

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_KEYDOWN && turn == Turn::PlayerTurn) {
                if (event.key.keysym.sym == SDLK_LEFT) {
                    selected_menu_button = (selected_menu_button - 1 + menu_buttons.size()) % menu_buttons.size();
                } else if (event.key.keysym.sym == SDLK_RIGHT) {
                    selected_menu_button = (selected_menu_button + 1) % menu_buttons.size();
                } else if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_z) {
                    turn = Turn::EnemyTurn;
                }
            }
        }

        player_rect.x = menu_buttons[selected_menu_button].x + player_rect.w / 3;
        player_rect.y = menu_buttons[selected_menu_button].y + (menu_buttons[selected_menu_button].h - player_rect.h) / 2;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &battleBox);

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);
        for (auto &button : menu_buttons) {
            SDL_RenderFillRect(renderer, &button);
        }

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &player_rect);

        SDL_RenderPresent(renderer);

        printf("Turn: %d\n", static_cast<int>(turn));
    }

    return 0;
}
