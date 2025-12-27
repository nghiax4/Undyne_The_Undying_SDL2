#include "Attack_11_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include <Player_EnemyTurn_Green.h>
#include <Shield.h>

Attack_11_Manager::Attack_11_Manager() : Attack_Manager_Base_Class(11) {
    MILLISECONDS_LENGTH = 7000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    const double SPEED_X = SCREEN_WIDTH * 0.00075;
    const double SPEED_Y = SCREEN_HEIGHT * 0.00075;

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 900, 1, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 1234, 2, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 1567, 3, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 1867, 4, ArrowType::Yellow));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 2200, 5, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 2467, 6, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 2800, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 3134, 8, ArrowType::Yellow));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 3500, 9, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 3767, 10, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 4134, 11, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 4500, 12, ArrowType::Yellow));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 4800, 13, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 5067, 14, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 5367, 15, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 5767, 16, ArrowType::Yellow));
}

void Attack_11_Manager::render() {}
void Attack_11_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_11_Manager> register_attack_11(11);
