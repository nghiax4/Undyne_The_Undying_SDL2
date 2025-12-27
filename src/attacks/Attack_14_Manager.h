#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_14_Manager : public Attack_Manager_Base_Class {
    const int SPAWN_INTERVAL_MS = 633;
    const double SPAWN_RADIUS = SCREEN_WIDTH * 0.25;
    
    int time_until_next_spawn = SPAWN_INTERVAL_MS;
    int spears_created = 0;

    Attack_14_Manager();

    void update() override;
    void render() override;
    void ready_to_be_removed() override;
};