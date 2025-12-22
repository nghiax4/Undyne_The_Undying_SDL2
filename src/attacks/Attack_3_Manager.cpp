#include "Attack_3_Manager.h"
#include "AttackRegistry.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "White_Arrow_Small_Box_Attack.h"

Attack_3_Manager::Attack_3_Manager() {
    obj_name = "Attack_Manager_3";
    MILLISECONDS_LENGTH = 8500;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT * 0.72;
    global_battlebox->width = SCREEN_WIDTH * 0.12;
    global_battlebox->height = SCREEN_HEIGHT * 0.19;

    Player_EnemyTurn *player = new Player_EnemyTurn(global_battlebox->x_center, global_battlebox->y_center);

    objs.push_back(player);
}

void Attack_3_Manager::update() {
    Attack_Manager_Base_Class::update();

    time_elapsed_since_last_arrow += deltaTime;

    if (time_elapsed_since_last_arrow <= TIME_PER_ARROW)
        return;

    std::vector<double> x_multiplier = {0.8 / 4, 1.0 / 2, 3.2 / 4};
    double x_center_of_arrow = global_battlebox->x_center - global_battlebox->width / 2 + global_battlebox->width * x_multiplier.at(get_random(0, 2));
    double y_center_of_arrow = global_battlebox->y_center + global_battlebox->height;

    White_Arrow_Small_Box_Attack *arrow = new White_Arrow_Small_Box_Attack(x_center_of_arrow, y_center_of_arrow, "Attack_3_White_Arrow_" + std::to_string(arrows_created));

    objs.push_back(arrow);

    time_elapsed_since_last_arrow = 0;
    arrows_created += 1;
}

void Attack_3_Manager::render() {}
void Attack_3_Manager::ready_to_be_removed() {
    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));
    player->to_be_removed = true;
    this->to_be_removed = true;

    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_3") == 0) {
            obj->to_be_removed = true;
        }
    }
}

static AutoRegisterAttack<Attack_3_Manager> register_attack_3(3);
