#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Utils.h"

struct Ring_Spear : public GameObject {
    const double SPIN_DURATION_MS = 567.0;
    const double LOCK_DURATION_MS = 200.0;
    const double TRAVEL_DURATION_MS = 434.0;

    double x_center, y_center;
    double origin_x, origin_y;
    double current_radius;
    double current_angle_rad;
    double time_alive = 0;
    double charge_speed;

    SDL_Texture *texture;
    int width, height;

    Ring_Spear(double x, double y, double angle_deg, double radius, std::string name);

    void update() override;
    void render() override;
};