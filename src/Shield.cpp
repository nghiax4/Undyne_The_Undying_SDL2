#include "Shield.h"
#include "GameObject.h"

#include "Player_EnemyTurn_Green.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Input.h"
#include "core/Scene.h"

Shield::Shield() : m_distance_from_soul(Engine::SCREEN_HEIGHT * 0.07) {
    m_texture = ResourceManager::get().get_texture("sprites/shield.png");
    m_obj_name = "Shield";
    m_z_index = 3;

    double width = Engine::SCREEN_WIDTH * 0.1;
    double height = Engine::SCREEN_HEIGHT * 0.007;
    add_component<Transform>(0, 0, width, height);
}

void Shield::update() {
    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(Scene::get().find_object_by_name("Player_EnemyTurn_Green"));

    if (Input::get().is_key_down(SDL_SCANCODE_UP)) {
        m_target_angle = 270;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_RIGHT)) {
        m_target_angle = 0;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_DOWN)) {
        m_target_angle = 90;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_LEFT)) {
        m_target_angle = 180;
    }

    auto mod360 = [](double x) {
        return std::fmod(std::fmod(x, 360.0) + 360.0, 360.0);
    };

    double increment_distance = mod360(m_target_angle - m_cur_angle);
    double decrement_distance = mod360(m_cur_angle - m_target_angle);

    if (increment_distance < decrement_distance) {
        m_cur_angle += increment_distance * Engine::get().get_delta_time() * 0.03;
    } else {
        m_cur_angle -= decrement_distance * Engine::get().get_delta_time() * 0.03;
    }

    Transform *player_transform = player->get_component<Transform>();
    Transform *transform = get_component<Transform>();

    transform->m_x_center = player_transform->m_x_center + m_distance_from_soul * cos(m_cur_angle * M_PI / 180);
    transform->m_y_center = player_transform->m_y_center + m_distance_from_soul * sin(m_cur_angle * M_PI / 180);
}

void Shield::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height, m_cur_angle + 90);
}
