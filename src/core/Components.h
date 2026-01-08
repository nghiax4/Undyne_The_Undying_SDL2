#pragma once
#include <string>

struct Component {
    virtual ~Component() = default;
};

struct Transform : public Component {
    double m_x_center = 0.0;
    double m_y_center = 0.0;
    double m_width = 0.0;
    double m_height = 0.0;
    double m_angle = 0.0;

    Transform(double x_center, double y_center, double width, double height, double angle = 0.0) : m_x_center(x_center), m_y_center(y_center), m_width(width), m_height(height), m_angle(angle) {}
};
