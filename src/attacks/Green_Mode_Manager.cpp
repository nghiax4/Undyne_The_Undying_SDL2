#include "Green_Mode_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "core/Engine.h"
#include "core/Scene.h"

Green_Mode_Manager::Green_Mode_Manager(int attack_id, Uint32 duration_ms, std::vector<GreenModeArrowData> arrows_data) : Attack_Manager_Base_Class(attack_id, duration_ms) {
    static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_x_center = Engine::SCREEN_WIDTH / 2;
    static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_y_center = Engine::SCREEN_HEIGHT / 2;
    static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_width = Engine::SCREEN_WIDTH * 0.13;
    static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_height = Engine::SCREEN_WIDTH * 0.13;

    Scene::get().spawn(std::make_unique<Player_EnemyTurn_Green>(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2));
    Scene::get().spawn(std::make_unique<Shield>());

    for (const auto &data : arrows_data) {
        arrow_counter_for_unique_names++;
        Arrow_For_Green_Attack *arrow = create_arrow_for_green_attack_with_impact_time(data.m_direction, data.m_speed, data.m_time_to_impact_ms, arrow_counter_for_unique_names, data.m_type);
        Scene::get().spawn(std::unique_ptr<Arrow_For_Green_Attack>(arrow));
    }
}

void Green_Mode_Manager::ready_to_be_removed() {
    _teardown_green_mode();
}
