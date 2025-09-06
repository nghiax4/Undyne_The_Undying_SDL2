#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_3_Manager : public Attack_Manager_Base_Class {
    const int TIME_PER_ARROW = 450;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created = 0;
    Attack_3_Manager();

    virtual void update() override;
    virtual void render() override;
    virtual void ready_to_be_removed() override;
};
