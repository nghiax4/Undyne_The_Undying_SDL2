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
    size_t selected_menu_button = static_cast<SelectedMenuButtonContainer *>(Scene::get().find_object_by_name("SelectedMenuButtonContainer"))->m_selected_menu_button;

    std::vector<MenuButton *> menu_buttons = {static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_0")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_1")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_2")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_3"))};

    Transform *transform = get_component<Transform>();

    transform->m_x_center = menu_buttons[selected_menu_button]->m_x_center - menu_buttons[selected_menu_button]->m_width / 2 + transform->m_width;
    transform->m_y_center = menu_buttons[selected_menu_button]->m_y_center;
}

void Player::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_player_texture, transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height);
}
