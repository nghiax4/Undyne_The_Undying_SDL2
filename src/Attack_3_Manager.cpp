#include "Attack_3_Manager.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"

Attack_3_Manager::Attack_3_Manager() {
    obj_name = "Attack_Manager_3";
    MILLISECONDS_LENGTH = 5000;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    battlebox->x_center = SCREEN_WIDTH / 2;
    battlebox->y_center = SCREEN_HEIGHT * 0.72;
    battlebox->width = SCREEN_WIDTH * 0.12;
    battlebox->height = SCREEN_HEIGHT * 0.19;

    Player_EnemyTurn *player = new Player_EnemyTurn(battlebox->x_center, battlebox->y_center);

    objs.push_back(player);
}

void Attack_3_Manager::update() {}
void Attack_3_Manager::render() {}
void Attack_3_Manager::ready_to_be_removed() {
    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));
    player->to_be_removed = true;

    for (auto &obj : objs) {
        if (obj->obj_name.find("Attack_3") == 0) {
            obj->to_be_removed = true;
        }
    }
}