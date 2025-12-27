#include "Attack_8_Manager.h"
#include "AttackRegistry.h"

Attack_8_Manager::Attack_8_Manager() : Spinning_Arrow_Circle_Manager(8, 933) {}

static AutoRegisterAttack<Attack_8_Manager> register_attack_8(8);
