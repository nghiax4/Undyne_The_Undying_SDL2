#pragma once
#include "GameObject.h"
#include "Utils.h"
#include <vector>

struct Undyne : public GameObject {
    const double UNDYNE_SPRITE_WIDTH_OVER_HEIGHT = 314.0 / 246;
    const int MILLISECOND_BETWEEN_SPRITE_FRAME = 30;

    int x_center, y_center, width, height;
    double time_elapsed_since_last_sprite_frame = 0;
    int current_sprite_frame = 0;
    const int NUM_OF_SPRITE_FRAMES = 107;

    std::vector<SmartTexture> sprite_frames;

    Undyne(int x_center, int y_center, int height);

    virtual void update() override;

    virtual void render() override;
};
