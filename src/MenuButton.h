#pragma once
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <string>

struct MenuButton : public GameObject {
  public:
    SDL_Texture *button_texture;
    int x_center, y_center, width, height;
    std::string sprite_unselected, sprite_selected;

    MenuButton(int x_center, int y_center, int width, int height, std::string sprite_unselected, std::string sprite_selected, int button_index);

    virtual void update() override;

    virtual void render() override;

    // Check if the button is currently selected by checking if the player's position is within the button
    virtual bool is_selected_by_player();
};