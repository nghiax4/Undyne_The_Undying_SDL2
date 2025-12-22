#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Globals.h"

struct Attack_5_Manager : public Attack_Manager_Base_Class {
    Attack_5_Manager();

    virtual void render() override;
    virtual void ready_to_be_removed() override;
};