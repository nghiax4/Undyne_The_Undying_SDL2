#include "Player.h"
#include "MenuButton.h"
#include "SelectedMenuButtonContainer.h"
#include "Utils.h"
#include "core/Engine.h"
#include <string>
#include <vector>

Player::Player(int x_center, int y_center) : width(Engine::get().get_screen_width() * 0.03), height(Engine::get().get_screen_width() * 0.03), x_center(x_center), y_center(y_center) {
    player_texture.reset(loadTexture("sprites/soul.png"));
    obj_name = "Player";
    this->z_index = 3;
}

void Player::update() {
    int selected_menu_button = static_cast<SelectedMenuButtonContainer *>(find_object_by_name("SelectedMenuButtonContainer"))->selected_menu_button;

    std::vector<MenuButton *> menu_buttons = {static_cast<MenuButton *>(find_object_by_name("Menu_Button_0")), static_cast<MenuButton *>(find_object_by_name("Menu_Button_1")), static_cast<MenuButton *>(find_object_by_name("Menu_Button_2")), static_cast<MenuButton *>(find_object_by_name("Menu_Button_3"))};

    x_center = menu_buttons[selected_menu_button]->x_center - menu_buttons[selected_menu_button]->width / 2 + width;
    y_center = menu_buttons[selected_menu_button]->y_center;
}

void Player::render() {
    int left_x = x_center - width / 2;
    int top_y = y_center - height / 2;

    SDL_Rect player_rect = {left_x, top_y, width, height};

    SDL_RenderCopy(Engine::get().get_renderer(), player_texture.get(), NULL, &player_rect);
}
