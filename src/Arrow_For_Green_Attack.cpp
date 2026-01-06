#include "Arrow_For_Green_Attack.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include <algorithm>

Arrow_For_Green_Attack::Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name, ArrowType arrow_type) : m_x_center(x_center), m_y_center(y_center), m_v_x(v_x), m_v_y(v_y), m_direction(direction), m_arrow_type(arrow_type) {
    m_height = (Engine::SCREEN_HEIGHT * 0.06);
    m_width = m_height * SPRITE_WIDTH_TO_HEIGHT_RATIO;

    m_obj_name = obj_name;
    m_z_index = 4;

    std::string sprite_path = arrow_type == ArrowType::Yellow ? "sprites/down_arrow_yellow.png" : "sprites/down_arrow.png";
    m_texture = ResourceManager::get().get_texture(sprite_path);
}

void Arrow_For_Green_Attack::update() {
    if (m_state == State::APPROACHING_BEFORE_ROTATE || m_state == State::APPROACHING_AFTER_ROTATE) {
        m_x_center += m_v_x * Engine::get().get_delta_time();
        m_y_center += m_v_y * Engine::get().get_delta_time();
    }

    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(Scene::get().find_object_by_name("Player_EnemyTurn_Green"));

    if (m_arrow_type == ArrowType::Yellow && m_state == State::APPROACHING_BEFORE_ROTATE) {
        double dist = distance(m_x_center, m_y_center, player->m_x_center, player->m_y_center);

        if (dist <= DISTANCE_FROM_SOUL_TO_FLIP) {
            m_state = State::ROTATING;
            m_orbit_radius = dist;

            double dx = m_x_center - player->m_x_center;
            double dy = m_y_center - player->m_y_center;
            // angle relative to soul
            m_orbit_angle_deg = std::atan2(dy, dx) * 180.0 / M_PI;

            m_target_orbit_angle_deg = m_orbit_angle_deg + 180.0;
        }
    }

    if (m_state == State::ROTATING) {
        double rotation_speed = ROTATION_SPEED_DEGREE_PER_MS * Engine::get().get_delta_time();

        m_orbit_angle_deg = std::min(m_orbit_angle_deg + rotation_speed, m_target_orbit_angle_deg);

        double orbit_angle_rad = m_orbit_angle_deg * M_PI / 180.0;
        m_x_center = player->m_x_center + m_orbit_radius * std::cos(orbit_angle_rad);
        m_y_center = player->m_y_center + m_orbit_radius * std::sin(orbit_angle_rad);

        // While equality for double is discouraged, equality is guaranteed to happen here due to min() above
        if (m_orbit_angle_deg == m_target_orbit_angle_deg) {
            m_state = State::APPROACHING_AFTER_ROTATE;
            double current_speed = std::sqrt(m_v_x * m_v_x + m_v_y * m_v_y);

            if (m_direction == Direction::LEFT) {
                m_v_x = -current_speed;
                m_v_y = 0;
            } else if (m_direction == Direction::RIGHT) {
                m_v_x = current_speed;
                m_v_y = 0;
            } else if (m_direction == Direction::UP) {
                m_v_x = 0;
                m_v_y = -current_speed;
            } else if (m_direction == Direction::DOWN) {
                m_v_x = 0;
                m_v_y = current_speed;
            }
        }
    }

    if (Scene::get().object_exists("Shield")) {
        Shield *shield = static_cast<Shield *>(Scene::get().find_object_by_name("Shield"));

        if (distance(m_x_center, m_y_center, shield->m_x_center, shield->m_y_center) <= 20) {
            play_sound_effect("audio/shield_reflect.ogg");
            m_to_be_removed = true;
        }
    }
}

void Arrow_For_Green_Attack::render() {
    int angle;
    if (m_direction == Direction::DOWN) {
        angle = 0;
    }
    if (m_direction == Direction::RIGHT) {
        angle = 270;
    }
    if (m_direction == Direction::UP) {
        angle = 180;
    }
    if (m_direction == Direction::LEFT) {
        angle = 90;
    }

    Engine::get().draw_texture(m_texture, m_x_center, m_y_center, m_width, m_height, angle);
}
