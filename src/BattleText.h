#pragma once
#include "GameObject.h"
#include "HealthPointText.h" // Reuse FontDeleter
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>

struct BattleText : public GameObject {
    std::string full_text = "* The heroine appears.";
    const double TOTAL_DURATION_MS = 669.0;
    
    double time_elapsed_since_spawn = 0;
    std::unique_ptr<TTF_Font, FontDeleter> font;

    BattleText();
    void update() override;
    void render() override;
};
