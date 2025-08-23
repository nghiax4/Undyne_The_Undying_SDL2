#include "Shield.h"
#include "GameObject.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Utils.h"

Shield::Shield() : width(SCREEN_WIDTH * 0.1), height(SCREEN_HEIGHT * 0.007) {
    texture = loadTexture(renderer, "sprites/shield.png");
    obj_name = "Shield";
    z_index = 3;
}

void Shield::update() {
    const int distance_from_soul = SCREEN_HEIGHT * 0.07;
    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));

    if (cur_keyboard_state[SDL_SCANCODE_UP]) {
        state = 0;
    }
    if (cur_keyboard_state[SDL_SCANCODE_RIGHT]) {
        state = 1;
    }
    if (cur_keyboard_state[SDL_SCANCODE_DOWN]) {
        state = 2;
    }
    if (cur_keyboard_state[SDL_SCANCODE_LEFT]) {
        state = 3;
    }

    if (state == 0) {
        x_center = player->x_center;
        y_center = player->y_center - distance_from_soul;
    } else if (state == 1) {
        x_center = player->x_center + distance_from_soul;
        y_center = player->y_center;
    } else if (state == 2) {
        x_center = player->x_center;
        y_center = player->y_center + distance_from_soul;
    } else {
        x_center = player->x_center - distance_from_soul;
        y_center = player->y_center;
    }
}

void Shield::render() {
    bool render_vertical = state == 1 || state == 3;

    int width_2 = width, height_2 = height;
    if (render_vertical) {
        std::swap(width_2, height_2);
    }

    SDL_Rect rect{x_center - width_2 / 2, y_center - height_2 / 2, width_2, height_2};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
