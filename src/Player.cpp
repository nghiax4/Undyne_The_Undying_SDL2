#include "Player.h"
#include "MenuButton.h"
#include "SelectedMenuButtonContainer.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"
#include <string>
#include <vector>

Player::Player(double x_center, double y_center) {
    m_player_texture = ResourceManager::get().get_texture("sprites/soul.png");
    m_obj_name = "Player";
    m_z_index = 3;

    add_component<Transform>(x_center, y_center, Engine::SCREEN_WIDTH * 0.03, Engine::SCREEN_WIDTH * 0.03);
}

void Player::update() {
    size_t selected_menu_button_index = static_cast<SelectedMenuButtonContainer *>(Scene::get().find_object_by_name("SelectedMenuButtonContainer"))->m_selected_menu_button;

    assert(0 <= selected_menu_button_index && selected_menu_button_index < 4);

    MenuButton *selected_menu_button = static_cast<MenuButton *>(Scene::get().find_object_by_name(std::string("Menu_Button_") + std::to_string(selected_menu_button_index)));

    Transform *transform = get_component<Transform>();
    Transform *button_transform = selected_menu_button->get_component<Transform>();

    transform->m_x_center = button_transform->m_x_center - button_transform->m_width / 2 + transform->m_width;
    transform->m_y_center = button_transform->m_y_center;
}

void Player::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_player_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height);
}
