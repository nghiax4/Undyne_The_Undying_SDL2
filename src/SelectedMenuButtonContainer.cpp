#include "SelectedMenuButtonContainer.h"
#include "GameManager.h"
#include "Utils.h"
#include "core/Input.h"
#include "core/Scene.h"

SelectedMenuButtonContainer::SelectedMenuButtonContainer() {
    m_selected_menu_button = 0;
    m_obj_name = "SelectedMenuButtonContainer";
};

void SelectedMenuButtonContainer::update() {
    const int NUM_OF_MENU_BUTTONS = 4;

    if (static_cast<GameManager *>(Scene::get().find_object_by_name("GameManager"))->m_current_turn == Turn::PlayerTurn) {
        if (Input::get().is_key_pressed(SDL_SCANCODE_LEFT)) {
            m_selected_menu_button = (m_selected_menu_button + NUM_OF_MENU_BUTTONS - 1) % NUM_OF_MENU_BUTTONS;
            play_sound_effect("audio/menu_select_sound.ogg");
        }
        if (Input::get().is_key_pressed(SDL_SCANCODE_RIGHT)) {
            m_selected_menu_button = (m_selected_menu_button + 1) % NUM_OF_MENU_BUTTONS;
            play_sound_effect("audio/menu_select_sound.ogg");
        }
    }
}
