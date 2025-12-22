#pragma once
#include "Arrow_For_Green_Attack.h"
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_2_Manager : public Attack_Manager_Base_Class {
    Attack_2_Manager();

    virtual void render() override;
    virtual void ready_to_be_removed() override;
};