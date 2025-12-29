#pragma once
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>
#include <memory>

struct FontDeleter {
    void operator()(TTF_Font *font) const {
        if (font)
            TTF_CloseFont(font);
    }
};

struct HealthPointText : public GameObject {
    int x_center, y_center, font_size;
    std::unique_ptr<TTF_Font, FontDeleter> font;
    int hp = 50;

    HealthPointText(int x_center, int y_center);

    void update() override;
    void render() override;
};
