#pragma once
#include "Circle_Spawn_Manager.h"

struct Attack_14_Manager : public Circle_Spawn_Manager {
    Attack_14_Manager();
    void update() override;
    void spawn_on_ring(double center_x, double center_y) override;
    void render() override {}
};
