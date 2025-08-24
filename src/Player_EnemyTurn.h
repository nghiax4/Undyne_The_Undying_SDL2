#pragma once
#include "GameObject.h"
#include "Globals.h"

struct Player_EnemyTurn : public GameObject {
    const double v_x = SCREEN_WIDTH * 0.0003, v_y = SCREEN_WIDTH * 0.0003;
    double x_center, y_center;
    int width, height;
    SDL_Texture *texture;
    Player_EnemyTurn(int x_center, int y_center);

    virtual void update() override;
    virtual void render() override;
};