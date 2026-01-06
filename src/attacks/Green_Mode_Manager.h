#pragma once
#include "Attack_Manager_Base_Class.h"

#include <vector>

struct GreenModeArrowData {
    Direction m_direction;
    Uint32 m_time_to_impact_ms;
    double m_speed;
    ArrowType m_type = ArrowType::Blue;
};

struct Green_Mode_Manager : public Attack_Manager_Base_Class {
    int arrow_counter_for_unique_names = 0;

    Green_Mode_Manager(int attack_id, Uint32 duration_ms, std::vector<GreenModeArrowData> arrows_data);

    virtual void ready_to_be_removed() override;
};
