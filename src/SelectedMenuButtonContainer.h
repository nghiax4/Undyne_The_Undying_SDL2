#pragma once
#include "GameObject.h"
#include <string>

struct SelectedMenuButtonContainer : public GameObject {
    size_t m_selected_menu_button;

    SelectedMenuButtonContainer();

    virtual void update() override;
};
