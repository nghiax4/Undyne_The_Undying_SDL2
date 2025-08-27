#pragma once
#include "GameObject.h"
#include <string>

struct SelectedMenuButtonContainer : public GameObject {
    int selected_menu_button;

    SelectedMenuButtonContainer();

    virtual void update() override;
};