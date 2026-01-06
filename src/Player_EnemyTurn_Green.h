#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Player_EnemyTurn_Green : public GameObject {
    static constexpr double PLAYER_ARROW_COLLISION_DISTANCE = 10;
    double m_x_center, m_y_center, m_width, m_height;
    Uint32 m_time_elapsed_since_invisibility_frame = 0;
    bool m_enable_invisbility_frame = 0;
    // Render transparently for the invisibility frame (it flickers between transparent and opaque)
    bool m_render_texture_transparent = false;
    Uint32 m_time_elapsed_since_transparent = 0;

    SmartTexture m_texture;

    Player_EnemyTurn_Green(int x_center, int y_center);

    virtual void update() override;

    virtual void render() override;
};
