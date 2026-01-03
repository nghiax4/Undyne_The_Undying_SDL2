#include "VirtualController.h"
#include "Globals.h"
#include "Utils.h"
#include "core/Engine.h"

VirtualController::VirtualController() {
    obj_name = "VirtualController";
    z_index = 999;

    arrow_texture.reset(loadTexture("sprites/control_up_arrow.png"));
    enter_texture.reset(loadTexture("sprites/control_enter_key.png"));

    SDL_SetTextureBlendMode(arrow_texture.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(arrow_texture.get(), 128);
    SDL_SetTextureBlendMode(enter_texture.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(enter_texture.get(), 128);

    int btn_size = Engine::get().get_screen_width() * 0.14;

    int dpad_radius = btn_size * 0.85;

    int padding = Engine::get().get_screen_width() * 0.04;

    int dpad_center_x = padding + btn_size;
    int dpad_center_y = Engine::get().get_screen_height() - padding - btn_size;

    // Helper lambda to create a centered rectangle
    auto make_rect = [&](int center_x, int center_y, int w, int h) {
        return SDL_Rect{center_x - w / 2, center_y - h / 2, w, h};
    };

    // UP
    buttons.push_back({make_rect(dpad_center_x, dpad_center_y - dpad_radius, btn_size, btn_size), 0.0, SDL_SCANCODE_UP, false});

    // DOWN
    buttons.push_back({make_rect(dpad_center_x, dpad_center_y + dpad_radius, btn_size, btn_size), 180.0, SDL_SCANCODE_DOWN, false});

    // LEFT
    buttons.push_back({make_rect(dpad_center_x - dpad_radius, dpad_center_y, btn_size, btn_size), 270.0, SDL_SCANCODE_LEFT, false});

    // RIGHT
    buttons.push_back({make_rect(dpad_center_x + dpad_radius, dpad_center_y, btn_size, btn_size), 90.0, SDL_SCANCODE_RIGHT, false});

    // -- ENTER KEY --
    int enter_width = btn_size * 1.5;
    int enter_center_x = Engine::get().get_screen_width() - padding - (enter_width / 2);
    int enter_center_y = dpad_center_y;

    buttons.push_back({make_rect(enter_center_x, enter_center_y, enter_width, btn_size), 0.0, SDL_SCANCODE_RETURN, true});
}

void VirtualController::update() {
    // SDL can expose multiple touch devices (not just the screen eg touchscreen + external touch monitor, touchpads...)
    // Also on some platforms SDL may report 0 touch devices until the user touches the screen once
    int num_devices = SDL_GetNumTouchDevices();

    for (int i = 0; i < num_devices; i++) {
        SDL_TouchID touchID = SDL_GetTouchDevice(i);
        if (touchID == 0)
            continue; // Invalid device

        int num_fingers = SDL_GetNumTouchFingers(touchID);
        for (int j = 0; j < num_fingers; j++) {
            SDL_Finger *finger = SDL_GetTouchFinger(touchID, j);
            if (!finger)
                continue;

            // finger->x and finger->y are percentages of the window size
            int touch_x = static_cast<int>(finger->x * Engine::get().get_screen_width());
            int touch_y = static_cast<int>(finger->y * Engine::get().get_screen_height());

            SDL_Point touch_point = {touch_x, touch_y};

            for (const auto &button : buttons) {
                if (SDL_PointInRect(&touch_point, &button.screen_area)) {
                    cur_keyboard_state[button.scancode_target] = 1;
                }
            }
        }
    }
}

void VirtualController::render() {
    for (const auto &button : buttons) {
        SDL_Texture *texture_to_use = button.is_enter_key ? enter_texture.get() : arrow_texture.get();
        SDL_RenderCopyEx(Engine::get().get_renderer(), texture_to_use, NULL, &button.screen_area, button.rotation_angle_deg, NULL, SDL_FLIP_NONE);
    }
}
