#pragma once
#include "GameObject.h"
#include "HealthPointText.h" // Reuse FontDeleter
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>

struct BattleText : public GameObject {
    static constexpr std::string_view m_full_text = "* The heroine appears.";
    static constexpr double TOTAL_DURATION_MS = 669.0;

    double m_time_elapsed_since_spawn = 0;
    SmartFont m_font;

    BattleText();
    void update() override;
    void render() override;
};
