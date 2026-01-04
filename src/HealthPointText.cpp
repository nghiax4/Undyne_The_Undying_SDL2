#include "HealthPointText.h"
#include "core/Engine.h"
#include <SDL2/SDL_ttf.h>
#include <string>

HealthPointText::HealthPointText(int x_center, int y_center) : x_center(x_center), y_center(y_center) {
    obj_name = "HealthPointText";
    font = ResourceManager::get().get_font("fonts/font.ttf", Engine::get().get_screen_height() * 0.03);
}

void HealthPointText::update() {}

void HealthPointText::render() {
    SDL_Color color = {255, 255, 255, 0}; // white
    Engine::get().draw_text(font, (std::string("HP: ") + std::to_string(hp)), x_center, y_center, color, true);
}
