#include "HelpText.h"
#include "core/Engine.h"
#include "core/ResourceManager.h"
#include <string>

HelpText::HelpText() {
    obj_name = "HelpText";
    z_index = 1000;

    int font_size = Engine::get().get_screen_height() * 0.05;
    font = ResourceManager::get().get_font("fonts/ui_font.ttf", font_size);
}

void HelpText::update() {}

void HelpText::render() {
    SDL_Color text_color = {255, 255, 255, 0};
    const int ALPHA_TRANSPARENCY = 128; // 0-255, where 128 is ~50% transparent
    const int PADDING_LEFT = 10;
    const int PADDING_TOP = 10;

    Engine::get().draw_text(font, "Keyboard: Arrow keys, Enter key\nTouchscreen: Buttons on screen", PADDING_LEFT, PADDING_TOP, text_color, false, ALPHA_TRANSPARENCY);
}
