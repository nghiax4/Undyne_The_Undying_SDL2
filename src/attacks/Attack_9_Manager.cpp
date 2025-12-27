#include "Attack_9_Manager.h"
#include "AttackRegistry.h"

Attack_9_Manager::Attack_9_Manager() : Spinning_Arrow_Circle_Manager(9, 933) {}

static AutoRegisterAttack<Attack_9_Manager> register_attack_9(9);
