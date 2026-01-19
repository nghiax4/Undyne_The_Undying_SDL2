#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Shield : public GameObject {
    const double m_distance_from_soul;
    double m_cur_angle = 0, m_target_angle = 0;
    SmartTexture m_texture;

    Shield();

    virtual void update() override;

    virtual void render() override;
};
