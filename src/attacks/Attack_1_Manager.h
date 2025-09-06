#pragma once
#include "Attack_Manager_Base_Class.h"

struct Attack_1_Manager : public Attack_Manager_Base_Class {
    Attack_1_Manager();

    virtual void update() override;
    virtual void render() override;
    virtual void ready_to_be_removed() override;
};