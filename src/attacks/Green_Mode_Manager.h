#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

// Abstract class to handle the setup and teardown of Green Soul mode (Shield + Green Player)
struct Green_Mode_Manager : public Attack_Manager_Base_Class {
    const double DEFAULT_ARROW_SPEED_X = SCREEN_WIDTH * 0.001;
    const double DEFAULT_ARROW_SPEED_Y = SCREEN_HEIGHT * 0.001;

    int arrow_counter_for_unique_names = 0;

    Green_Mode_Manager(int attack_id, int duration_ms);

    virtual void ready_to_be_removed() override;

    // Helper to shorten the syntax in the derived classes
    // defaulting arrow_type to Blue as it is most common
    void schedule_arrow(Direction direction, int time_to_impact_ms, double speed_val, ArrowType arrow_type = ArrowType::Blue);
};
