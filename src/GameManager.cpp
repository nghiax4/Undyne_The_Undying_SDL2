#include "GameManager.h"
#include "BattleBox.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "Utils.h"

GameManager::GameManager() { obj_name = "GameManager"; }

void GameManager::update() {
    if (current_turn == Turn::EnemyTurn) {
        time_since_enemy_turn += deltaTime;
        if (time_since_enemy_turn > get_milliseconds_of_attack(current_attack_idx)) {
            current_turn = Turn::PlayerTurn;
            Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));
            Shield *shield = static_cast<Shield *>(find_object_by_name("Shield"));
            player->to_be_removed = true;
            shield->to_be_removed = true;
        }
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

int GameManager::get_milliseconds_of_attack(int attack_idx) { return 5000; }