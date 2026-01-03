#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Player_EnemyTurn_Green : public GameObject {
    constexpr static double PLAYER_ARROW_COLLISION_DISTANCE = 10;
    int x_center, y_center, width, height;
    int time_elapsed_since_invisibility_frame = 0;
    bool enable_invisbility_frame = 0;
    // Render transparently for the invisibility frame (it flickers between transparent and opaque)
    bool render_texture_transparent = false;
    int time_elapsed_since_transparent = 0;

    SmartTexture texture;

    Player_EnemyTurn_Green(int x_center, int y_center);

    virtual void update() override;

    virtual void render() override;
};
