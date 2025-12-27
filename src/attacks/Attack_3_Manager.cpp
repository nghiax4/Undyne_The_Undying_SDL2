#include "Attack_3_Manager.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Globals.h" // For SCREEN_WIDTH/HEIGHT access if needed
#include "Utils.h"
#include "White_Arrow_Small_Box_Attack.h"
#include <vector>

Attack_3_Manager::Attack_3_Manager() : Red_Mode_Manager(3, 8500, 0.72, 0.12, 0.19) {}

void Attack_3_Manager::update() {
    Red_Mode_Manager::update();

    time_elapsed_since_last_arrow += deltaTime;

    if (time_elapsed_since_last_arrow <= TIME_PER_ARROW)
        return;

    std::vector<double> x_multiplier = {0.8 / 4, 1.0 / 2, 3.2 / 4};
    double x_center_of_arrow = global_battlebox->x_center - global_battlebox->width / 2 + global_battlebox->width * x_multiplier.at(get_random(0, 2));
    double y_center_of_arrow = global_battlebox->y_center + global_battlebox->height;

    White_Arrow_Small_Box_Attack *arrow = new White_Arrow_Small_Box_Attack(x_center_of_arrow, y_center_of_arrow, attack_prefix + "_White_Arrow_" + std::to_string(arrows_created));

    objs.push_back(arrow);

    time_elapsed_since_last_arrow = 0;
    arrows_created += 1;
}

void Attack_3_Manager::render() {}

static AutoRegisterAttack<Attack_3_Manager> register_attack_3(3);
