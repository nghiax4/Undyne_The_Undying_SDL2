#include "VirtualController.h"
#include "Globals.h"
#include "Utils.h"

VirtualController::VirtualController() {
    obj_name = "VirtualController";
    z_index = 999;

    arrow_texture.reset(loadTexture(renderer, "sprites/control_up_arrow.png"));
    enter_texture.reset(loadTexture(renderer, "sprites/control_enter_key.png"));

    SDL_SetTextureBlendMode(arrow_texture.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(arrow_texture.get(), 128);
    SDL_SetTextureBlendMode(enter_texture.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(enter_texture.get(), 128);

    int button_dimension = SCREEN_WIDTH * 0.13;
    int spacing = SCREEN_WIDTH * 0.01;

    int start_x = spacing;
    int start_y = SCREEN_HEIGHT - button_dimension - spacing;

    // Left Arrow (Rotated -90 or 270)
    buttons.push_back({{start_x, start_y, button_dimension, button_dimension}, 270.0, SDL_SCANCODE_LEFT, false});

    // Down Arrow (Rotated 180)
    buttons.push_back({{start_x + button_dimension + spacing, start_y, button_dimension, button_dimension}, 180.0, SDL_SCANCODE_DOWN, false});

    // Right Arrow (Rotated 90)
    buttons.push_back({{start_x + (button_dimension + spacing) * 2, start_y, button_dimension, button_dimension}, 90.0, SDL_SCANCODE_RIGHT, false});

    // Up Arrow (No Rotation, sits above Down Arrow)
    buttons.push_back({{start_x + button_dimension + spacing, start_y - button_dimension - spacing, button_dimension, button_dimension}, 0.0, SDL_SCANCODE_UP, false});

    // Enter key
    int enter_width = button_dimension * 1.5;
    int enter_x = SCREEN_WIDTH - enter_width - spacing;
    buttons.push_back({{enter_x, start_y, enter_width, button_dimension}, 0.0, SDL_SCANCODE_RETURN, true});
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
            int touch_x = static_cast<int>(finger->x * SCREEN_WIDTH);
            int touch_y = static_cast<int>(finger->y * SCREEN_HEIGHT);

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
        SDL_RenderCopyEx(renderer, texture_to_use, NULL, &button.screen_area, button.rotation_angle_deg, NULL, SDL_FLIP_NONE);
    }
}
