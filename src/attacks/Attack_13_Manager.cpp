#include "Attack_13_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include <Player_EnemyTurn_Green.h>
#include <Shield.h>

Attack_13_Manager::Attack_13_Manager() : Attack_Manager_Base_Class(13) {
    MILLISECONDS_LENGTH = 12500;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    const double SPEED_X = SCREEN_WIDTH * 0.00012;
    const double SPEED_Y = SCREEN_HEIGHT * 0.00012;

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 5733, 1, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 5967, 2, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 6300, 3, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 6567, 4, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 6800, 5, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 7067, 6, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 7467, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 7733, 8, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 7967, 9, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 8133, 10, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 8467, 11, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 8667, 12, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 8900, 13, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 9133, 14, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 9467, 15, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 9700, 16, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 10000, 17, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 10367, 18, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 10667, 19, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 10900, 20, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 11033, 21, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 11267, 22, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 11600, 23, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 11900, 24, ArrowType::Blue));
}

void Attack_13_Manager::render() {}
void Attack_13_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_13_Manager> register_attack_13(13);
