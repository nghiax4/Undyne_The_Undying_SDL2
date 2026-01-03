#include "MenuButton.h"
#include "Player.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"

MenuButton::MenuButton(int x_center, int y_center, int width, int height, std::string sprite_unselected_path, std::string sprite_selected_path, int button_index) : x_center(x_center), y_center(y_center), width(width), height(height), sprite_unselected_path(sprite_unselected_path), sprite_selected_path(sprite_selected_path) {
    obj_name = "Menu_Button_" + std::to_string(button_index);
    texture_unselected_obj.reset(loadTexture(sprite_unselected_path));
    texture_selected_obj.reset(loadTexture(sprite_selected_path));
}

void MenuButton::update() {}

void MenuButton::render() {
    int left_x = x_center - width / 2;
    int top_y = y_center - height / 2;

    SDL_Texture *texture_to_draw = is_selected_by_player() ? texture_selected_obj.get() : texture_unselected_obj.get();
    SDL_Rect button_rect = {left_x, top_y, width, height};

    SDL_RenderCopy(Engine::get().get_renderer(), texture_to_draw, NULL, &button_rect);
}

// Check if the button is currently selected by checking if the player's position is within the button
bool MenuButton::is_selected_by_player() {
    if (!Scene::get().object_exists("Player")) {
        return false;
    }

    Player *player = static_cast<Player *>(Scene::get().find_object_by_name("Player"));
    bool x_within = x_center - width / 2 <= player->x_center && player->x_center <= x_center + width / 2;
    bool y_within = y_center - height / 2 <= player->y_center && player->y_center <= y_center + height / 2;
    return x_within && y_within;
}
