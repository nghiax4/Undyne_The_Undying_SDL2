#include "MenuButton.h"
#include "Player.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"

MenuButton::MenuButton(int x_center, int y_center, int width, int height, std::string sprite_unselected_path, std::string sprite_selected_path, int button_index) : x_center(x_center), y_center(y_center), width(width), height(height), sprite_unselected_path(sprite_unselected_path), sprite_selected_path(sprite_selected_path) {
    obj_name = "Menu_Button_" + std::to_string(button_index);
    texture_unselected_obj = ResourceManager::get().get_texture(sprite_unselected_path);
    texture_selected_obj = ResourceManager::get().get_texture(sprite_selected_path);
}

void MenuButton::update() {}

void MenuButton::render() {
    SmartTexture texture = is_selected_by_player() ? texture_selected_obj : texture_unselected_obj;

    Engine::get().draw_texture(texture, x_center, y_center, width, height);
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
