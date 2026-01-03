#pragma once
#include "GameObject.h"

#include "Utils.h"

struct Player_EnemyTurn : public GameObject {
    const double v_x, v_y;
    double x_center, y_center;
    int width, height;
    SmartTexture texture;
    int time_elapsed_since_invisibility_frame = 0;
    bool enable_invisbility_frame = 0;
    // Render transparently for the invisibility frame (it flickers between transparent and opaque)
    bool render_texture_transparent = false;
    int time_elapsed_since_transparent = 0;
    Player_EnemyTurn(int x_center, int y_center);

    virtual void update() override;
    virtual void render() override;
};
