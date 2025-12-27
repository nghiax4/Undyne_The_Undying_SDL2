#include "Attack_0_Manager.h"
#include "AttackRegistry.h"

Attack_0_Manager::Attack_0_Manager() : Green_Mode_Manager(0, 10000) {
    const double SLOW_SPEED_Y = SCREEN_HEIGHT * 0.0002;

    schedule_arrow(Direction::DOWN, 3500, SLOW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 4250, SLOW_SPEED_Y);
    schedule_arrow(Direction::DOWN, 5000, SLOW_SPEED_Y);

    schedule_arrow(Direction::LEFT, 5000, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::UP, 5400, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::RIGHT, 5800, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::DOWN, 6200, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::RIGHT, 6600, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::UP, 7000, DEFAULT_ARROW_SPEED_Y);

    schedule_arrow(Direction::LEFT, 7400, DEFAULT_ARROW_SPEED_X);
    schedule_arrow(Direction::UP, 7800, DEFAULT_ARROW_SPEED_Y);
    schedule_arrow(Direction::RIGHT, 8200, DEFAULT_ARROW_SPEED_X);

    schedule_arrow(Direction::DOWN, 8600, DEFAULT_ARROW_SPEED_Y);
}

void Attack_0_Manager::render() {}

static AutoRegisterAttack<Attack_0_Manager> register_attack_0(0);
