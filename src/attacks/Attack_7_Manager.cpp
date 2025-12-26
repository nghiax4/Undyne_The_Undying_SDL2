#include "Attack_7_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include <Player_EnemyTurn_Green.h>
#include <Shield.h>

Attack_7_Manager::Attack_7_Manager() : Attack_Manager_Base_Class(7) {
    MILLISECONDS_LENGTH = 6500;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0005, 1067, 1, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0005, 1400, 2, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0005, 1667, 3, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0005, 2000, 4, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0005, 2233, 5, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0005, 2600, 6, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0005, 2833, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0005, 3167, 8, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0005, 3800, 9, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0005, 4067, 10, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0005, 4400, 11, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0005, 4667, 12, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0005, 5000, 13, ArrowType::Yellow));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0005, 5267, 14, ArrowType::Yellow));
}

void Attack_7_Manager::render() {}
void Attack_7_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_7_Manager> register_attack_7(7);
