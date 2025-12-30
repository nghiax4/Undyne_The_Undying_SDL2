#pragma once
#include "GameObject.h"
#include "Utils.h"
#include <vector>
#include <utility>

struct VirtualController : public GameObject {
    SmartTexture arrow_texture;
    SmartTexture enter_texture;

    struct ButtonMapping {
        SDL_Rect screen_area;
        double rotation_angle_deg;
        SDL_Scancode scancode_target;
        bool is_enter_key;
    };

    std::vector<ButtonMapping> buttons;

    VirtualController();

    void update() override;
    void render() override;
};
