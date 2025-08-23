#include "Attack_0_Manager.h"
#include "Arrow_For_Green_Attack.h"
#include "Globals.h"

Attack_0_Manager::Attack_0_Manager() {
    obj_name = "Attack_Manager_0";

    Arrow_For_Green_Attack *arrow_1 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.7, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_1");
    Arrow_For_Green_Attack *arrow_2 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.85, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_2");
    Arrow_For_Green_Attack *arrow_3 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 1, 0, SCREEN_HEIGHT * 0.0002, Direction::DOWN, "Attack_0_Arrow_For_Green_Attack_3");

    Arrow_For_Green_Attack *arrow_4 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 + SCREEN_WIDTH * 5, SCREEN_HEIGHT / 2, -SCREEN_WIDTH * 0.001, 0, Direction::LEFT, "Attack_0_Arrow_For_Green_Attack_4");
    Arrow_For_Green_Attack *arrow_5 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 5.4, 0, -SCREEN_HEIGHT * 0.001, Direction::UP, "Attack_0_Arrow_For_Green_Attack_5");
    Arrow_For_Green_Attack *arrow_6 = new Arrow_For_Green_Attack(SCREEN_WIDTH / 2 - SCREEN_WIDTH * 5.8, SCREEN_HEIGHT / 2, SCREEN_WIDTH * 0.001, 0, Direction::RIGHT, "Attack_0_Arrow_For_Green_Attack_6");

    objs.push_back(arrow_1);
    objs.push_back(arrow_2);
    objs.push_back(arrow_3);
    objs.push_back(arrow_4);
    objs.push_back(arrow_5);
    objs.push_back(arrow_6);
}

void Attack_0_Manager::update() { time_elapsed_since_creation += deltaTime; }

void Attack_0_Manager::render() {}

void Attack_0_Manager::ready_to_be_removed() {
    this->to_be_removed = true;
    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_0") == 0) {
            obj->to_be_removed = true;
        }
    }
}