#pragma once
#include "GameObject.h"
#include "Utils.h"
#include <vector>
#include <utility>

struct VirtualController : public GameObject {
    SmartTexture m_arrow_texture;
    SmartTexture m_enter_texture;

    struct ButtonMapping {
        SDL_Rect m_screen_area;
        double m_rotation_angle_deg;
        SDL_Scancode m_scancode_target;
        bool m_is_enter_key;
    };

    std::vector<ButtonMapping> m_buttons;

    VirtualController();

    void update() override;
    void render() override;
};
