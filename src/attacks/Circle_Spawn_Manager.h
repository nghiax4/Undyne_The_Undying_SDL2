#pragma once
#include "Red_Mode_Manager.h"

struct Circle_Spawn_Manager : public Red_Mode_Manager {
    int time_until_next_spawn;
    int current_interval;
    double spawn_radius;
    int items_created_counter = 0;

    Circle_Spawn_Manager(int attack_id, int duration_ms, int interval_ms, double radius);

    virtual void update() override;
    virtual void spawn_on_ring(double center_x, double center_y) = 0;
};
