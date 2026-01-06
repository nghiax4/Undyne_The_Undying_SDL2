#include "VirtualController.h"

#include "Utils.h"
#include "core/Engine.h"
#include "core/Input.h"

VirtualController::VirtualController() {
    m_obj_name = "VirtualController";
    m_z_index = 999;

    m_arrow_texture = ResourceManager::get().get_texture("sprites/control_up_arrow.png");
    m_enter_texture = ResourceManager::get().get_texture("sprites/control_enter_key.png");

    double btn_size = Engine::SCREEN_WIDTH * 0.14;

    double dpad_radius = btn_size * 0.85;

    double padding = Engine::SCREEN_WIDTH * 0.04;

    double dpad_center_x = padding + btn_size;
    double dpad_center_y = Engine::SCREEN_HEIGHT - padding - btn_size;

    // Helper lambda to create a centered rectangle
    auto make_rect = [&](double center_x, double center_y, double w, double h) {
        return SDL_Rect{static_cast<int>(center_x - w / 2), static_cast<int>(center_y - h / 2), static_cast<int>(w), static_cast<int>(h)};
    };

    // UP
    m_buttons.push_back({make_rect(dpad_center_x, dpad_center_y - dpad_radius, btn_size, btn_size), 0.0, SDL_SCANCODE_UP, false});

    // DOWN
    m_buttons.push_back({make_rect(dpad_center_x, dpad_center_y + dpad_radius, btn_size, btn_size), 180.0, SDL_SCANCODE_DOWN, false});

    // LEFT
    m_buttons.push_back({make_rect(dpad_center_x - dpad_radius, dpad_center_y, btn_size, btn_size), 270.0, SDL_SCANCODE_LEFT, false});

    // RIGHT
    m_buttons.push_back({make_rect(dpad_center_x + dpad_radius, dpad_center_y, btn_size, btn_size), 90.0, SDL_SCANCODE_RIGHT, false});

    // -- ENTER KEY --
    double enter_width = btn_size * 1.5;
    double enter_center_x = Engine::SCREEN_WIDTH - padding - (enter_width / 2);
    double enter_center_y = dpad_center_y;

    m_buttons.push_back({make_rect(enter_center_x, enter_center_y, enter_width, btn_size), 0.0, SDL_SCANCODE_RETURN, true});
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
            int touch_x = static_cast<int>(static_cast<double>(finger->x) * Engine::SCREEN_WIDTH);
            int touch_y = static_cast<int>(static_cast<double>(finger->y) * Engine::SCREEN_HEIGHT);

            SDL_Point touch_point = {touch_x, touch_y};

            for (const auto &button : m_buttons) {
                if (SDL_PointInRect(&touch_point, &button.m_screen_area)) {
                    Input::get().set_virtual_key(button.m_scancode_target, true);
                }
            }
        }
    }
}

void VirtualController::render() {
    for (const auto &button : m_buttons) {
        SmartTexture texture = button.m_is_enter_key ? m_enter_texture : m_arrow_texture;

        double x_center = button.m_screen_area.x + button.m_screen_area.w / 2.0;
        double y_center = button.m_screen_area.y + button.m_screen_area.h / 2.0;

        Engine::get().draw_texture(texture, x_center, y_center, button.m_screen_area.w, button.m_screen_area.h, button.m_rotation_angle_deg, 128);
    }
}
