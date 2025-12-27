#include "Attack_12_Manager.h"
#include "AttackRegistry.h"

Attack_12_Manager::Attack_12_Manager() : Green_Mode_Manager(12, 7000) {
    const double SPEED_X = SCREEN_WIDTH * 0.00075;
    const double SPEED_Y = SCREEN_HEIGHT * 0.00075;

    schedule_arrow(Direction::RIGHT, 800, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 1333, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 1567, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 2167, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::LEFT, 2400, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::RIGHT, 2933, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::DOWN, 3233, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::UP, 3800, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::RIGHT, 4067, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 4633, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 4833, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 5433, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::LEFT, 5667, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::RIGHT, 6233, SPEED_X, ArrowType::Yellow);
}

void Attack_12_Manager::render() {}

static AutoRegisterAttack<Attack_12_Manager> register_attack_12(12);
