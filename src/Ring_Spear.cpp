#include "Ring_Spear.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "core/Engine.h"
#include <algorithm>
#include <cmath>

Ring_Spear::Ring_Spear(double x, double y, double angle_deg, double radius, std::string name) : m_origin_x(x), m_origin_y(y), m_current_radius(radius), m_current_angle_rad(angle_deg * M_PI / 180.0) {
    m_obj_name = name;
    m_z_index = 5;

    // Calculate speed so it reaches center exactly when TRAVEL_DURATION_MS passes
    m_charge_speed = radius / TRAVEL_DURATION_MS;

    m_width = Engine::SCREEN_WIDTH * 0.025;
    m_height = m_width / White_Arrow_Medium_Box_Attack::SPRITE_WIDTH_TO_HEIGHT;

    m_x_center = m_origin_x + m_current_radius * std::cos(m_current_angle_rad);
    m_y_center = m_origin_y + m_current_radius * std::sin(m_current_angle_rad);

    m_texture = ResourceManager::get().get_texture("sprites/white_arrow.png");
}

void Ring_Spear::update() {
    m_time_alive += Engine::get().get_delta_time();

    // Stage 3: Charge
    if (m_time_alive >= (SPIN_DURATION_MS + LOCK_DURATION_MS)) {
        m_current_radius -= m_charge_speed * Engine::get().get_delta_time();

        if (m_current_radius <= 0) {
            m_to_be_removed = true;
        }
    }

    m_x_center = m_origin_x + m_current_radius * std::cos(m_current_angle_rad);
    m_y_center = m_origin_y + m_current_radius * std::sin(m_current_angle_rad);
}

void Ring_Spear::render() {
    double target_facing_angle = (m_current_angle_rad * 180.0 / M_PI) + 270;
    double final_render_angle = target_facing_angle;

    if (m_time_alive < SPIN_DURATION_MS) {
        // Linear Interpolation for Spin:
        // Start at -360 offset, reach 0 offset exactly when time_alive == SPIN_DURATION_MS
        double progress = m_time_alive / SPIN_DURATION_MS;
        double spin_offset = -360.0 + (progress * 360.0);
        final_render_angle += spin_offset;
    }

    // Handle Opacity Fade-in
    // 0 to 1 over SPIN_DURATION_MS
    double alpha_ratio = std::min(1.0, m_time_alive / SPIN_DURATION_MS);
    Uint8 alpha = static_cast<Uint8>(alpha_ratio * 255);

    Engine::get().draw_texture(m_texture, m_x_center, m_y_center, m_width, m_height, final_render_angle, alpha);
}
