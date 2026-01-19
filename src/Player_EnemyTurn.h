#pragma once
#include "GameObject.h"

#include "Utils.h"

struct Player_EnemyTurn : public GameObject {
    const double m_v_x, m_v_y;

    SmartTexture m_texture;
    Uint32 m_time_elapsed_since_invisibility_frame = 0;
    bool m_enable_invisbility_frame = 0;

    // Render transparently for the invisibility frame (it flickers between transparent and opaque)
    bool m_render_texture_transparent = false;
    Uint32 m_time_elapsed_since_transparent = 0;

    Player_EnemyTurn(double x_center, double y_center);

    virtual void update() override;
    virtual void render() override;
};
