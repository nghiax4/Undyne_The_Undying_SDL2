#include "BattleBox.h"
#include "GameManager.h"
#include "GameObject.h"
#include "HealthPointText.h"
#include "MenuButton.h"
#include "Player.h"
#include "SelectedMenuButtonContainer.h"
#include "Turn.h"
#include "Undyne.h"
#include "Utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

Mix_Music *song;
double deltaTime;
int last_tick = 0;
SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;
std::vector<GameObject *> objs;
std::vector<Uint8> prev_keyboard_state;
std::vector<Uint8> cur_keyboard_state;
int time_since_enemy_turn = 0;
int current_attack_idx = 0;
Turn current_turn = Turn::PlayerTurn;

std::vector<MenuButton> init_menu_buttons(int button_width) {
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

    return {fight_button, act_button, item_button, mercy_button};
}

void start_music() {
    song = Mix_LoadMUS("audio/music.ogg");
    if (song == NULL) {
        throw std::runtime_error(std::string("Failed to load music: ") + Mix_GetError());
    }
    Mix_PlayMusic(song, -1);
}

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        throw;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        throw;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        throw;
    }

    window = SDL_CreateWindow("Undyne SDL2 wip", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);

    objs.push_back(new Player(1, 1));

    std::vector<MenuButton> menu_buttons = init_menu_buttons(0.2 * SCREEN_WIDTH);

    for (auto &menu_button : menu_buttons) {
        objs.push_back(&menu_button);
    }

    BattleBox *battlebox = new BattleBox(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.67, SCREEN_WIDTH * 0.9, SCREEN_HEIGHT * 0.3);
    objs.push_back(battlebox);
    objs.push_back(new Undyne(SCREEN_WIDTH * 0.57, SCREEN_HEIGHT / 4, SCREEN_HEIGHT * 0.48));
    objs.push_back(new SelectedMenuButtonContainer());
    objs.push_back(new GameManager());
    objs.push_back(new HealthPointText(SCREEN_WIDTH / 2, (battlebox->y_center + battlebox->height / 2 + menu_buttons.at(0).y_center - menu_buttons.at(0).height / 2) / 2));

    start_music();

    bool running = true;

    while (running) {
        Uint32 now = SDL_GetTicks();
        deltaTime = now - last_tick;
        last_tick = now;

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

        _remove_objs_that_are_to_be_removed();
        // _print_objs_names();
        _verify_objs_correct();

        for (auto &obj : objs) {
            obj->update();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        sort(objs.begin(), objs.end(), [](const GameObject *obj1, const GameObject *obj2) { return obj1->z_index < obj2->z_index; });

        for (auto &obj : objs) {
            if (obj->show) {
                obj->render();
            }
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
