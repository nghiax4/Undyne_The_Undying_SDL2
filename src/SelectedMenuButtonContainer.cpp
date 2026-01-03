#include "SelectedMenuButtonContainer.h"
#include "Globals.h"
#include "Utils.h"
#include "core/Input.h"

SelectedMenuButtonContainer::SelectedMenuButtonContainer() {
    selected_menu_button = 0;
    obj_name = "SelectedMenuButtonContainer";
};

void SelectedMenuButtonContainer::update() {
    const int NUM_OF_MENU_BUTTONS = 4;

    if (current_turn == Turn::PlayerTurn) {
        if (Input::get().is_key_pressed(SDL_SCANCODE_LEFT)) {
            selected_menu_button = (selected_menu_button - 1 + NUM_OF_MENU_BUTTONS) % NUM_OF_MENU_BUTTONS;
            play_sound_effect("audio/menu_select_sound.ogg");
        }
        if (Input::get().is_key_pressed(SDL_SCANCODE_RIGHT)) {
            selected_menu_button = (selected_menu_button + 1) % NUM_OF_MENU_BUTTONS;
            play_sound_effect("audio/menu_select_sound.ogg");
        }
    }
}
