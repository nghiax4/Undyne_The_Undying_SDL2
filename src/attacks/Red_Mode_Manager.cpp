#include "Red_Mode_Manager.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"

Red_Mode_Manager::Red_Mode_Manager(int attack_id, int duration_ms, double box_center_y_ratio, double box_width_ratio, double box_height_ratio) : Attack_Manager_Base_Class(attack_id) {
    MILLISECONDS_LENGTH = duration_ms;

    static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->x_center = Engine::get().get_screen_width() / 2;
    static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->y_center = Engine::get().get_screen_height() * box_center_y_ratio;
    static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->width = Engine::get().get_screen_width() * box_width_ratio;
    static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->height = Engine::get().get_screen_height() * box_height_ratio;

    Player_EnemyTurn *player = new Player_EnemyTurn(static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->x_center, static_cast<BattleBox*>(Scene::get().find_object_by_name("BattleBox"))->y_center);
    Scene::get().spawn(std::unique_ptr<Player_EnemyTurn>(player));
}

void Red_Mode_Manager::ready_to_be_removed() {
    this->to_be_removed = true;

    // Remove the red player
    if (Scene::get().object_exists("Player_EnemyTurn")) {
        GameObject *player = Scene::get().find_object_by_name("Player_EnemyTurn");
        player->to_be_removed = true;
    }

    // Remove all projectiles owned by this attack
    for (auto &obj : Scene::get().get_objects()) {
        if (obj->obj_name.find(attack_prefix) == 0) {
            obj->to_be_removed = true;
        }
    }
}
