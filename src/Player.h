#pragma once
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Player : public GameObject {
    SmartTexture m_player_texture;

    Player(double x_center, double y_center);

    virtual void update() override;

    virtual void render() override;
};
