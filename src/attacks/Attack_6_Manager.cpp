#include "Attack_6_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"

Attack_6_Manager::Attack_6_Manager() : Attack_Manager_Base_Class(6) {
    MILLISECONDS_LENGTH = 5500;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT / 2;
    global_battlebox->width = SCREEN_WIDTH * 0.13;
    global_battlebox->height = SCREEN_WIDTH * 0.13;

    Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Shield *shield = new Shield();
    objs.push_back(player);
    objs.push_back(shield);

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.2, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 1));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.35, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 2));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.5, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 3));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 0.65, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 4));

    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 0.9, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 5));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.15, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 6));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.3, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 7));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.45, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 8));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 1.6, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 9));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH * 2.75, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 10));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 2.1, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 11));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 2.25, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 12));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 2.4, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 13));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 2.55, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 14));

    // objs.push_back(create_arrow_for_green_attack(-SCREEN_WIDTH * 2.72, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, 15));

    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 3.05, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 16));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 3.2, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 17));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 3.35, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 18));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH / 2, -SCREEN_HEIGHT * 3.5, 0, SCREEN_HEIGHT * 0.001, Direction::DOWN, 19));
    // objs.push_back(create_arrow_for_green_attack(SCREEN_WIDTH * 4.55, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, 20));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 700, 1, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 850, 2, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 1000, 3, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 1150, 4, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.001, 1400, 5, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 1650, 6, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 1800, 7, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 1950, 8, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 2100, 9, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.001, 2250, 10, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 2600, 11, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 2750, 12, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 2900, 13, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 3050, 14, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::RIGHT, SCREEN_WIDTH * 0.001, 3220, 15, ArrowType::Blue));

    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 3550, 16, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 3700, 17, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 3850, 18, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::DOWN, SCREEN_HEIGHT * 0.001, 4000, 19, ArrowType::Blue));
    objs.push_back(create_arrow_for_green_attack_with_impact_time(Direction::LEFT, SCREEN_WIDTH * 0.001, 4050, 20, ArrowType::Blue));
}

void Attack_6_Manager::render() {}

void Attack_6_Manager::ready_to_be_removed() { _teardown_green_mode(); }

static AutoRegisterAttack<Attack_6_Manager> register_attack_6(6);
