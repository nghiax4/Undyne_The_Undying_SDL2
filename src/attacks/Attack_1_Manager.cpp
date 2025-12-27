#include "Attack_1_Manager.h"
#include "AttackRegistry.h"

Attack_1_Manager::Attack_1_Manager() : Green_Mode_Manager(1, 5000) {
    schedule_arrow(Direction::RIGHT, 1000, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::LEFT, 1300, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::RIGHT, 1600, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::RIGHT, 1750, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::LEFT, 2050, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::LEFT, 2350, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::RIGHT, 2750, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::LEFT, 3000, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::LEFT, 3150, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::RIGHT, 3450, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::LEFT, 3700, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::RIGHT, 4000, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::LEFT, 4300, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::RIGHT, 4600, DEFAULT_ARROW_SPEED_X);
}

void Attack_1_Manager::render() {}

static AutoRegisterAttack<Attack_1_Manager> register_attack_1(1);
