#pragma once
#include "GameObject.h"
#include "HealthPointText.h"
#include "core/ResourceManager.h"
#include <SDL2/SDL_ttf.h>
#include <memory>

struct HelpText : public GameObject {
    SmartFont m_font;

    HelpText();
    void update() override;
    void render() override;
};
