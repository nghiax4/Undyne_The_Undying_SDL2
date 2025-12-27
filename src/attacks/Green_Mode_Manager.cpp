#include "Green_Mode_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Green_Mode_Manager::Green_Mode_Manager(int attack_id, int duration_ms) : Attack_Manager_Base_Class(attack_id) {
    MILLISECONDS_LENGTH = duration_ms;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();

    objs.push_back(player);
    objs.push_back(shield);
}

void Green_Mode_Manager::ready_to_be_removed() { _teardown_green_mode(); }

void Green_Mode_Manager::schedule_arrow(Direction direction, int time_to_impact_ms, double speed_val, ArrowType arrow_type) {
    arrow_counter_for_unique_names++;
    objs.push_back(create_arrow_for_green_attack_with_impact_time(direction, speed_val, time_to_impact_ms, arrow_counter_for_unique_names, arrow_type));
}
