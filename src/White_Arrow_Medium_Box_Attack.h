#pragma once
#include "GameObject.h"
#include "Globals.h"

struct White_Arrow_Medium_Box_Attack : public GameObject {
    const double SPRITE_WIDTH_TO_HEIGHT = 60.0 / 196;
    int x_center, y_center, x_target, y_target, width, height;
    double dx, dy;

    const double v_x = SCREEN_WIDTH * 0.0008, v_y = SCREEN_HEIGHT * 0.0008;

    SDL_Texture *texture;
    int time_elapsed_since_creation = 0;

    double angle = 0;
    double target_angle;

    bool played_flying_sound = false;

    White_Arrow_Medium_Box_Attack(int x_center, int y_center, int x_target, int y_target, std::string obj_name);

    void update() override;
    void render() override;
};