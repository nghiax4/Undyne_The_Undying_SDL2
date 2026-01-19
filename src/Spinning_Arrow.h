#pragma once
#include "GameObject.h"

#include "Utils.h"

struct Spinning_Arrow : public GameObject {
    const double m_radial_speed_pixels_per_ms;
    static constexpr double TRAVEL_DURATION_MS = 1800.0;
    static constexpr double INITIAL_ANGULAR_SPEED_RAD_PER_MS = 0.006;
    static constexpr double FADE_DURATION_MS = 234.0;

    const double m_origin_x, m_origin_y;
    double m_current_radius;
    double m_current_angle_rad;
    double m_initial_radius;
    const double m_radial_speed;

    double m_time_elapsed_since_spawn = 0;

    SmartTexture m_texture;
    bool m_played_sound = false;

    Spinning_Arrow(double origin_x, double origin_y, double start_angle_deg, double start_radius, std::string obj_name);

    void update() override;
    void render() override;
};
