#include "Attack_Manager_Base_Class.h"
#include "Globals.h"
#include "Utils.h"

void Attack_Manager_Base_Class::update() {
    time_elapsed_since_creation += deltaTime;
}

void Attack_Manager_Base_Class::ready_to_be_removed() {
    this->to_be_removed = true;
}

void Attack_Manager_Base_Class::_teardown_green_mode(std::string attack_prefix) {
    this->to_be_removed = true;

    GameObject* player = find_object_by_name("Player_EnemyTurn_Green");
    player->to_be_removed = true;
    
    GameObject* shield = find_object_by_name("Shield");
    shield->to_be_removed = true;

    // Remove all arrows/attacks specific to this attack
    for (auto &obj : objs) {
        if (obj->obj_name.find(attack_prefix) == 0) {
            obj->to_be_removed = true;
        }
    }
}
