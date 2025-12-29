#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Shield : public GameObject {
    double x_center, y_center;
    int width, height;
    const double distance_from_soul = SCREEN_HEIGHT * 0.07;
    double cur_angle = 0, target_angle = 0;
    SmartTexture texture;

    Shield();

    virtual void update() override;

    virtual void render() override;
};
