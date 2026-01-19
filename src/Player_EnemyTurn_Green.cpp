#include "Player_EnemyTurn_Green.h"
#include "Arrow_For_Green_Attack.h"
#include "GameObject.h"
#include "HealthPointText.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

Player_EnemyTurn_Green::Player_EnemyTurn_Green(int x_center, int y_center) {
    m_texture = ResourceManager::get().get_texture("sprites/soul_green.png");
    m_obj_name = "Player_EnemyTurn_Green";
    m_z_index = 3;

    double width = Engine::SCREEN_WIDTH * 0.03;
    double height = Engine::SCREEN_WIDTH * 0.03;
    add_component<Transform>(x_center, y_center, width, height);
}

void Player_EnemyTurn_Green::update() {
    m_time_elapsed_since_invisibility_frame += Engine::get().get_delta_time();
    m_time_elapsed_since_transparent += Engine::get().get_delta_time();

    if (m_enable_invisbility_frame == true) {
        if (m_time_elapsed_since_transparent >= 140) {
            m_render_texture_transparent = !m_render_texture_transparent;
            m_time_elapsed_since_transparent = 0;
        }

        if (m_time_elapsed_since_invisibility_frame >= 700) {
            m_enable_invisbility_frame = false;
            m_render_texture_transparent = false;
            m_time_elapsed_since_invisibility_frame = 0;
        }
    }

    Transform *transform = get_component<Transform>();

    for (auto &obj : Scene::get().get_objects()) {
        Arrow_For_Green_Attack *arrow = dynamic_cast<Arrow_For_Green_Attack *>(obj.get());
        if (arrow == nullptr)
            continue;

        HealthPointText *healthpoint = static_cast<HealthPointText *>(Scene::get().find_object_by_name("HealthPointText"));

        Transform *arrow_transform = arrow->get_component<Transform>();

        if (distance(transform->m_x_center, transform->m_y_center, arrow_transform->m_x_center, arrow_transform->m_y_center) <= PLAYER_ARROW_COLLISION_DISTANCE) {
            if (!m_enable_invisbility_frame) {
                m_enable_invisbility_frame = true;
                m_render_texture_transparent = true;
                m_time_elapsed_since_invisibility_frame = 0;
                healthpoint->m_hp -= 13;
                play_sound_effect("audio/damage_taken.ogg");
            }
            obj->m_to_be_removed = true;
            break;
        }
    }
}

void Player_EnemyTurn_Green::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height, 0, m_render_texture_transparent ? 128 : 255);
}
