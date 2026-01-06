#include "Input.h"
#include <algorithm>
#include <cassert>
#include <cstring>

void Input::update() {
    // 1. Fetch raw SDL keyboard state
    if (!m_sdl_key_states) {
        m_sdl_key_states = SDL_GetKeyboardState(&m_num_keys);
        assert(m_num_keys >= 0);
        m_current_state.resize(static_cast<size_t>(m_num_keys), 0);
        m_previous_state.resize(static_cast<size_t>(m_num_keys), 0);
        m_virtual_key_state.resize(static_cast<size_t>(m_num_keys), 0);
    }

    // 2. Save current as previous
    m_previous_state = m_current_state;

    // 3. Update current from SDL + Virtual Buffer
    // We combine physical key press OR virtual key press
    for (size_t i = 0; i < static_cast<size_t>(m_num_keys); i++) {
        m_current_state[i] = m_sdl_key_states[i] | m_virtual_key_state[i];
    }

    // 4. Reset virtual keys buffer
    std::fill(m_virtual_key_state.begin(), m_virtual_key_state.end(), 0);
}

void Input::set_virtual_key(SDL_Scancode key, bool down) {
    assert(0 <= key && key < m_num_keys);
    m_virtual_key_state[key] = down ? 1 : 0;
}

bool Input::is_key_down(SDL_Scancode key) const {
    assert(0 <= key && key < m_num_keys);
    return m_current_state[key] != 0;
}

bool Input::is_key_pressed(SDL_Scancode key) const {
    assert(0 <= key && key < m_num_keys);
    return m_current_state[key] != 0 && m_previous_state[key] == 0;
}
