#include "White_Arrow_Medium_Box_Attack.h"
#include "GameObject.h"
#include "Globals.h"
#include "Utils.h"
#include "core/Engine.h"
#include <string>

White_Arrow_Medium_Box_Attack::White_Arrow_Medium_Box_Attack(int x_center, int y_center, int x_target, int y_target, std::string obj_name, int delay_before_charge_ms) : x_center(x_center), y_center(y_center), x_target(x_target), y_target(y_target), dx(x_target - x_center), dy(y_target - y_center), v_x(Engine::get().get_screen_width() * 0.0008), v_y(Engine::get().get_screen_height() * 0.0008), delay_before_charge_ms(delay_before_charge_ms) {
    target_angle = std::atan2(dy, dx) * 180.0 / M_PI + 90.0;
    this->obj_name = obj_name;
    width = Engine::get().get_screen_width() * 0.025;
    height = width / SPRITE_WIDTH_TO_HEIGHT;
    texture = loadTexture("sprites/white_arrow.png");
    angle = get_random(0, 360);
    this->z_index = 5;
    play_sound_effect("audio/white_arrow_getting_ready.ogg");
}

void White_Arrow_Medium_Box_Attack::update() {
    time_elapsed_since_creation += Engine::get().get_delta_time();

    if (time_elapsed_since_creation < delay_before_charge_ms) {
        double angle_difference = std::fmod(std::fmod(target_angle - angle, 360) + 360, 360);
        angle += angle_difference * Engine::get().get_delta_time() * 0.007;
    } else {
        if (!played_flying_sound) {
            play_sound_effect("audio/arrow_fly_from_afar.ogg");
            played_flying_sound = true;
        }
        angle = target_angle;
        double vector_maginitude = std::hypot(dx, dy);
        x_center += dx / vector_maginitude * v_x * Engine::get().get_delta_time();
        y_center += dy / vector_maginitude * v_y * Engine::get().get_delta_time();
    }
}

void White_Arrow_Medium_Box_Attack::render() {
    // Reset transparency in case a Spinning_Arrow made the texture transparent
    SDL_SetTextureAlphaMod(texture, 255);
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};
    SDL_RenderCopyEx(Engine::get().get_renderer(), texture, nullptr, &rect, angle, NULL, SDL_FLIP_NONE);
}
