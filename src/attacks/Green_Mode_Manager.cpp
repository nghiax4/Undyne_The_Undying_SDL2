#include "Green_Mode_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "core/Engine.h"

Green_Mode_Manager::Green_Mode_Manager(int attack_id, int duration_ms, std::vector<GreenModeArrowData> arrows_data) : Attack_Manager_Base_Class(attack_id) {
    MILLISECONDS_LENGTH = duration_ms;

    global_battlebox->x_center = Engine::get().get_screen_width() / 2;
    global_battlebox->y_center = Engine::get().get_screen_height() / 2;
    global_battlebox->width = Engine::get().get_screen_width() * 0.13;
    global_battlebox->height = Engine::get().get_screen_width() * 0.13;

    objs.push_back(std::make_unique<Player_EnemyTurn_Green>(Engine::get().get_screen_width() / 2, Engine::get().get_screen_height() / 2));
    objs.push_back(std::make_unique<Shield>());

    for (const auto &data : arrows_data) {
        arrow_counter_for_unique_names++;
        Arrow_For_Green_Attack *arrow = create_arrow_for_green_attack_with_impact_time(data.direction, data.speed, data.time_to_impact_ms, arrow_counter_for_unique_names, data.type);
        objs.push_back(std::unique_ptr<Arrow_For_Green_Attack>(arrow));
    }
}

void Green_Mode_Manager::ready_to_be_removed() {
    _teardown_green_mode();
}
