#pragma once
#include "GameObject.h"
#include "Utils.h"
#include <vector>

struct Undyne : public GameObject {
    static constexpr double UNDYNE_SPRITE_WIDTH_OVER_HEIGHT = 314.0 / 246;
    static constexpr int MILLISECOND_BETWEEN_SPRITE_FRAME = 30;

    Uint32 m_time_elapsed_since_last_sprite_frame = 0;
    size_t m_current_sprite_frame = 0;
    static constexpr int NUM_OF_SPRITE_FRAMES = 107;

    std::vector<SmartTexture> m_sprite_frames;

    Undyne(double x_center, double y_center, double height);

    virtual void update() override;

    virtual void render() override;
};
