#pragma once
#include "Attack_Manager_Base_Class.h"

struct Attack_11_Manager : public Attack_Manager_Base_Class {
    Attack_11_Manager();

    void render() override;
    void ready_to_be_removed() override;
};
