#include "Circle_Spawn_Manager.h"
#include "Player_EnemyTurn.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"

Circle_Spawn_Manager::Circle_Spawn_Manager(int attack_id, int duration_ms, int interval_ms, double radius) : Red_Mode_Manager(attack_id, duration_ms, 0.5, 0.9, 0.6), time_until_next_spawn(interval_ms), current_interval(interval_ms), spawn_radius(radius) {}

void Circle_Spawn_Manager::update() {
    Red_Mode_Manager::update();
    time_until_next_spawn -= Engine::get().get_delta_time();

    if (time_until_next_spawn <= 0) {
        time_until_next_spawn = current_interval;

        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(Scene::get().find_object_by_name("Player_EnemyTurn"));
        spawn_on_ring(player->x_center, player->y_center);
    }
}
