#include "Attack_15_Manager.h"
#include "AttackRegistry.h"

Attack_15_Manager::Attack_15_Manager() : Spinning_Arrow_Circle_Manager(15, 800) {}

static AutoRegisterAttack<Attack_15_Manager> register_attack_15(15);
