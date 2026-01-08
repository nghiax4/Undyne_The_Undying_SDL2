#include "Fundamental_Managers.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Ring_Spear.h"
#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "White_Arrow_Small_Box_Attack.h"
#include "core/Engine.h"
#include "core/Scene.h"

Three_Lane_Rising_Arrow_Attack::Three_Lane_Rising_Arrow_Attack(int attack_id, Uint32 duration_ms, Uint32 time_between_arrows_ms, Uint32 arrow_prep_time_ms) : Red_Mode_Manager(attack_id, duration_ms, 0.72, 0.12, 0.19), m_time_between_arrows_ms(time_between_arrows_ms), m_arrow_prep_time_ms(arrow_prep_time_ms) {}

void Three_Lane_Rising_Arrow_Attack::update() {
    Red_Mode_Manager::update();
    m_time_elapsed_since_last_arrow += Engine::get().get_delta_time();

    if (m_time_elapsed_since_last_arrow > m_time_between_arrows_ms) {
        std::vector<double> x_multipliers = {0.2, 0.5, 0.8};
        Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

        double x_pos = battle_box_transform->m_x_center - battle_box_transform->m_width / 2 + battle_box_transform->m_width * x_multipliers.at(static_cast<size_t>(get_random(0, 2)));
        double y_pos = battle_box_transform->m_y_center + battle_box_transform->m_height;

        std::string name = m_attack_prefix + "_Falling_Arrow_" + std::to_string(m_arrows_created_counter++);
        Scene::get().spawn(std::make_unique<White_Arrow_Small_Box_Attack>(x_pos, y_pos, name, m_arrow_prep_time_ms));

        m_time_elapsed_since_last_arrow = 0;
    }
}

Random_Spawn_Player_Aimed_Arrow_Attack::Random_Spawn_Player_Aimed_Arrow_Attack(int attack_id, Uint32 duration_ms, Uint32 time_between_arrows_ms, Uint32 arrow_rotation_time_ms) : Red_Mode_Manager(attack_id, duration_ms, 0.63, 0.28, (Engine::SCREEN_WIDTH * 0.28) / Engine::SCREEN_HEIGHT), m_time_between_arrows_ms(time_between_arrows_ms), m_arrow_rotation_time_ms(arrow_rotation_time_ms) {}

void Random_Spawn_Player_Aimed_Arrow_Attack::update() {
    Red_Mode_Manager::update();
    m_time_elapsed_since_last_arrow += Engine::get().get_delta_time();

    if (m_time_elapsed_since_last_arrow > m_time_between_arrows_ms) {
        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(Scene::get().find_object_by_name("Player_EnemyTurn"));
        Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

        double spawn_radius = get_random(Engine::SCREEN_WIDTH * 0.2, Engine::SCREEN_WIDTH * 0.3);
        double angle_deg = get_random(0, 360);
        double spawn_x = battle_box_transform->m_x_center + spawn_radius * cos(angle_deg * M_PI / 180.0);
        double spawn_y = battle_box_transform->m_y_center + spawn_radius * sin(angle_deg * M_PI / 180.0);

        std::string name = m_attack_prefix + "_Targeted_Arrow_" + std::to_string(m_arrows_created_counter++);
        Scene::get().spawn(std::make_unique<White_Arrow_Medium_Box_Attack>(spawn_x, spawn_y, player->m_x_center, player->m_y_center, name, m_arrow_rotation_time_ms));

        m_time_elapsed_since_last_arrow = 0;
    }
}

Inward_Spiraling_Arrow_Ring_Attack::Inward_Spiraling_Arrow_Ring_Attack(int attack_id, Uint32 duration_ms, Uint32 interval_ms) : Circle_Spawn_Manager(attack_id, duration_ms, interval_ms, Engine::SCREEN_WIDTH * 0.35) {}

void Inward_Spiraling_Arrow_Ring_Attack::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    const int ARROWS_PER_RING = 7;

    for (int i = 0; i < ARROWS_PER_RING; i++) {
        double angle = angle_offset + (360.0 / ARROWS_PER_RING) * i;
        std::string name = m_attack_prefix + "_Spinning_" + std::to_string(m_items_created_counter++);
        Scene::get().spawn(std::make_unique<Spinning_Arrow>(center_x, center_y, angle, m_spawn_radius, name));
    }
}

Contracting_Rotating_Spear_Ring_Attack::Contracting_Rotating_Spear_Ring_Attack(int attack_id, Uint32 duration_ms, double radius, IntervalCalculator get_interval_func) : Circle_Spawn_Manager(attack_id, duration_ms, get_interval_func(0), radius), m_get_interval_func(get_interval_func) {}

void Contracting_Rotating_Spear_Ring_Attack::update() {
    m_current_interval = m_get_interval_func(m_time_elapsed_since_creation);
    Circle_Spawn_Manager::update();
}

void Contracting_Rotating_Spear_Ring_Attack::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    const int SPEARS_PER_RING = 6;

    for (int i = 0; i < SPEARS_PER_RING; i++) {
        double angle = angle_offset + (360.0 / SPEARS_PER_RING) * i;
        std::string name = m_attack_prefix + "_Spear_" + std::to_string(m_items_created_counter++);
        Scene::get().spawn(std::make_unique<Ring_Spear>(center_x, center_y, angle, m_spawn_radius, name));
    }
}
