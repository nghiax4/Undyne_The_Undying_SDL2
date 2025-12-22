#include "Attack_7_Manager.h"
#include "AttackRegistry.h"

Attack_7_Manager::Attack_7_Manager() {
    obj_name = "Attack_Manager_7";
    MILLISECONDS_LENGTH = 5000;
}

static AutoRegisterAttack<Attack_7_Manager> register_attack_7(7);
