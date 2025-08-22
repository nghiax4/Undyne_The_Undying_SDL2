#include "GameObject.h"
#include "MenuButton.h"
#include "Player.h"
#include "SelectedMenuButtonContainer.h"
#include "Turn.h"
#include "Utils.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <stdio.h>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

double deltaTime;
int last_tick = 0;
SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;
std::vector<GameObject *> objs;
std::vector<Uint8> prev_keyboard_state;
std::vector<Uint8> cur_keyboard_state;
Turn current_turn = Turn::PlayerTurn;

std::vector<MenuButton> init_menu_buttons(int button_width) {
    const double BUTTON_WIDTH_TO_HEIGHT = 110.0 / 42;
    int button_height = button_width / BUTTON_WIDTH_TO_HEIGHT;
    printf("Making buttons of size: %d %d\n", button_width, button_height);

    int Y_POS = SCREEN_HEIGHT - button_height - button_height / 3;
    int NUM_BUTTONS = 4;
    int gap_between_button_edges = (SCREEN_WIDTH - NUM_BUTTONS * button_width) / (NUM_BUTTONS + 1);
    std::vector<SDL_Rect> result;

    int cur_left_x = gap_between_button_edges;
    for (int i = 0; i < NUM_BUTTONS; i++) {
        result.push_back(SDL_Rect{cur_left_x, Y_POS, button_width, button_height});
        cur_left_x += button_width + gap_between_button_edges;
    }

    MenuButton fight_button(result.at(0).x + button_width / 2, result.at(0).y + button_height / 2, button_width, button_height, "sprites/fight_unselected.png", "sprites/fight_selected.png", 0);
    MenuButton act_button(result.at(1).x + button_width / 2, result.at(0).y + button_height / 2, button_width, button_height, "sprites/act_unselected.png", "sprites/act_selected.png", 1);
    MenuButton item_button(result.at(2).x + button_width / 2, result.at(2).y + button_height / 2, button_width, button_height, "sprites/item_unselected.png", "sprites/item_selected.png", 2);
    MenuButton mercy_button(result.at(3).x + button_width / 2, result.at(3).y + button_height / 2, button_width, button_height, "sprites/mercy_unselected.png", "sprites/mercy_selected.png", 3);

    return {fight_button, act_button, item_button, mercy_button};
}

struct BattleBox : public GameObject {
  public:
    int x_center, y_center, width, height;

    BattleBox(int x_center, int y_center, int width, int height) : x_center(x_center), y_center(y_center), width(width), height(height) { obj_name = "BattleBox"; }

    void update() override {}

    void render() override {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_Rect rect{x_center - width / 2, y_center - height / 2, width, height};
        SDL_RenderDrawRect(renderer, &rect);
    }
};

struct Undyne : public GameObject {
    const double UNDYNE_SPRITE_WIDTH_OVER_HEIGHT = 314.0 / 246;
    const int MILLISECOND_BETWEEN_SPRITE_FRAME = 30;

    int x_center, y_center, width, height;
    // int secondOfLastSpriteFrame = 0;
    double time_elapsed_since_last_sprite_frame = 0;
    int current_sprite_frame = 0;
    const int NUM_OF_SPRITE_FRAMES = 107;

    Undyne(int x_center, int y_center, int height) : x_center(x_center), y_center(y_center), height(height), width(height * UNDYNE_SPRITE_WIDTH_OVER_HEIGHT) { obj_name = "Undyne"; }

    void update() override {
        time_elapsed_since_last_sprite_frame += deltaTime;
        if (time_elapsed_since_last_sprite_frame > MILLISECOND_BETWEEN_SPRITE_FRAME) {
            current_sprite_frame = (current_sprite_frame + 1) % NUM_OF_SPRITE_FRAMES;
            time_elapsed_since_last_sprite_frame = 0;
        }
    }

    void render() override {
        std::string current_sprite_frame_correctlength = std::to_string(current_sprite_frame);
        while (current_sprite_frame_correctlength.size() < 3)
            current_sprite_frame_correctlength = "0" + current_sprite_frame_correctlength;
        std::string sprite_filename = "sprites/undyne_sprite/frame_" + current_sprite_frame_correctlength + ".png";

        SDL_Texture *texture = loadTexture(renderer, sprite_filename);
        SDL_Rect *rect = new SDL_Rect({x_center - width / 2, y_center - height / 2, width, height});
        SDL_RenderCopy(renderer, texture, NULL, rect);
    }
};

void _print_all_objs_names() {
    printf("All objects names:\n");
    for (const auto &obj : objs) {
        printf("- %s\n", obj->obj_name.c_str());
    }
    printf("\n");
}

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        throw;
    }

    // The window we'll be rendering to
    window = SDL_CreateWindow("Undyne SDL2 wip", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);

    objs.push_back(new Player(1, 1, SCREEN_WIDTH * 0.03, SCREEN_WIDTH * 0.03, "sprites/soul.png", 2));

    std::vector<MenuButton> menu_buttons = init_menu_buttons(0.2 * SCREEN_WIDTH);

    for (auto &menu_button : menu_buttons) {
        objs.push_back(&menu_button);
    }

    objs.push_back(new BattleBox(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.67, SCREEN_WIDTH * 0.9, SCREEN_HEIGHT * 0.3));
    objs.push_back(new Undyne(SCREEN_WIDTH * 0.57, SCREEN_HEIGHT / 4, SCREEN_HEIGHT * 0.48));
    objs.push_back(new SelectedMenuButtonContainer());

    bool running = true;

    while (running) {
        Uint32 now = SDL_GetTicks();
        deltaTime = now - last_tick;
        last_tick = now;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                exit(0);
            }
        }

        int num_keys;
        const Uint8 *sdl_keys = SDL_GetKeyboardState(&num_keys);
        cur_keyboard_state.assign(sdl_keys, sdl_keys + num_keys);

        if (prev_keyboard_state.empty()) {
            prev_keyboard_state.resize(num_keys, 0);
        }

        for (auto &obj : objs) {
            obj->update();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        sort(objs.begin(), objs.end(), [](const GameObject *obj1, const GameObject *obj2) { return obj1->z_index < obj2->z_index; });

        for (auto &obj : objs) {
            obj->render();
        }

        SDL_RenderPresent(renderer);

        int frameTime = SDL_GetTicks() - now;

        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        prev_keyboard_state = cur_keyboard_state;
    }
    return 0;
}
