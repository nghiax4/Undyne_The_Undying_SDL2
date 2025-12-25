#include "Attack_Manager_Base_Class.h"
#include "Globals.h"
#include "Utils.h"
#include <Arrow_For_Green_Attack.h>

Attack_Manager_Base_Class::Attack_Manager_Base_Class(int _attack_id) : attack_id(_attack_id) {
    attack_prefix = "Attack_" + std::to_string(attack_id);
    obj_name = "Attack_Manager_" + std::to_string(attack_id);
}

void Attack_Manager_Base_Class::update() { time_elapsed_since_creation += deltaTime; }

void Attack_Manager_Base_Class::ready_to_be_removed() { this->to_be_removed = true; }

void Attack_Manager_Base_Class::_teardown_green_mode() {
    this->to_be_removed = true;

    GameObject *player = find_object_by_name("Player_EnemyTurn_Green");
    player->to_be_removed = true;

    GameObject *shield = find_object_by_name("Shield");
    shield->to_be_removed = true;

    // Remove all arrows/attacks specific to this attack
    for (auto &obj : objs) {
        if (obj->obj_name.find(attack_prefix) == 0) {
            obj->to_be_removed = true;
        }
    }
}

Arrow_For_Green_Attack *Attack_Manager_Base_Class::create_arrow_for_green_attack(double x, double y, double v_x, double v_y, Direction direction, int arrow_number) {
    std::string arrow_name = attack_prefix + "_Arrow_For_Green_Attack_" + std::to_string(arrow_number);
    return new Arrow_For_Green_Attack(x, y, v_x, v_y, direction, arrow_name);
}