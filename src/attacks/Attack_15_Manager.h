#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

// This attack is same as attack 8, but with faster spawn interval

struct Attack_15_Manager : public Attack_Manager_Base_Class {
    const int SPAWN_INTERVAL_MS = 800;
    int time_until_next_spawn = SPAWN_INTERVAL_MS;

    // Radius of the spawn circle
    const double SPAWN_RADIUS = SCREEN_WIDTH * 0.35;

    int number_of_arrows_created = 0;

    Attack_15_Manager();

    void update() override;
    void ready_to_be_removed() override;
};
