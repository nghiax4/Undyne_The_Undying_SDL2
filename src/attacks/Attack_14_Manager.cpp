#include "Attack_14_Manager.h"
#include "AttackRegistry.h"
#include "Ring_Spear.h"
#include "Utils.h"

Attack_14_Manager::Attack_14_Manager() : Circle_Spawn_Manager(14, 12000, 633, SCREEN_WIDTH * 0.25) {}

void Attack_14_Manager::update() {
    current_interval = (time_elapsed_since_creation > 5000) ? 333 : 633;
    Circle_Spawn_Manager::update();
}

void Attack_14_Manager::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    const int SPEARS_PER_RING = 6;

    for (int i = 0; i < SPEARS_PER_RING; i++) {
        double angle = angle_offset + (360.0 / SPEARS_PER_RING) * i;

        Ring_Spear *spear = new Ring_Spear(center_x, center_y, angle, spawn_radius, attack_prefix + "_Ring_Spear_" + std::to_string(items_created_counter));
        objs.push_back(spear);
        items_created_counter++;
    }
}

static AutoRegisterAttack<Attack_14_Manager> register_attack_14(14);
