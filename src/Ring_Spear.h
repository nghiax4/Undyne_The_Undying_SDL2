#pragma once
#include "GameObject.h"

#include "Utils.h"

struct Ring_Spear : public GameObject {
    static constexpr double SPIN_DURATION_MS = 567.0;
    static constexpr double LOCK_DURATION_MS = 200.0;
    static constexpr double TRAVEL_DURATION_MS = 434.0;

    double m_origin_x, m_origin_y;
    double m_current_radius;
    double m_current_angle_rad;
    Uint32 m_time_alive = 0;
    double m_charge_speed;

    SmartTexture m_texture;

    Ring_Spear(double x, double y, double angle_deg, double radius, std::string name);

    void update() override;
    void render() override;
};
