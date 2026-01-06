#pragma once
#include "Red_Mode_Manager.h"

struct Circle_Spawn_Manager : public Red_Mode_Manager {
    Uint32 m_time_since_last_spawn;
    Uint32 m_current_interval;
    double m_spawn_radius;
    int m_items_created_counter = 0;

    Circle_Spawn_Manager(int attack_id, Uint32 duration_ms, Uint32 interval_ms, double radius);

    virtual void update() override;
    virtual void spawn_on_ring(double center_x, double center_y) = 0;
};
