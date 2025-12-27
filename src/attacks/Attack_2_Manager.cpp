#include "Attack_2_Manager.h"
#include "AttackRegistry.h"

Attack_2_Manager::Attack_2_Manager() : Green_Mode_Manager(2, 11000) {
    const double SPEED_X = SCREEN_WIDTH * 0.0002;
    const double SPEED_Y = SCREEN_HEIGHT * 0.0002;

    schedule_arrow(Direction::UP, 3500, SPEED_Y);
    schedule_arrow(Direction::DOWN, 3750, SPEED_Y);

    schedule_arrow(Direction::LEFT, 4000, SPEED_X);
    schedule_arrow(Direction::DOWN, 4500, SPEED_Y);

    schedule_arrow(Direction::DOWN, 5000, SPEED_Y);
    schedule_arrow(Direction::LEFT, 5500, SPEED_X);

    schedule_arrow(Direction::RIGHT, 5750, SPEED_X);
    schedule_arrow(Direction::RIGHT, 5900, SPEED_X);

    schedule_arrow(Direction::UP, 6250, SPEED_Y);
    schedule_arrow(Direction::LEFT, 6500, SPEED_X);

    schedule_arrow(Direction::DOWN, 7000, SPEED_Y);
    schedule_arrow(Direction::DOWN, 7500, SPEED_Y);

    schedule_arrow(Direction::UP, 8000, SPEED_Y);

    schedule_arrow(Direction::DOWN, 8500, SPEED_Y);
    schedule_arrow(Direction::DOWN, 8650, SPEED_Y);

    schedule_arrow(Direction::LEFT, 8800, SPEED_X);
    schedule_arrow(Direction::RIGHT, 8950, SPEED_X);

    schedule_arrow(Direction::LEFT, 9100, SPEED_X);
    schedule_arrow(Direction::RIGHT, 9250, SPEED_X);
}

void Attack_2_Manager::render() {}

static AutoRegisterAttack<Attack_2_Manager> register_attack_2(2);
