#pragma once
#include "GameObject.h"

struct Attack_Manager_Base_Class : public GameObject {
    int MILLISECONDS_LENGTH;
    int time_elapsed_since_creation = 0;
    virtual void ready_to_be_removed();
};