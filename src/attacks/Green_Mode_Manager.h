#pragma once
#include "Attack_Manager_Base_Class.h"

#include <vector>

struct GreenModeArrowData {
    Direction direction;
    int time_to_impact_ms;
    double speed;
    ArrowType type = ArrowType::Blue;
};

struct Green_Mode_Manager : public Attack_Manager_Base_Class {
    int arrow_counter_for_unique_names = 0;

    Green_Mode_Manager(int attack_id, int duration_ms, std::vector<GreenModeArrowData> arrows_data);

    virtual void ready_to_be_removed() override;
};
