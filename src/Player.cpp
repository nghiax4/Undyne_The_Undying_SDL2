#include "Player.h"
#include "MenuButton.h"
#include "SelectedMenuButtonContainer.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include "core/Scene.h"
#include <string>
#include <vector>

Player::Player(int x_center, int y_center) : x_center(x_center), y_center(y_center), width(Engine::get().get_screen_width() * 0.03), height(Engine::get().get_screen_width() * 0.03) {
    player_texture = ResourceManager::get().get_texture("sprites/soul.png");
    obj_name = "Player";
    this->z_index = 3;
}

void Player::update() {
    int selected_menu_button = static_cast<SelectedMenuButtonContainer *>(Scene::get().find_object_by_name("SelectedMenuButtonContainer"))->selected_menu_button;

    std::vector<MenuButton *> menu_buttons = {static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_0")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_1")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_2")), static_cast<MenuButton *>(Scene::get().find_object_by_name("Menu_Button_3"))};

    x_center = menu_buttons[selected_menu_button]->x_center - menu_buttons[selected_menu_button]->width / 2 + width;
    y_center = menu_buttons[selected_menu_button]->y_center;
}

void Player::render() {
    Engine::get().draw_texture(player_texture, x_center, y_center, width, height);
}
