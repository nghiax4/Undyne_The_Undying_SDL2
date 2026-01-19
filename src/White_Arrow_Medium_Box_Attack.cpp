#include "White_Arrow_Medium_Box_Attack.h"
#include "GameObject.h"

#include "Utils.h"
#include "core/Engine.h"
#include <string>

White_Arrow_Medium_Box_Attack::White_Arrow_Medium_Box_Attack(int x_center, int y_center, int x_target, int y_target, std::string obj_name, Uint32 delay_before_charge_ms) : m_x_target(x_target), m_y_target(y_target), m_dx(x_target - x_center), m_dy(y_target - y_center), m_v_x(Engine::SCREEN_WIDTH * 0.0008), m_v_y(Engine::SCREEN_HEIGHT * 0.0008), m_delay_before_charge_ms(delay_before_charge_ms) {
    m_target_angle = std::atan2(m_dy, m_dx) * 180.0 / M_PI + 90.0;
    m_obj_name = obj_name;
    m_texture = ResourceManager::get().get_texture("sprites/white_arrow.png");

    double width = Engine::SCREEN_WIDTH * 0.025;
    double height = width / SPRITE_WIDTH_TO_HEIGHT;
    double angle = get_random(0, 360);
    add_component<Transform>(x_center, y_center, width, height, angle);

    m_z_index = 5;
    play_sound_effect("audio/white_arrow_getting_ready.ogg");
}

void White_Arrow_Medium_Box_Attack::update() {
    m_time_elapsed_since_creation += Engine::get().get_delta_time();

    Transform *transform = get_component<Transform>();

    if (m_time_elapsed_since_creation < m_delay_before_charge_ms) {
        double angle_difference = std::fmod(std::fmod(m_target_angle - transform->m_angle, 360) + 360, 360);
        transform->m_angle += angle_difference * Engine::get().get_delta_time() * 0.007;
    } else {
        if (!m_played_flying_sound) {
            play_sound_effect("audio/arrow_fly_from_afar.ogg");
            m_played_flying_sound = true;
        }
        transform->m_angle = m_target_angle;
        double vector_maginitude = std::hypot(m_dx, m_dy);
        transform->m_x_center += m_dx / vector_maginitude * m_v_x * Engine::get().get_delta_time();
        transform->m_y_center += m_dy / vector_maginitude * m_v_y * Engine::get().get_delta_time();
    }
}

void White_Arrow_Medium_Box_Attack::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height, transform->m_angle);
}
