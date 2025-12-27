#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

// This attack is same as attack 8, so they have exactly same code (need to refactor in the future)

struct Attack_9_Manager : public Attack_Manager_Base_Class {
    const int SPAWN_INTERVAL_MS = 933;
    int time_until_next_spawn = SPAWN_INTERVAL_MS;

    // Radius of the spawn circle
    const double SPAWN_RADIUS = SCREEN_WIDTH * 0.35;

    int number_of_arrows_created = 0;

    Attack_9_Manager();

    void update() override;
    void ready_to_be_removed() override;
};
