#include "Ring_Spear.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include <algorithm>
#include <cmath>

Ring_Spear::Ring_Spear(double x, double y, double angle_deg, double radius, std::string name) : origin_x(x), origin_y(y), current_radius(radius), current_angle_rad(angle_deg * M_PI / 180.0) {

    obj_name = name;
    z_index = 5;

    // Calculate speed so it reaches center exactly when TRAVEL_DURATION_MS passes
    charge_speed = radius / TRAVEL_DURATION_MS;

    width = SCREEN_WIDTH * 0.025;
    height = width / White_Arrow_Medium_Box_Attack::SPRITE_WIDTH_TO_HEIGHT;

    x_center = origin_x + current_radius * std::cos(current_angle_rad);
    y_center = origin_y + current_radius * std::sin(current_angle_rad);

    texture = loadTexture(renderer, "sprites/white_arrow.png");
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, 0); // Start invisible
}

void Ring_Spear::update() {
    time_alive += deltaTime;

    // Stage 3: Charge
    if (time_alive >= (SPIN_DURATION_MS + LOCK_DURATION_MS)) {
        current_radius -= charge_speed * deltaTime;

        if (current_radius <= 0) {
            to_be_removed = true;
        }
    }

    x_center = origin_x + current_radius * std::cos(current_angle_rad);
    y_center = origin_y + current_radius * std::sin(current_angle_rad);
}

void Ring_Spear::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};

    double target_facing_angle = (current_angle_rad * 180.0 / M_PI) + 270;
    double final_render_angle = target_facing_angle;

    // Handle Opacity Fade-in
    // 0 to 1 over SPIN_DURATION_MS
    double alpha_ratio = std::min(1.0, time_alive / SPIN_DURATION_MS);
    SDL_SetTextureAlphaMod(texture, (Uint8)(alpha_ratio * 255));

    if (time_alive < SPIN_DURATION_MS) {
        // Linear Interpolation for Spin:
        // Start at -360 offset, reach 0 offset exactly when time_alive == SPIN_DURATION_MS
        double progress = time_alive / SPIN_DURATION_MS;
        double spin_offset = -360.0 + (progress * 360.0);

        final_render_angle += spin_offset;
    }

    SDL_RenderCopyEx(renderer, texture, nullptr, &rect, final_render_angle, NULL, SDL_FLIP_NONE);
}
