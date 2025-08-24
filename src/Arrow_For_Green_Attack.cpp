#include "Arrow_For_Green_Attack.h"
#include "Shield.h"
#include "Utils.h"

Arrow_For_Green_Attack::Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name) : x_center(x_center), y_center(y_center), v_x(v_x), v_y(v_y), direction(direction) {
    height = SCREEN_HEIGHT * 0.06;
    width = height * SPRITE_WIDTH_TO_HEIGHT_RATIO;

    this->obj_name = obj_name;
    texture = loadTexture(renderer, "sprites/down_arrow.png");
    z_index = 4;
}

void Arrow_For_Green_Attack::update() {
    x_center += v_x * deltaTime;
    y_center += v_y * deltaTime;

    if (object_by_name_exists("Shield")) {
        Shield *shield = static_cast<Shield *>(find_object_by_name("Shield"));

        if (distance(x_center, y_center, shield->x_center, shield->y_center) <= 20) {
            play_sound_effect("audio/shield_reflect.mp3");
            this->to_be_removed = true;
        }
    }
}

void Arrow_For_Green_Attack::render() {
    SDL_Rect rect{x_center - width / 2, y_center - height / 2, width, height};

    int angle;
    if (direction == Direction::DOWN) {
        angle = 0;
    }
    if (direction == Direction::RIGHT) {
        angle = 270;
    }
    if (direction == Direction::UP) {
        angle = 180;
    }
    if (direction == Direction::LEFT) {
        angle = 90;
    }

    SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}