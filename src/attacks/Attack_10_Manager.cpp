#include "Attack_10_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include <Player_EnemyTurn_Green.h>
#include <Shield.h>

Attack_10_Manager::Attack_10_Manager() : Attack_Manager_Base_Class(7) {
    MILLISECONDS_LENGTH = 7000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    const float SPEED_X = SCREEN_WIDTH * 0.0012;
    const float SPEED_Y = SCREEN_HEIGHT * 0.0012;

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 1700, 1, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 2033, 2, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 2366, 3, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 2766, 4, ArrowType::Yellow));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 2966, 5, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 3300, 6, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 3633, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 3966, 8, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SPEED_Y, 4766, 9, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SPEED_X, 5100, 10, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SPEED_X, 5433, 11, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SPEED_Y, 5766, 12, ArrowType::Yellow));
}

void Attack_10_Manager::render() {}
void Attack_10_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_10_Manager> register_attack_10(10);
