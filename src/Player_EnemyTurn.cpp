#include "Player_EnemyTurn.h"
#include "BattleBox.h"
#include "HealthPointText.h"
#include "Ring_Spear.h"
#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "White_Arrow_Small_Box_Attack.h"
#include "core/Engine.h"
#include "core/Input.h"
#include "core/Scene.h"

template <typename AttackType>
void apply_collision_logic_for_type(Player_EnemyTurn *player) {
    const double PLAYER_ARROW_COLLISION_DISTANCE = 20.0;
    const int DAMAGE_AMOUNT = 13;

    Transform *player_transform = player->get_component<Transform>();

    HealthPointText *hp_text_obj = static_cast<HealthPointText *>(Scene::get().find_object_by_name("HealthPointText"));

    for (auto &game_obj : Scene::get().get_objects()) {
        AttackType *specific_attack = dynamic_cast<AttackType *>(game_obj.get());

        if (specific_attack == nullptr)
            continue;

        double distance_to_attack = distance(player_transform->m_x_center, player_transform->m_y_center, specific_attack->m_x_center, specific_attack->m_y_center);
        bool is_colliding = distance_to_attack <= PLAYER_ARROW_COLLISION_DISTANCE;

        if (is_colliding) {
            if (!player->m_enable_invisbility_frame) {
                player->m_enable_invisbility_frame = true;
                player->m_render_texture_transparent = true;
                player->m_time_elapsed_since_invisibility_frame = 0;

                hp_text_obj->m_hp -= DAMAGE_AMOUNT;
                play_sound_effect("audio/damage_taken.ogg");
            }
            game_obj->m_to_be_removed = true;
        }
    }
}

Player_EnemyTurn::Player_EnemyTurn(double x_center, double y_center) : m_v_x(Engine::SCREEN_WIDTH * 0.0003), m_v_y(Engine::SCREEN_WIDTH * 0.0003) {
    m_texture = ResourceManager::get().get_texture("sprites/soul.png");
    m_obj_name = "Player_EnemyTurn";
    m_z_index = 3;

    double width = Engine::SCREEN_WIDTH * 0.03;
    double height = Engine::SCREEN_WIDTH * 0.03;
    add_component<Transform>(x_center, y_center, width, height);
}

void Player_EnemyTurn::update() {
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

    int x_multiplier = 0;
    if (Input::get().is_key_down(SDL_SCANCODE_LEFT)) {
        x_multiplier = -1;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_RIGHT)) {
        x_multiplier = 1;
    }

    int y_multiplier = 0;
    if (Input::get().is_key_down(SDL_SCANCODE_UP)) {
        y_multiplier = -1;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_DOWN)) {
        y_multiplier = 1;
    }

    Transform *transform = get_component<Transform>();

    transform->m_x_center += x_multiplier * m_v_x * Engine::get().get_delta_time();
    transform->m_y_center += y_multiplier * m_v_y * Engine::get().get_delta_time();

    Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

    transform->m_x_center = std::max(transform->m_x_center, (double)(battle_box_transform->m_x_center - battle_box_transform->m_width / 2 + transform->m_width / 2));
    transform->m_x_center = std::min(transform->m_x_center, (double)(battle_box_transform->m_x_center + battle_box_transform->m_width / 2 - transform->m_width / 2));

    transform->m_y_center = std::max(transform->m_y_center, (double)(battle_box_transform->m_y_center - battle_box_transform->m_height / 2 + transform->m_height / 2));
    transform->m_y_center = std::min(transform->m_y_center, (double)(battle_box_transform->m_y_center + battle_box_transform->m_height / 2 - transform->m_height / 2));

    apply_collision_logic_for_type<White_Arrow_Small_Box_Attack>(this);
    apply_collision_logic_for_type<White_Arrow_Medium_Box_Attack>(this);
    apply_collision_logic_for_type<Spinning_Arrow>(this);
    apply_collision_logic_for_type<Ring_Spear>(this);
}

void Player_EnemyTurn::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height, 0, m_render_texture_transparent ? 128 : 255);
}
