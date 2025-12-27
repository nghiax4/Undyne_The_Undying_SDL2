#include "Attack_6_Manager.h"
#include "AttackRegistry.h"

Attack_6_Manager::Attack_6_Manager() : Green_Mode_Manager(6, 5500) {
    schedule_arrow(Direction::DOWN, 700, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 850, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 1000, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 1150, DEFAULT_ARROW_SPEED_Y);

    schedule_arrow(Direction::RIGHT, 1400, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::DOWN, 1650, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 1800, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 1950, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 2100, DEFAULT_ARROW_SPEED_Y);

    schedule_arrow(Direction::LEFT, 2250, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::DOWN, 2600, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 2750, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 2900, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 3050, DEFAULT_ARROW_SPEED_Y);

    schedule_arrow(Direction::RIGHT, 3220, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::DOWN, 3550, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 3700, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 3850, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 4000, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::LEFT, 4050, DEFAULT_ARROW_SPEED_X);
}

void Attack_6_Manager::render() {}

static AutoRegisterAttack<Attack_6_Manager> register_attack_6(6);
