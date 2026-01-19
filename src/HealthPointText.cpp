#include "HealthPointText.h"
#include "core/Engine.h"
#include <SDL2/SDL_ttf.h>
#include <string>

HealthPointText::HealthPointText(int x_center, int y_center) {
    m_obj_name = "HealthPointText";
    m_font = ResourceManager::get().get_font("fonts/font.ttf", static_cast<int>(Engine::SCREEN_HEIGHT * 0.03));
    add_component<Transform>(x_center, y_center, 0, 0);
}

void HealthPointText::update() {}

void HealthPointText::render() {
    SDL_Color color = {255, 255, 255, 0}; // white
    Transform *transform = get_component<Transform>();
    Engine::get().draw_text(m_font, (std::string("HP: ") + std::to_string(m_hp)), transform->m_x_center, transform->m_y_center, color, true);
}
