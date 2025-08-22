#include "Player.h"
#include "MenuButton.h"
#include "SelectedMenuButtonContainer.h"
#include "Utils.h"
#include <string>

extern SDL_Renderer *renderer;

Player::Player(int x_center, int y_center, int width, int height, std::string path, int z_index) : width(width), height(height), x_center(x_center), y_center(y_center) {
    player_texture = loadTexture(renderer, path.c_str());
    obj_name = "Player";
    this->z_index = z_index;
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

    SDL_Rect *player_rect = new SDL_Rect({left_x, top_y, width, height});

    SDL_RenderCopy(renderer, player_texture, NULL, player_rect);
}