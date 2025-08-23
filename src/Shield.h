#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Shield : public GameObject {
    int x_center, y_center, width, height;
    SDL_Texture *texture;
    int state = 0; // 0 is up, 1 is right, 2 is down, 3 is left

    Shield();

    virtual void update() override;

    virtual void render() override;
};