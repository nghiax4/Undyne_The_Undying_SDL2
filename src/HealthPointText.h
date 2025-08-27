#pragma once
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>

struct HealthPointText : public GameObject {
    int x_center, y_center, font_size;
    TTF_Font *font;
    int hp = 50;

    HealthPointText(int x_center, int y_center);

    void update() override;
    void render() override;
};