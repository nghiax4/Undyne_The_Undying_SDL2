#include "HelpText.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include <string>

HelpText::HelpText() {
    m_obj_name = "HelpText";
    m_z_index = 1000;

    m_font = ResourceManager::get().get_font("fonts/ui_font.ttf", static_cast<int>(Engine::get().get_screen_height() * 0.05));
}

void HelpText::update() {}

void HelpText::render() {
    constexpr SDL_Color text_color = {255, 255, 255, 0};
    constexpr int ALPHA_TRANSPARENCY = 128; // 0-255, where 128 is ~50% transparent
    constexpr int PADDING_LEFT = 10;
    constexpr int PADDING_TOP = 10;

    Engine::get().draw_text(m_font, "Keyboard: Arrow keys, Enter key\nTouchscreen: Buttons on screen", PADDING_LEFT, PADDING_TOP, text_color, false, ALPHA_TRANSPARENCY);
}
