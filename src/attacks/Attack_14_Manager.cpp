#include "Attack_14_Manager.h"
#include "AttackRegistry.h"
#include "Player_EnemyTurn.h"
#include "Ring_Spear.h"
#include "Utils.h"

Attack_14_Manager::Attack_14_Manager() : Attack_Manager_Base_Class(14) {
    MILLISECONDS_LENGTH = 12000;

    global_battlebox->x_center = SCREEN_WIDTH / 2;
    global_battlebox->y_center = SCREEN_HEIGHT * 0.5;
    global_battlebox->width = SCREEN_WIDTH * 0.9;
    global_battlebox->height = SCREEN_HEIGHT * 0.6;

    Player_EnemyTurn *player = new Player_EnemyTurn(global_battlebox->x_center, global_battlebox->y_center);
    objs.push_back(player);
}

void Attack_14_Manager::update() {
    Attack_Manager_Base_Class::update();
    time_until_next_spawn -= deltaTime;

    // Hard switch to faster interval (333ms) after 5000ms
    int current_interval = (time_elapsed_since_creation > 5000) ? 333 : 633;

    if (time_until_next_spawn <= 0) {
        time_until_next_spawn = current_interval;

        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));

        double center_x = player->x_center;
        double center_y = player->y_center;

        double angle_offset = get_random(0, 360);
        const int SPEARS_PER_RING = 6;

        for (int i = 0; i < SPEARS_PER_RING; i++) {
            double angle = angle_offset + (360.0 / SPEARS_PER_RING) * i;

            Ring_Spear *spear = new Ring_Spear(center_x, center_y, angle, SPAWN_RADIUS, attack_prefix + "_Ring_Spear_" + std::to_string(spears_created));
            objs.push_back(spear);
            spears_created++;
        }
    }
}

void Attack_14_Manager::render() {}

void Attack_14_Manager::ready_to_be_removed() {
    Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));
    player->to_be_removed = true;
    this->to_be_removed = true;

    for (auto &obj : objs) {
        if (dynamic_cast<Ring_Spear *>(obj) != nullptr) {
            obj->to_be_removed = true;
        }
    }
}

static AutoRegisterAttack<Attack_14_Manager> register_attack_14(14);