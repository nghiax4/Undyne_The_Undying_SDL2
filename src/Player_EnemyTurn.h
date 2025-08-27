#pragma once
#include "GameObject.h"
#include "Globals.h"

struct Player_EnemyTurn : public GameObject {
    const double v_x = SCREEN_WIDTH * 0.0003, v_y = SCREEN_WIDTH * 0.0003;
    double x_center, y_center;
    int width, height;
    SDL_Texture *texture;
    int time_elapsed_since_invisibility_frame = 0;
    bool enable_invisbility_frame = 0;
    // Render transparently for the invisibility frame (it flickers between transparent and opaque)
    bool render_texture_transparent = false;
    int time_elapsed_since_transparent = 0;
    Player_EnemyTurn(int x_center, int y_center);

    virtual void update() override;
    virtual void render() override;
};