#include "Player_EnemyTurn.h"
#include "BattleBox.h"
#include "Utils.h"

Player_EnemyTurn::Player_EnemyTurn(int x_center, int y_center) : width(SCREEN_WIDTH * 0.03), height(SCREEN_WIDTH * 0.03) {
    texture = loadTexture(renderer, "sprites/soul.png");
    obj_name = "Player_EnemyTurn";
    this->z_index = 3;
}

void Player_EnemyTurn::update() {
    int x_multiplier = 0;
    if (cur_keyboard_state[SDL_SCANCODE_LEFT]) {
        x_multiplier = -1;
    }
    if (cur_keyboard_state[SDL_SCANCODE_RIGHT]) {
        x_multiplier = 1;
    }

    int y_multiplier = 0;
    if (cur_keyboard_state[SDL_SCANCODE_UP]) {
        y_multiplier = -1;
    }
    if (cur_keyboard_state[SDL_SCANCODE_DOWN]) {
        y_multiplier = 1;
    }

    x_center += x_multiplier * v_x * deltaTime;
    y_center += y_multiplier * v_y * deltaTime;

    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));

    x_center = std::max(x_center, (double)(battlebox->x_center - battlebox->width / 2 + width / 2));
    x_center = std::min(x_center, (double)(battlebox->x_center + battlebox->width / 2 - width / 2));

    y_center = std::max(y_center, (double)(battlebox->y_center - battlebox->height / 2 + height / 2));
    y_center = std::min(y_center, (double)(battlebox->y_center + battlebox->height / 2 - height / 2));
}

void Player_EnemyTurn::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}