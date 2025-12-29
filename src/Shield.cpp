#include "Shield.h"
#include "GameObject.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Utils.h"

Shield::Shield() : width(SCREEN_WIDTH * 0.1), height(SCREEN_HEIGHT * 0.007) {
    texture.reset(loadTexture(renderer, "sprites/shield.png"));
    obj_name = "Shield";
    z_index = 3;
}

void Shield::update() {
    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));

    if (cur_keyboard_state[SDL_SCANCODE_UP]) {
        target_angle = 270;
    }
    if (cur_keyboard_state[SDL_SCANCODE_RIGHT]) {
        target_angle = 0;
    }
    if (cur_keyboard_state[SDL_SCANCODE_DOWN]) {
        target_angle = 90;
    }
    if (cur_keyboard_state[SDL_SCANCODE_LEFT]) {
        target_angle = 180;
    }

    auto mod360 = [](double x) { return std::fmod(std::fmod(x, 360.0) + 360.0, 360.0); };

    double increment_distance = mod360(target_angle - cur_angle);
    double decrement_distance = mod360(cur_angle - target_angle);

    if (increment_distance < decrement_distance) {
        cur_angle += increment_distance * deltaTime * 0.03;
    } else {
        cur_angle -= decrement_distance * deltaTime * 0.03;
    }

    x_center = player->x_center + distance_from_soul * cos(cur_angle * M_PI / 180);
    y_center = player->y_center + distance_from_soul * sin(cur_angle * M_PI / 180);
}

void Shield::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};
    SDL_RenderCopyEx(renderer, texture.get(), NULL, &rect, cur_angle + 90, NULL, SDL_FLIP_NONE);
}
