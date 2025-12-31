#pragma once
#include "GameObject.h"
#include "HealthPointText.h"
#include <SDL2/SDL_ttf.h>
#include <memory>

struct HelpText : public GameObject {
    std::unique_ptr<TTF_Font, FontDeleter> font;

    HelpText();
    void update() override;
    void render() override;
};
