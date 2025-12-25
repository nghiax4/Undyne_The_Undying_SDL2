#include "Attack_0_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Attack_0_Manager::Attack_0_Manager() : Attack_Manager_Base_Class(0) {
    MILLISECONDS_LENGTH = 10000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 3500, 1));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 4250, 2));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 5000, 3));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.001, 5000, 4));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.001, 5400, 5));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.001, 5800, 6));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 6200, 7));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.001, 6600, 8));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.001, 7000, 9));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.001, 7400, 10));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.001, 7800, 11));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.001, 8200, 12));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 8600, 13));
}

void Attack_0_Manager::render() {}

void Attack_0_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_0_Manager> register_attack_0(0);
