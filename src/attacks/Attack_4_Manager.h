#pragma once
#include "Red_Mode_Manager.h"

struct Attack_4_Manager : public Red_Mode_Manager {
    int time_elapsed_since_last_arrow = 0;
    int arrows_created = 0;

    Attack_4_Manager();

    void update() override;
    void render() override;
};
