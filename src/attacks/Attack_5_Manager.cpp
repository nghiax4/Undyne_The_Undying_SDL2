#include "Attack_5_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Attack_5_Manager::Attack_5_Manager() : Attack_Manager_Base_Class(5) {
    MILLISECONDS_LENGTH = 6000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 0.2, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0007, 0, Direction::RIGHT, 1));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.2, 0, SCREEN_HEIGHT * 0.0004, Direction::DOWN, 2));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH * 2, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0007, 0, Direction::LEFT, 3));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 1.5, 0, -SCREEN_HEIGHT * 0.0004, Direction::UP, 4));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH * 2.5, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0007, 0, Direction::LEFT, 5));
    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 1, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0004, 0, Direction::RIGHT, 6));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.25, 0, SCREEN_HEIGHT * 0.0004, Direction::DOWN, 7));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 2.5, 0, -SCREEN_HEIGHT * 0.0004, Direction::UP, 8));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0007, 1000, 1));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0004, 1750, 2));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0007, 2143, 3));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0004, 2500, 4));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0007, 2857, 5));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0004, 3750, 6));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0004, 4375, 7));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0004, 5000, 8));
}

void Attack_5_Manager::render() {}

void Attack_5_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_5_Manager> register_attack_5(5);
