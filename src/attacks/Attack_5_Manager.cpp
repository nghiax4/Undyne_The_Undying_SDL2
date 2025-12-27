#include "Attack_5_Manager.h"
#include "AttackRegistry.h"

Attack_5_Manager::Attack_5_Manager() : Green_Mode_Manager(5, 6000) {
    const double SPEED_X = SCREEN_WIDTH * 0.0007;
    const double SPEED_Y = SCREEN_HEIGHT * 0.0004;
    const double SPEED_Y_FAST = SCREEN_WIDTH * 0.0004; // using SCREEN_WIDTH to calculate Y speed here is probably intentional, I forgot

    schedule_arrow(Direction::RIGHT, 1000, SPEED_X);
    schedule_arrow(Direction::DOWN, 1750, SPEED_Y);

    schedule_arrow(Direction::LEFT, 2143, SPEED_X);
    schedule_arrow(Direction::UP, 2500, SPEED_Y);
    schedule_arrow(Direction::LEFT, 2857, SPEED_X);
    schedule_arrow(Direction::RIGHT, 3750, SPEED_Y_FAST);

    schedule_arrow(Direction::DOWN, 4375, SPEED_Y);
    schedule_arrow(Direction::UP, 5000, SPEED_Y);
}

void Attack_5_Manager::render() {}

static AutoRegisterAttack<Attack_5_Manager> register_attack_5(5);
