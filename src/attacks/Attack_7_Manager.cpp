#include "Attack_7_Manager.h"
#include "AttackRegistry.h"

Attack_7_Manager::Attack_7_Manager() : Green_Mode_Manager(7, 6500) {
    const double SPEED_X = SCREEN_WIDTH * 0.0005;
    const double SPEED_Y = SCREEN_HEIGHT * 0.0005;

    schedule_arrow(Direction::RIGHT, 1067, SPEED_X);
    schedule_arrow(Direction::DOWN, 1400, SPEED_Y);
    schedule_arrow(Direction::RIGHT, 1667, SPEED_X);
    schedule_arrow(Direction::DOWN, 2000, SPEED_Y);
    schedule_arrow(Direction::RIGHT, 2233, SPEED_X);
    schedule_arrow(Direction::DOWN, 2600, SPEED_Y);
    schedule_arrow(Direction::RIGHT, 2833, SPEED_X);
    schedule_arrow(Direction::DOWN, 3167, SPEED_Y);

    schedule_arrow(Direction::LEFT, 3800, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 4067, SPEED_Y, ArrowType::Yellow);
    schedule_arrow(Direction::LEFT, 4400, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 4667, SPEED_Y, ArrowType::Yellow);
    schedule_arrow(Direction::LEFT, 5000, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 5267, SPEED_Y, ArrowType::Yellow);
}

void Attack_7_Manager::render() {}

static AutoRegisterAttack<Attack_7_Manager> register_attack_7(7);
