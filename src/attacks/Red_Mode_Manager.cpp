#include "Red_Mode_Manager.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"

Red_Mode_Manager::Red_Mode_Manager(int attack_id, Uint32 duration_ms, double box_center_y_ratio, double box_width_ratio, double box_height_ratio) : Attack_Manager_Base_Class(attack_id, duration_ms) {
    Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

    battle_box_transform->m_x_center = Engine::SCREEN_WIDTH / 2;
    battle_box_transform->m_y_center = Engine::SCREEN_HEIGHT * box_center_y_ratio;
    battle_box_transform->m_width = Engine::SCREEN_WIDTH * box_width_ratio;
    battle_box_transform->m_height = Engine::SCREEN_HEIGHT * box_height_ratio;

    Player_EnemyTurn *player = new Player_EnemyTurn(battle_box_transform->m_x_center, battle_box_transform->m_y_center);
    Scene::get().spawn(std::unique_ptr<Player_EnemyTurn>(player));
}

void Red_Mode_Manager::ready_to_be_removed() {
    m_to_be_removed = true;

    // Remove the red player
    if (Scene::get().object_exists("Player_EnemyTurn")) {
        GameObject *player = Scene::get().find_object_by_name("Player_EnemyTurn");
        player->m_to_be_removed = true;
    }

    // Remove all projectiles owned by this attack
    for (auto &obj : Scene::get().get_objects()) {
        if (obj->m_obj_name.find(m_attack_prefix) == 0) {
            obj->m_to_be_removed = true;
        }
    }
}
