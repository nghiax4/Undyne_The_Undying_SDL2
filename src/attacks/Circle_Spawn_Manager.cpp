#include "Circle_Spawn_Manager.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include <cinttypes>

Circle_Spawn_Manager::Circle_Spawn_Manager(int attack_id, Uint32 duration_ms, Uint32 interval_ms, double radius) : Red_Mode_Manager(attack_id, duration_ms, 0.5, 0.9, 0.6), m_time_since_last_spawn(interval_ms), m_current_interval(interval_ms), m_spawn_radius(radius) {}

void Circle_Spawn_Manager::update() {
    Red_Mode_Manager::update();
    m_time_since_last_spawn += Engine::get().get_delta_time();

    if (m_time_since_last_spawn >= m_current_interval) {
        m_time_since_last_spawn = 0;

        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(Scene::get().find_object_by_name("Player_EnemyTurn"));
        spawn_on_ring(player->m_x_center, player->m_y_center);
    }
}
