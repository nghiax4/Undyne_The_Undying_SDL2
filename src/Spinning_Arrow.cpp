#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "core/Engine.h"
#include <algorithm>
#include <cmath>

Spinning_Arrow::Spinning_Arrow(double origin_x, double origin_y, double start_angle_deg, double start_radius, std::string obj_name) : radial_speed_pixels_per_ms(Engine::get().get_screen_width() * 0.00017), origin_x(origin_x), origin_y(origin_y), current_radius(start_radius), initial_radius(start_radius), radial_speed(start_radius / TRAVEL_DURATION_MS) {
    this->obj_name = obj_name;
    z_index = 5; // Above the box

    // Convert to radians for math
    current_angle_rad = start_angle_deg * M_PI / 180.0;

    width = Engine::get().get_screen_width() * 0.025;
    height = width / White_Arrow_Medium_Box_Attack::SPRITE_WIDTH_TO_HEIGHT;

    // Reusing the white arrow texture
    texture = ResourceManager::get().get_texture("sprites/white_arrow.png");

    // Set blend mode to support transparency
    SDL_SetTextureBlendMode(texture.get(), SDL_BLENDMODE_BLEND);
    // Set zero opacity
    SDL_SetTextureAlphaMod(texture.get(), 0);
}

void Spinning_Arrow::update() {
    time_elapsed_since_spawn += Engine::get().get_delta_time();

    // 1. Linearly decrease radius (close in on center)
    current_radius -= radial_speed_pixels_per_ms * Engine::get().get_delta_time();

    // 2. Decaying Angular Velocity: As radius gets smaller, rotation slows down
    // The ratio (current / initial) goes from 1.0 to 0.0
    double speed_decay_factor = std::max(0.0, (current_radius / initial_radius) * (current_radius / initial_radius) * (current_radius / initial_radius));
    double current_angular_speed = INITIAL_ANGULAR_SPEED_RAD_PER_MS * speed_decay_factor;

    current_angle_rad += current_angular_speed * Engine::get().get_delta_time();

    // 3. Convert Polar (r, theta) -> Cartesian (x, y)
    x_center = origin_x + current_radius * std::cos(current_angle_rad);
    y_center = origin_y + current_radius * std::sin(current_angle_rad);

    // 4. Remove if it hits the center (radius < 0)
    if (current_radius <= 0) {
        to_be_removed = true;
    }
}

void Spinning_Arrow::render() {
    double alpha_ratio = std::min(1.0, time_elapsed_since_spawn / FADE_DURATION_MS);
    Uint8 alpha = static_cast<Uint8>(alpha_ratio * 255);
    SDL_SetTextureAlphaMod(texture.get(), alpha);

    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};

    // Rotate texture to point inward to the center (+90 degree adjustment for sprite orientation)
    double angle_deg = current_angle_rad * 180.0 / M_PI;

    // We add 90 because the arrow sprite points Up, but 0 rad is Right.
    // We add 180 to make it point INWARD.
    double render_angle = angle_deg + 90 + 180;

    SDL_RenderCopyEx(Engine::get().get_renderer(), texture.get(), nullptr, &rect, render_angle, NULL, SDL_FLIP_NONE);
}
