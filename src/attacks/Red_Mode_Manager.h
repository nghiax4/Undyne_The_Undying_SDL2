#pragma once
#include "Attack_Manager_Base_Class.h"

struct Red_Mode_Manager : public Attack_Manager_Base_Class {
    // box_center_y_ratio: 0.5 means center of screen vertically
    // box_width_ratio: 0.9 means 90% of Screen Width
    // box_height_ratio: 0.6 means 60% of Screen Height
    Red_Mode_Manager(int attack_id, int duration_ms, double box_center_y_ratio, double box_width_ratio, double box_height_ratio);

    virtual void ready_to_be_removed() override;
};
