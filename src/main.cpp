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
#include "core/Input.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <stdio.h>
#include <vector>

constexpr Uint32 FPS = 100;
constexpr Uint32 FRAME_DELAY = 1000 / FPS;

std::vector<std::unique_ptr<MenuButton>> init_menu_buttons(double button_width) {
    const double BUTTON_WIDTH_TO_HEIGHT = 367.0 / 140;
    double button_height = button_width / BUTTON_WIDTH_TO_HEIGHT;

    double Y_POS = Engine::SCREEN_HEIGHT * 0.9;
    int NUM_BUTTONS = 4;
    double gap_between_button_edges = (Engine::SCREEN_WIDTH - NUM_BUTTONS * button_width) / (NUM_BUTTONS + 1);
    std::vector<SDL_Rect> result;

    double cur_left_x = gap_between_button_edges;
    for (int i = 0; i < NUM_BUTTONS; i++) {
        result.push_back(SDL_Rect{static_cast<int>(cur_left_x), static_cast<int>(Y_POS), static_cast<int>(button_width), static_cast<int>(button_height)});
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
    SmartMusic song = ResourceManager::get().get_music("audio/music.ogg");
    Mix_PlayMusic(song.get(), -1);
}

int main(int, char *[]) {
    Engine::get().init("Undyne SDL2 Refactored");

    Scene::get().spawn(std::make_unique<Player>(1, 1));

    std::vector<std::unique_ptr<MenuButton>> menu_buttons = init_menu_buttons(0.2 * Engine::SCREEN_WIDTH);
    const double first_btn_y_center = menu_buttons.at(0)->m_y_center;
    const double first_btn_height = menu_buttons.at(0)->m_height;

    for (auto &menu_button : menu_buttons) {
        Scene::get().spawn(std::move(menu_button));
    }

    Scene::get().spawn(std::make_unique<BattleBox>(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT * 0.67, Engine::SCREEN_WIDTH * 0.9, Engine::SCREEN_HEIGHT * 0.3));
    Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

    Scene::get().spawn(std::make_unique<Undyne>(Engine::SCREEN_WIDTH * 0.57, Engine::SCREEN_HEIGHT / 4, Engine::SCREEN_HEIGHT * 0.48));
    Scene::get().spawn(std::make_unique<SelectedMenuButtonContainer>());
    Scene::get().spawn(std::make_unique<GameManager>());
    Scene::get().spawn(std::make_unique<HealthPointText>(Engine::SCREEN_WIDTH / 2, (battle_box_transform->m_y_center + battle_box_transform->m_height / 2 + first_btn_y_center - first_btn_height / 2) / 2));
    Scene::get().spawn(std::make_unique<BattleText>());
    Scene::get().spawn(std::make_unique<HelpText>());

    Scene::get().spawn(std::make_unique<VirtualController>());

    start_music();

    bool running = true;

    SDL_Event event;

    while (running) {
        Uint32 frameStart = SDL_GetTicks();

        Engine::get().update_time();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Force virtual controller and input handler to update first before any other objects
        static_cast<VirtualController *>(Scene::get().find_object_by_name("VirtualController"))->update();
        Input::get().update();

        Scene::get().cleanup_marked_objects();

        Scene::get().update_all();

        Scene::get().debug_verify_nonempty_names();

        Engine::get().clear_screen();

        Scene::get().render_all();

        Engine::get().present_screen();

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        // Gemini's solution to making the code work in both desktop and emscripten
        // Gemini explained: yields the CPU to the operating system’s scheduler
        SDL_Delay(0);
    }

    Scene::get().clear();
    ResourceManager::get().clear();
    Engine::get().cleanup();
    return 0;
}
