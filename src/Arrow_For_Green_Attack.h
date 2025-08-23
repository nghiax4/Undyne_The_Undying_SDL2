#pragma once
#include "GameObject.h"
#include "Globals.h"

struct Arrow_For_Green_Attack : public GameObject {
    const double SPRITE_WIDTH_TO_HEIGHT_RATIO = 43.0 / 83;
    double x_center, y_center, v_x, v_y;
    int width, height;
    Direction direction;
    SDL_Texture *texture;
    Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name);
    virtual void update() override;
    virtual void render() override;
};