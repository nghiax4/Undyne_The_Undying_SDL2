#include "Attack_8_Manager.h"
#include "AttackRegistry.h"
#include "Player_EnemyTurn.h"
#include "Spinning_Arrow.h"
#include "Utils.h"

Attack_8_Manager::Attack_8_Manager() : Attack_Manager_Base_Class(8) {
    MILLISECONDS_LENGTH = 10000; // Lasts 10 seconds

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT * 0.5;
    global_battlebox->width = SCREEN_WIDTH * 0.9;
    global_battlebox->height = SCREEN_HEIGHT * 0.6;

    Player_EnemyTurn *player = new Player_EnemyTurn(global_battlebox->x_center, global_battlebox->y_center);
    objs.push_back(player);
}

void Attack_8_Manager::update() {
    time_elapsed_since_creation += deltaTime;
    time_until_next_spawn -= deltaTime;

    if (time_until_next_spawn <= 0) {
        time_until_next_spawn = SPAWN_INTERVAL_MS;

        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));

        double center_x = player->x_center;
        double center_y = player->y_center;

        // Random offset for the rotation start angle so patterns aren't identical
        double angle_offset = get_random(0, 360);

        int arrows_per_ring = 7;
        for (int i = 0; i < arrows_per_ring; i++) {
            double angle = angle_offset + (360.0 / arrows_per_ring) * i;

            Spinning_Arrow *arrow = new Spinning_Arrow(center_x, center_y, angle, SPAWN_RADIUS, attack_prefix + std::string("_Spinning_Arrow_") + std::to_string(number_of_arrows_created));
            objs.push_back(arrow);
            number_of_arrows_created++;
        }
    }
}

static AutoRegisterAttack<Attack_8_Manager> register_attack(8);
