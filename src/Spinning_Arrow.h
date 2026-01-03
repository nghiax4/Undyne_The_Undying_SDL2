#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Utils.h"

struct Spinning_Arrow : public GameObject {
    const double radial_speed_pixels_per_ms;
    const double TRAVEL_DURATION_MS = 1800.0;
    const double INITIAL_ANGULAR_SPEED_RAD_PER_MS = 0.006;
    const double FADE_DURATION_MS = 234.0;

    double x_center, y_center;
    int width, height;

    const double origin_x, origin_y;
    double current_radius;
    double current_angle_rad;
    double initial_radius;
    const double radial_speed;

    double time_elapsed_since_spawn = 0;

    SDL_Texture *texture;
    bool played_sound = false;

    Spinning_Arrow(double origin_x, double origin_y, double start_angle_deg, double start_radius, std::string obj_name);

    void update() override;
    void render() override;
};
