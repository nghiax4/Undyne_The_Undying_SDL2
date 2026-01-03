#include "BattleBox.h"
#include "BattleText.h"
#include "GameManager.h"
#include "GameObject.h"
#include "HealthPointText.h"
#include "HelpText.h"
#include "MenuButton.h"
#include "Player.h"
#include "SelectedMenuButtonContainer.h"
#include "Turn.h"
#include "Undyne.h"
#include "Utils.h"
#include "VirtualController.h"
#include "core/Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <stdio.h>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 100;
const int FRAME_DELAY = 1000 / FPS;

Mix_Music *song = nullptr;
double deltaTime;
int last_tick = 0;
SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;
std::vector<std::unique_ptr<GameObject>> objs;
std::vector<Uint8> prev_keyboard_state;
std::vector<Uint8> cur_keyboard_state;
int time_since_enemy_turn = 0;
int current_attack_idx = 0;
Turn current_turn = Turn::PlayerTurn;
BattleBox *global_battlebox = nullptr;
VirtualController *global_virtual_controller = nullptr;

std::vector<std::unique_ptr<MenuButton>> init_menu_buttons(int button_width) {
    const double BUTTON_WIDTH_TO_HEIGHT = 367.0 / 140;
    int button_height = button_width / BUTTON_WIDTH_TO_HEIGHT;

    int Y_POS = SCREEN_HEIGHT * 0.9;
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

    std::vector<std::unique_ptr<MenuButton>> result_vector;
    result_vector.push_back(std::make_unique<MenuButton>(std::move(fight_button)));
    result_vector.push_back(std::make_unique<MenuButton>(std::move(act_button)));
    result_vector.push_back(std::make_unique<MenuButton>(std::move(item_button)));
    result_vector.push_back(std::make_unique<MenuButton>(std::move(mercy_button)));

    return result_vector;
}

void start_music() {
    song = Mix_LoadMUS("audio/music.ogg");
    if (song == NULL) {
        throw std::runtime_error(std::string("Failed to load music: ") + Mix_GetError());
    }
    Mix_PlayMusic(song, -1);
}

int main(int argc, char *args[]) {
    Engine::get().init("Undyne SDL2 Refactored", SCREEN_WIDTH, SCREEN_HEIGHT);

    objs.push_back(std::make_unique<Player>(1, 1));

    std::vector<std::unique_ptr<MenuButton>> menu_buttons = init_menu_buttons(0.2 * SCREEN_WIDTH);
    const int first_btn_y_center = menu_buttons.at(0)->y_center;
    const int first_btn_height = menu_buttons.at(0)->height;

    for (auto &menu_button : menu_buttons) {
        objs.push_back(std::move(menu_button));
    }

    auto battlebox = std::make_unique<BattleBox>(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.67, SCREEN_WIDTH * 0.9, SCREEN_HEIGHT * 0.3);
    global_battlebox = battlebox.get();
    objs.push_back(std::move(battlebox));
    objs.push_back(std::make_unique<Undyne>(SCREEN_WIDTH * 0.57, SCREEN_HEIGHT / 4, SCREEN_HEIGHT * 0.48));
    objs.push_back(std::make_unique<SelectedMenuButtonContainer>());
    objs.push_back(std::make_unique<GameManager>());
    objs.push_back(std::make_unique<HealthPointText>(SCREEN_WIDTH / 2, (global_battlebox->y_center + global_battlebox->height / 2 + first_btn_y_center - first_btn_height / 2) / 2));
    objs.push_back(std::make_unique<BattleText>());
    objs.push_back(std::make_unique<HelpText>());

    std::unique_ptr<VirtualController> virtual_controller_ptr = std::make_unique<VirtualController>();
    global_virtual_controller = virtual_controller_ptr.get();
    objs.push_back(std::move(virtual_controller_ptr));

    start_music();

    bool running = true;

    while (running) {
        Uint32 frameStart = SDL_GetTicks();

        Engine::get().update_time();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        int num_keys;
        const Uint8 *sdl_keys = SDL_GetKeyboardState(&num_keys);
        cur_keyboard_state.assign(sdl_keys, sdl_keys + num_keys);
        if (prev_keyboard_state.empty()) {
            prev_keyboard_state.resize(num_keys, 0);
        }

        // Force virtual controller to update first before any other objects
        global_virtual_controller->update();

        _remove_objs_that_are_to_be_removed();
        // _print_objs_names();
        _verify_objs_correct();

        // Use index instead of iterator to handle vector resizing during update
        for (size_t i = 0; i < objs.size(); i++) {
            objs[i]->update();
        }

        Engine::get().clear_screen();

        sort(objs.begin(), objs.end(), [](const std::unique_ptr<GameObject> &obj1, const std::unique_ptr<GameObject> &obj2) {
            return obj1->z_index < obj2->z_index;
        });

        for (auto &obj : objs) {
            if (obj->show) {
                obj->render();
            }
        }

        Engine::get().present_screen();

        int frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        // Gemini's solution to making the code work in both desktop and emscripten
        // Gemini explained: yields the CPU to the operating system’s scheduler
        SDL_Delay(0);

        prev_keyboard_state = cur_keyboard_state;
    }
    return 0;
}
