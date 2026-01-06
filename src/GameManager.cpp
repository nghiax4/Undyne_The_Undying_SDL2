#include "GameManager.h"
#include "Attack_Manager_Base_Class.h"
#include "BattleBox.h"
#include "BattleText.h"
#include "CreateAttackFromAttackId.h"
#include "GameplayTypes.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "Turn.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Input.h"
#include "core/Scene.h"

GameManager::GameManager() {
    m_obj_name = "GameManager";
}

void GameManager::update() {
    if (m_current_turn == Turn::EnemyTurn) {
        Attack_Manager_Base_Class *attack_manager = find_attack_manager();
        if (attack_manager->m_time_elapsed_since_creation <= attack_manager->m_milliseconds_length)
            return;

        m_current_turn = Turn::PlayerTurn;
        attack_manager->ready_to_be_removed();

        static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_x_center = Engine::SCREEN_WIDTH / 2;
        static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_y_center = Engine::SCREEN_HEIGHT * 0.67;
        static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_width = Engine::SCREEN_WIDTH * 0.9;
        static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_height = Engine::SCREEN_HEIGHT * 0.3;

        m_current_attack_idx += 1;

        if (!Scene::get().object_exists("BattleText")) {
            Scene::get().spawn(std::make_unique<BattleText>());
        }
    }

    if (m_current_turn == Turn::PlayerTurn && Input::get().is_key_down(SDL_SCANCODE_RETURN)) {
        m_current_turn = Turn::EnemyTurn;
        play_attack(m_current_attack_idx);
    }
}

void GameManager::render() {}

void GameManager::play_attack(int attack_idx) {
    Attack_Manager_Base_Class *attack = create_attack(attack_idx);
    Scene::get().spawn(std::unique_ptr<Attack_Manager_Base_Class>(attack));
}

Attack_Manager_Base_Class *GameManager::find_attack_manager() {
    for (auto &obj : Scene::get().get_objects()) {
        if (obj->m_obj_name.find("Attack_Manager_") == 0) {
            return static_cast<Attack_Manager_Base_Class *>(obj.get());
        }
    }

    throw std::runtime_error("No attack manager object found");
}
