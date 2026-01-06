#include "HealthPointText.h"
#include "core/Engine.h"
#include <SDL2/SDL_ttf.h>
#include <string>

HealthPointText::HealthPointText(int x_center, int y_center) : m_x_center(x_center), m_y_center(y_center) {
    m_obj_name = "HealthPointText";
    m_font = ResourceManager::get().get_font("fonts/font.ttf", static_cast<int>(Engine::get().get_screen_height() * 0.03));
}

void HealthPointText::update() {}

void HealthPointText::render() {
    SDL_Color color = {255, 255, 255, 0}; // white
    Engine::get().draw_text(m_font, (std::string("HP: ") + std::to_string(m_hp)), m_x_center, m_y_center, color, true);
}
