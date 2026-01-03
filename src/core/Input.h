#pragma once
#include <SDL2/SDL.h>
#include <vector>

class Input {
  public:
    static Input &get() {
        static Input instance;
        return instance;
    }

    // Called once per frame at the start
    void update();

    // Key checks
    bool is_key_down(SDL_Scancode key) const;
    bool is_key_pressed(SDL_Scancode key) const; // True only on the frame it was pressed and not pressed in the previous frame

    // Virtual Controller support (Touch)
    // Allows VirtualController to "press" a key virtually
    void set_virtual_key(SDL_Scancode key, bool down);

  private:
    Input() = default;

    int num_keys = 0;
    const Uint8 *sdl_key_states = nullptr;

    std::vector<Uint8> current_state;
    std::vector<Uint8> previous_state;

    // Buffer for virtual keys (button presses on mobile)
    // Needs to be reset manually each frame because it's not handled by SDL_GetKeyboardState()
    std::vector<Uint8> virtual_key_state;
};
