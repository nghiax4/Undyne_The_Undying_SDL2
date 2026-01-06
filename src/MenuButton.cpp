#include "MenuButton.h"
#include "Player.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"

MenuButton::MenuButton(double x_center, double y_center, double width, double height, std::string sprite_unselected_path, std::string sprite_selected_path, int button_index) : m_x_center(x_center), m_y_center(y_center), m_width(width), m_height(height), m_sprite_unselected_path(sprite_unselected_path), m_sprite_selected_path(sprite_selected_path) {
    m_obj_name = "Menu_Button_" + std::to_string(button_index);
    m_texture_unselected_obj = ResourceManager::get().get_texture(sprite_unselected_path);
    m_texture_selected_obj = ResourceManager::get().get_texture(sprite_selected_path);
}

void MenuButton::update() {}

void MenuButton::render() {
    SmartTexture texture = is_selected_by_player() ? m_texture_selected_obj : m_texture_unselected_obj;

    Engine::get().draw_texture(texture, m_x_center, m_y_center, m_width, m_height);
}

// Check if the button is currently selected by checking if the player's position is within the button
bool MenuButton::is_selected_by_player() {
    if (!Scene::get().object_exists("Player")) {
        return false;
    }

    Player *player = static_cast<Player *>(Scene::get().find_object_by_name("Player"));
    bool x_within = m_x_center - m_width / 2 <= player->m_x_center && player->m_x_center <= m_x_center + m_width / 2;
    bool y_within = m_y_center - m_height / 2 <= player->m_y_center && player->m_y_center <= m_y_center + m_height / 2;
    return x_within && y_within;
}
