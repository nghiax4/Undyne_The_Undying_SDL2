#include "Attack_10_Manager.h"
#include "AttackRegistry.h"

Attack_10_Manager::Attack_10_Manager() : Green_Mode_Manager(10, 7000) {
    const float SPEED_X = SCREEN_WIDTH * 0.0012;
    const float SPEED_Y = SCREEN_HEIGHT * 0.0012;

    schedule_arrow(Direction::RIGHT, 1700, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 2033, SPEED_Y, ArrowType::Yellow);
    schedule_arrow(Direction::LEFT, 2366, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::DOWN, 2766, SPEED_Y, ArrowType::Yellow);

    schedule_arrow(Direction::UP, 2966, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::LEFT, 3300, SPEED_X, ArrowType::Blue);
    schedule_arrow(Direction::DOWN, 3633, SPEED_Y, ArrowType::Blue);
    schedule_arrow(Direction::RIGHT, 3966, SPEED_X, ArrowType::Blue);

    schedule_arrow(Direction::DOWN, 4766, SPEED_Y, ArrowType::Yellow);
    schedule_arrow(Direction::LEFT, 5100, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::RIGHT, 5433, SPEED_X, ArrowType::Yellow);
    schedule_arrow(Direction::UP, 5766, SPEED_Y, ArrowType::Yellow);
}

void Attack_10_Manager::render() {}

static AutoRegisterAttack<Attack_10_Manager> register_attack_10(10);
