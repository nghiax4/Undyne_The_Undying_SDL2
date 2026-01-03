#include "Input.h"
#include <algorithm>
#include <cassert>
#include <cstring>

void Input::update() {
    // 1. Fetch raw SDL keyboard state
    if (!sdl_key_states) {
        sdl_key_states = SDL_GetKeyboardState(&num_keys);
        current_state.resize(num_keys, 0);
        previous_state.resize(num_keys, 0);
        virtual_key_state.resize(num_keys, 0);
    }

    // 2. Save current as previous
    previous_state = current_state;

    // 3. Update current from SDL + Virtual Buffer
    // We combine physical key press OR virtual key press
    for (int i = 0; i < num_keys; i++) {
        current_state[i] = sdl_key_states[i] | virtual_key_state[i];
    }

    // 4. Reset virtual keys buffer
    std::fill(virtual_key_state.begin(), virtual_key_state.end(), 0);
}

void Input::set_virtual_key(SDL_Scancode key, bool down) {
    assert(0 <= key && key < num_keys);
    virtual_key_state[key] = down ? 1 : 0;
}

bool Input::is_key_down(SDL_Scancode key) const {
    assert(0 <= key && key < num_keys);
    return current_state[key] != 0;
}

bool Input::is_key_pressed(SDL_Scancode key) const {
    assert(0 <= key && key < num_keys);
    return current_state[key] != 0 && previous_state[key] == 0;
}
