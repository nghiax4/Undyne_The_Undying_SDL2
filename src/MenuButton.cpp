#include "MenuButton.h"
#include "Player.h"
#include "Utils.h"

extern SDL_Renderer *renderer;

MenuButton::MenuButton(int x_center, int y_center, int width, int height, std::string sprite_unselected, std::string sprite_selected, int button_index) : width(width), height(height), x_center(x_center), y_center(y_center), sprite_unselected(sprite_unselected), sprite_selected(sprite_selected) { obj_name = "Menu_Button_" + std::to_string(button_index); }

void MenuButton::update() {}

void MenuButton::render() {
    int left_x = x_center - width / 2;
    int top_y = y_center - height / 2;

    button_texture = loadTexture(renderer, is_selected_by_player() ? sprite_selected : sprite_unselected);
    SDL_Rect *button_rect = new SDL_Rect({left_x, top_y, width, height});

    SDL_RenderCopy(renderer, button_texture, NULL, button_rect);
}

// Check if the button is currently selected by checking if the player's position is within the button
bool MenuButton::is_selected_by_player() {
    Player *player = static_cast<Player *>(find_object_by_name("Player"));
    bool x_within = x_center - width / 2 <= player->x_center && player->x_center <= x_center + width / 2;
    bool y_within = y_center - height / 2 <= player->y_center && player->y_center <= y_center + height / 2;
    return x_within && y_within;
}