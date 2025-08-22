#include "GameManager.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Utils.h"

void GameManager::update() {
    if (current_turn == Turn::PlayerTurn && cur_keyboard_state[SDL_SCANCODE_RETURN]) {
        current_turn = Turn::EnemyTurn;
        BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    }
}

void GameManager::render() {}