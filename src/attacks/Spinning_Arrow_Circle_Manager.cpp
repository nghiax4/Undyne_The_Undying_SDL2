#include "Spinning_Arrow_Circle_Manager.h"
#include "AttackRegistry.h"
#include "Spinning_Arrow.h"
#include "Utils.h"

Spinning_Arrow_Circle_Manager::Spinning_Arrow_Circle_Manager(int attack_id, int interval_ms) : Circle_Spawn_Manager(attack_id, 10000, interval_ms, SCREEN_WIDTH * 0.35) {}

void Spinning_Arrow_Circle_Manager::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    int arrows_per_ring = 7;

    for (int i = 0; i < arrows_per_ring; i++) {
        double angle = angle_offset + (360.0 / arrows_per_ring) * i;

        Spinning_Arrow *arrow = new Spinning_Arrow(center_x, center_y, angle, spawn_radius, attack_prefix + "_Spinning_Arrow_" + std::to_string(items_created_counter));
        objs.push_back(arrow);
        items_created_counter++;
    }
}
