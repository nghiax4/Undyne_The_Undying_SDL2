#include "GameManager.h"
#include "Attack_0_Manager.h"
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
        if (attack_manager->time_elapsed_since_creation <= get_milliseconds_of_attack(current_attack_idx))
            return;

        current_turn = Turn::PlayerTurn;
        Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));
        Shield *shield = static_cast<Shield *>(find_object_by_name("Shield"));
        player->to_be_removed = true;
        shield->to_be_removed = true;
        attack_manager->ready_to_be_removed();

        BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
        battlebox->x_center = SCREEN_WIDTH / 2;
        battlebox->y_center = SCREEN_HEIGHT * 0.67;
        battlebox->width = SCREEN_WIDTH * 0.9;
        battlebox->height = SCREEN_HEIGHT * 0.3;
    }

    if (current_turn == Turn::PlayerTurn && cur_keyboard_state[SDL_SCANCODE_RETURN]) {
        current_turn = Turn::EnemyTurn;

        BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
        battlebox->x_center = SCREEN_WIDTH / 2;
        battlebox->y_center = SCREEN_HEIGHT / 2;
        battlebox->width = SCREEN_WIDTH * 0.13;
        battlebox->height = SCREEN_WIDTH * 0.13;

        Player_EnemyTurn_Green *player = new Player_EnemyTurn_Green(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        Shield *shield = new Shield();

        objs.push_back(player);
        objs.push_back(shield);

        play_attack(current_attack_idx);
    }
}

void GameManager::render() {}

void GameManager::play_attack(int attack_idx) {
    if (attack_idx == 0) {
        Attack_0_Manager *attack_0 = new Attack_0_Manager();
        objs.push_back(attack_0);
    } else {
        throw std::runtime_error(std::string("attack_idx=") + std::to_string(attack_idx) + std::string(" not supported yet."));
    }
}

int GameManager::get_milliseconds_of_attack(int attack_idx) {
    if (attack_idx == 0) {
        return Attack_0_Manager::MILLISECONDS_LENGTH;
    } else {
        throw std::runtime_error(std::string("attack_idx=") + std::to_string(attack_idx) + std::string(" not supported yet."));
    }
}

Attack_Manager_Base_Class *GameManager::find_attack_manager() {
    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_Manager_") == 0) {
            return static_cast<Attack_Manager_Base_Class *>(obj);
        }
    }

    throw std::runtime_error("No attack manager object found");
}