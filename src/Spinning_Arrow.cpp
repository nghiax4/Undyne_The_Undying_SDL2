#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "core/Engine.h"
#include <algorithm>
#include <cmath>

Spinning_Arrow::Spinning_Arrow(double origin_x, double origin_y, double start_angle_deg, double start_radius, std::string obj_name) : m_radial_speed_pixels_per_ms(Engine::get().get_screen_width() * 0.00017), m_origin_x(origin_x), m_origin_y(origin_y), m_current_radius(start_radius), m_initial_radius(start_radius), m_radial_speed(start_radius / TRAVEL_DURATION_MS) {
    m_obj_name = obj_name;
    m_z_index = 5; // Above the box

    // Convert to radians for math
    m_current_angle_rad = start_angle_deg * M_PI / 180.0;

    m_width = Engine::get().get_screen_width() * 0.025;
    m_height = m_width / White_Arrow_Medium_Box_Attack::SPRITE_WIDTH_TO_HEIGHT;

    // Reusing the white arrow texture
    m_texture = ResourceManager::get().get_texture("sprites/white_arrow.png");
}

void Spinning_Arrow::update() {
    m_time_elapsed_since_spawn += Engine::get().get_delta_time();

    // 1. Linearly decrease radius (close in on center)
    m_current_radius -= m_radial_speed_pixels_per_ms * Engine::get().get_delta_time();

    // 2. Decaying Angular Velocity: As radius gets smaller, rotation slows down
    // The ratio (current / initial) goes from 1.0 to 0.0
    double speed_decay_factor = std::max(0.0, (m_current_radius / m_initial_radius) * (m_current_radius / m_initial_radius) * (m_current_radius / m_initial_radius));
    double current_angular_speed = INITIAL_ANGULAR_SPEED_RAD_PER_MS * speed_decay_factor;

    m_current_angle_rad += current_angular_speed * Engine::get().get_delta_time();

    // 3. Convert Polar (r, theta) -> Cartesian (x, y)
    m_x_center = m_origin_x + m_current_radius * std::cos(m_current_angle_rad);
    m_y_center = m_origin_y + m_current_radius * std::sin(m_current_angle_rad);

    // 4. Remove if it hits the center (radius < 0)
    if (m_current_radius <= 0) {
        m_to_be_removed = true;
    }
}

void Spinning_Arrow::render() {
    double alpha_ratio = std::min(1.0, m_time_elapsed_since_spawn / FADE_DURATION_MS);
    Uint8 alpha = static_cast<Uint8>(alpha_ratio * 255);

    // Rotate texture to point inward to the center (+90 degree adjustment for sprite orientation)
    double angle_deg = m_current_angle_rad * 180.0 / M_PI;

    // We add 90 because the arrow sprite points Up, but 0 rad is Right.
    // We add 180 to make it point INWARD.
    double render_angle = angle_deg + 90 + 180;

    Engine::get().draw_texture(m_texture, m_x_center, m_y_center, m_width, m_height, render_angle, alpha);
}
