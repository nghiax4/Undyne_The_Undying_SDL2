#pragma once
#include "Attack_Manager_Base_Class.h"

struct Attack_13_Manager : public Attack_Manager_Base_Class {
    Attack_13_Manager();

    void render() override;
    void ready_to_be_removed() override;
};
