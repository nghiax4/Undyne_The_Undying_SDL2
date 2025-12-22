#include "GameManager.h"
#include "AttackRegistry.h"
#include "Attack_Manager_Base_Class.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "Utils.h"

GameManager::GameManager() { obj_name = "GameManager"; }

void GameManager::update() {
    if (current_turn == Turn::EnemyTurn) {
        Attack_Manager_Base_Class *attack_manager = find_attack_manager();
        if (attack_manager->time_elapsed_since_creation <= attack_manager->MILLISECONDS_LENGTH)
            return;

        current_turn = Turn::PlayerTurn;
        attack_manager->ready_to_be_removed();

        BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
        battlebox->x_center = SCREEN_WIDTH / 2;
        battlebox->y_center = SCREEN_HEIGHT * 0.67;
        battlebox->width = SCREEN_WIDTH * 0.9;
        battlebox->height = SCREEN_HEIGHT * 0.3;

        current_attack_idx += 1;
    }

    if (current_turn == Turn::PlayerTurn && cur_keyboard_state[SDL_SCANCODE_RETURN]) {
        current_turn = Turn::EnemyTurn;
        play_attack(current_attack_idx);
    }
}

void GameManager::render() {}

void GameManager::play_attack(int attack_idx) {
    Attack_Manager_Base_Class *attack = AttackRegistry::create_attack(attack_idx);
    objs.push_back(attack);
}

Attack_Manager_Base_Class *GameManager::find_attack_manager() {
    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_Manager_") == 0) {
            return static_cast<Attack_Manager_Base_Class *>(obj);
        }
    }

    throw std::runtime_error("No attack manager object found");
}
