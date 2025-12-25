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

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.7, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 1));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.85, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 2));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 1, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 3));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 5, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 4));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 5.4, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, 5));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 5.8, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 6));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 6.2, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 7));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 6.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 8));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 7, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, 9));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 7.4, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 10));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 7.8, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, 11));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 8.2, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 12));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 8.6, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 13));
}

void Attack_0_Manager::render() {}

void Attack_0_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_0_Manager> register_attack_0(0);
