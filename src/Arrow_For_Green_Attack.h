#pragma once
#include "GameObject.h"
#include "GameplayTypes.h"
#include "Utils.h"

struct Arrow_For_Green_Attack : public GameObject {
    static constexpr double SPRITE_WIDTH_TO_HEIGHT_RATIO = 43.0 / 83;
    static constexpr double DISTANCE_FROM_SOUL_TO_FLIP = 150.0;
    static constexpr double ROTATION_SPEED_DEGREE_PER_MS = 0.7;

    double m_v_x, m_v_y;
    Direction m_direction;
    ArrowType m_arrow_type;

    enum class State { APPROACHING_BEFORE_ROTATE,
                       ROTATING,
                       APPROACHING_AFTER_ROTATE };
    State m_state = State::APPROACHING_BEFORE_ROTATE;

    // Orbit variables for rotating the yellow arrow
    double m_orbit_angle_deg = 0;
    double m_target_orbit_angle_deg = 0;
    double m_orbit_radius = 0;
    bool m_clockwise_rotation = true;

    SmartTexture m_texture;

    Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name, ArrowType arrow_type);
    virtual void update() override;
    virtual void render() override;
};
