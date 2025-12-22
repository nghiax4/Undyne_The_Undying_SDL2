#include "Attack_7_Manager.h"
#include "AttackRegistry.h"

Attack_7_Manager::Attack_7_Manager() {}

void Attack_7_Manager::update() {}
void Attack_7_Manager::render() {}
void Attack_7_Manager::ready_to_be_removed() {}

static AutoRegisterAttack<Attack_7_Manager> register_attack_7(7);
