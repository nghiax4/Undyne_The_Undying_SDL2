#pragma once
#include "Red_Mode_Manager.h"

struct Attack_3_Manager : public Red_Mode_Manager {
    const int TIME_PER_ARROW = 450;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created = 0;

    Attack_3_Manager();

    void update() override;
    void render() override;
};
