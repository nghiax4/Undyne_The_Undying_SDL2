#include "MenuButton.h"
#include "Player.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"

MenuButton::MenuButton(double x_center, double y_center, double width, double height, std::string sprite_unselected_path, std::string sprite_selected_path, int button_index) {
    m_obj_name = "Menu_Button_" + std::to_string(button_index);
    m_texture_unselected_obj = ResourceManager::get().get_texture(sprite_unselected_path);
    m_texture_selected_obj = ResourceManager::get().get_texture(sprite_selected_path);

    add_component<Transform>(x_center, y_center, width, height);
}

void MenuButton::update() {}

void MenuButton::render() {
    SmartTexture texture = is_selected_by_player() ? m_texture_selected_obj : m_texture_unselected_obj;
    Transform *transform = get_component<Transform>();

    Engine::get().draw_texture(texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height);
}

// Check if the button is currently selected by checking if the player's position is within the button
bool MenuButton::is_selected_by_player() {
    if (!Scene::get().object_exists("Player")) {
        return false;
    }

    Player *player = static_cast<Player *>(Scene::get().find_object_by_name("Player"));
    Transform *transform = get_component<Transform>();
    Transform *player_transform = player->get_component<Transform>();

    bool x_within = transform->m_x_center - transform->m_width / 2 <= player_transform->m_x_center && player_transform->m_x_center <= transform->m_x_center + transform->m_width / 2;
    bool y_within = transform->m_y_center - transform->m_height / 2 <= player_transform->m_y_center && player_transform->m_y_center <= transform->m_y_center + transform->m_height / 2;

    return x_within && y_within;
}
