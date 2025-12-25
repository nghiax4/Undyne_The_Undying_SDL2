#include "Attack_1_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include <AttackRegistry.h>

Attack_1_Manager::Attack_1_Manager() : Attack_Manager_Base_Class(1) {
    MILLISECONDS_LENGTH = 5000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 1));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 1.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 2));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 3));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 1.75, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 4));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 2.05, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 5));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 2.35, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 6));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 2.75, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 7));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 8));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3.15, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 9));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 3.45, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 10));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 3.7, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 11));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 4, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 12));
    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 4.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 13));

    objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 4.6, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 14));
}

void Attack_1_Manager::render() {}
void Attack_1_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_1_Manager> register_attack_1(1);
