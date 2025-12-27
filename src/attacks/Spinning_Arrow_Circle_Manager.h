#pragma once
#include "Circle_Spawn_Manager.h"

struct Spinning_Arrow_Circle_Manager : public Circle_Spawn_Manager {
    Spinning_Arrow_Circle_Manager(int attack_id, int interval_ms);

    void spawn_on_ring(double center_x, double center_y) override;
};
