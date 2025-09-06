#pragma once
#include "Attack_Manager_Base_Class.h"

struct Attack_6_Manager : public Attack_Manager_Base_Class {
    Attack_6_Manager();

    void update() override;
    void render() override;
    void ready_to_be_removed() override;
};