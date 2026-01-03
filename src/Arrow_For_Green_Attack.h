#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Utils.h"

struct Arrow_For_Green_Attack : public GameObject {
    const double SPRITE_WIDTH_TO_HEIGHT_RATIO = 43.0 / 83;
    const double DISTANCE_FROM_SOUL_TO_FLIP = 150.0;
    constexpr static double ROTATION_SPEED_DEGREE_PER_MS = 0.7;

    double x_center, y_center, v_x, v_y;
    int width, height;
    Direction direction;
    ArrowType arrow_type;

    enum class State { APPROACHING_BEFORE_ROTATE,
                       ROTATING,
                       APPROACHING_AFTER_ROTATE };
    State state = State::APPROACHING_BEFORE_ROTATE;

    // Orbit variables for rotating the yellow arrow
    double orbit_angle_deg = 0;
    double target_orbit_angle_deg = 0;
    double orbit_radius = 0;
    bool clockwise_rotation = true;

    // Dont use SmartTexture here or it will delete the cached texture when the arrow dies
    // Same applies to other projectiles
    SmartTexture texture;

    Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name, ArrowType arrow_type);
    virtual void update() override;
    virtual void render() override;
};
