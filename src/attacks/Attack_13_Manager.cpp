#include "Attack_13_Manager.h"
#include "AttackRegistry.h"

Attack_13_Manager::Attack_13_Manager() : Green_Mode_Manager(13, 12500) {
    const double SPEED_X = SCREEN_WIDTH * 0.00012;
    const double SPEED_Y = SCREEN_HEIGHT * 0.00012;

    schedule_arrow(Direction::DOWN, 5733, SPEED_Y);
    schedule_arrow(Direction::LEFT, 5967, SPEED_X);
    schedule_arrow(Direction::DOWN, 6300, SPEED_Y);
    schedule_arrow(Direction::DOWN, 6567, SPEED_Y);

    schedule_arrow(Direction::RIGHT, 6800, SPEED_X);
    schedule_arrow(Direction::LEFT, 7067, SPEED_X);
    schedule_arrow(Direction::UP, 7467, SPEED_Y);
    schedule_arrow(Direction::LEFT, 7733, SPEED_X);

    schedule_arrow(Direction::DOWN, 7967, SPEED_Y);
    schedule_arrow(Direction::UP, 8133, SPEED_Y);
    schedule_arrow(Direction::RIGHT, 8467, SPEED_X);
    schedule_arrow(Direction::LEFT, 8667, SPEED_X);

    schedule_arrow(Direction::UP, 8900, SPEED_Y);
    schedule_arrow(Direction::UP, 9133, SPEED_Y);
    schedule_arrow(Direction::RIGHT, 9467, SPEED_X);
    schedule_arrow(Direction::LEFT, 9700, SPEED_X);

    schedule_arrow(Direction::LEFT, 10000, SPEED_X);
    schedule_arrow(Direction::RIGHT, 10367, SPEED_X);
    schedule_arrow(Direction::UP, 10667, SPEED_Y);
    schedule_arrow(Direction::UP, 10900, SPEED_Y);

    schedule_arrow(Direction::UP, 11033, SPEED_Y);
    schedule_arrow(Direction::LEFT, 11267, SPEED_X);
    schedule_arrow(Direction::DOWN, 11600, SPEED_Y);
    schedule_arrow(Direction::DOWN, 11900, SPEED_Y);
}

void Attack_13_Manager::render() {}

static AutoRegisterAttack<Attack_13_Manager> register_attack_13(13);
