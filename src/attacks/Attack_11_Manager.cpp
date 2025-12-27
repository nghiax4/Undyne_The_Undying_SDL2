#include "Attack_11_Manager.h"
#include "AttackRegistry.h"

Attack_11_Manager::Attack_11_Manager() : Green_Mode_Manager(11, 7000) {
    const double SPEED_X = SCREEN_WIDTH * 0.00075;
    const double SPEED_Y = SCREEN_HEIGHT * 0.00075;

    schedule_arrow(Direction::RIGHT, 900, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 1234, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 1567, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 1867, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::RIGHT, 2200, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 2467, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::UP, 2800, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::UP, 3134, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::RIGHT, 3500, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 3767, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 4134, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 4500, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::RIGHT, 4800, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 5067, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::UP, 5367, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::UP, 5767, SPEED_Y, ArrowType::Yellow);
}

void Attack_11_Manager::render() {}

static AutoRegisterAttack<Attack_11_Manager> register_attack_11(11);
