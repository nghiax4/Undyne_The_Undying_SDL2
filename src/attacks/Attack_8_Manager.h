#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_8_Manager : public Attack_Manager_Base_Class {
    const int SPAWN_INTERVAL_MS = 933;
    int time_until_next_spawn = 0;

    // Radius of the spawn circle
    const double SPAWN_RADIUS = SCREEN_WIDTH * 0.35;

    int number_of_arrows_created = 0;

    Attack_8_Manager();
    void update() override;
};
