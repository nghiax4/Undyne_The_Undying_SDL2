#pragma once
#include "GameObject.h"
#include "Utils.h"
#include <SDL2/SDL.h>
#include <string>

struct MenuButton : public GameObject {
  public:
    SmartTexture m_texture_unselected_obj;
    SmartTexture m_texture_selected_obj;

    MenuButton(double x_center, double y_center, double width, double height, std::string sprite_unselected_path, std::string sprite_selected_path, int button_index);

    virtual void update() override;

    virtual void render() override;

    // Check if the button is currently selected by checking if the player's position is within the button
    virtual bool is_selected_by_player();
};
