#include "Shield.h"
#include "GameObject.h"
#include "Globals.h"
#include "Player_EnemyTurn_Green.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include "core/Input.h"

Shield::Shield() : width(Engine::get().get_screen_width() * 0.1), height(Engine::get().get_screen_height() * 0.007), distance_from_soul(Engine::get().get_screen_height() * 0.07) {
    texture = loadTexture("sprites/shield.png");
    obj_name = "Shield";
    z_index = 3;
}

void Shield::update() {
    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(Scene::get().find_object_by_name("Player_EnemyTurn_Green"));

    if (Input::get().is_key_down(SDL_SCANCODE_UP)) {
        target_angle = 270;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_RIGHT)) {
        target_angle = 0;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_DOWN)) {
        target_angle = 90;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_LEFT)) {
        target_angle = 180;
    }

    auto mod360 = [](double x) {
        return std::fmod(std::fmod(x, 360.0) + 360.0, 360.0);
    };

    double increment_distance = mod360(target_angle - cur_angle);
    double decrement_distance = mod360(cur_angle - target_angle);

    if (increment_distance < decrement_distance) {
        cur_angle += increment_distance * Engine::get().get_delta_time() * 0.03;
    } else {
        cur_angle -= decrement_distance * Engine::get().get_delta_time() * 0.03;
    }

    x_center = player->x_center + distance_from_soul * cos(cur_angle * M_PI / 180);
    y_center = player->y_center + distance_from_soul * sin(cur_angle * M_PI / 180);
}

void Shield::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};
    SDL_RenderCopyEx(Engine::get().get_renderer(), texture, NULL, &rect, cur_angle + 90, NULL, SDL_FLIP_NONE);
}
