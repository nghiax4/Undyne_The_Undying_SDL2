#pragma once
#include "GameObject.h"
#include "core/ResourceManager.h"
#include <SDL2/SDL_ttf.h>
#include <memory>

struct HealthPointText : public GameObject {
    int m_x_center, m_y_center, m_font_size;
    SmartFont m_font;
    int m_hp = 50;

    HealthPointText(int x_center, int y_center);

    void update() override;
    void render() override;
};
