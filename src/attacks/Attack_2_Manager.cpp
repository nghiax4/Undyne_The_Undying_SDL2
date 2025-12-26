#include "Attack_2_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include <AttackRegistry.h>

Attack_2_Manager::Attack_2_Manager() : Attack_Manager_Base_Class(2) {
    MILLISECONDS_LENGTH = 11000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 0.2, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, 1));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.25, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 2));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.3, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, 3));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.4, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 4));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.5, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 5));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.6, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, 6));

    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 0.65, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, 7));
    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 0.68, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, 8));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 0.75, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, 9));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH + SCREEN_WIDTH * 0.8, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, 10));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.9, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 11));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 12));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT + SCREEN_HEIGHT * 1.1, 0, -SCREEN_HEIGHT * 0.0002, Direction::UP, 13));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.2, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 14));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.23, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, 15));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH + SCREEN_WIDTH * 1.26, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, 16));
    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 1.29, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, 17));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH + SCREEN_WIDTH * 1.32, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.0002, 0, Direction::LEFT, 18));
    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 1.35, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.0002, 0, Direction::RIGHT, 19));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0002, 3500, 1, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 3750, 2, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0002, 4000, 3, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 4500, 4, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 5000, 5, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0002, 5500, 6, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0002, 5750, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0002, 5900, 8, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0002, 6250, 9, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0002, 6500, 10, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 7000, 11, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 7500, 12, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::UP, SCREEN_HEIGHT * 0.0002, 8000, 13, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 8500, 14, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.0002, 8650, 15, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0002, 8800, 16, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0002, 8950, 17, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.0002, 9100, 18, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.0002, 9250, 19, ArrowType::Blue));
}

void Attack_2_Manager::render() {}

void Attack_2_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_2_Manager> register_attack_2(2);
