#pragma once
#include "GameObject.h"

#include "Utils.h"

struct White_Arrow_Medium_Box_Attack : public GameObject {
    constexpr static double SPRITE_WIDTH_TO_HEIGHT = 60.0 / 196;
    double m_x_center, m_y_center, m_x_target, m_y_target, m_width, m_height;
    double m_dx, m_dy;

    const double m_v_x, m_v_y;

    SmartTexture m_texture;
    Uint32 m_time_elapsed_since_creation = 0;
    Uint32 m_delay_before_charge_ms;

    double m_angle = 0;
    double m_target_angle;

    bool m_played_flying_sound = false;

    White_Arrow_Medium_Box_Attack(int x_center, int y_center, int x_target, int y_target, std::string obj_name, Uint32 delay_before_charge_ms = 1000);

    void update() override;
    void render() override;
};
