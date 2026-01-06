#include "BattleBox.h"

#include "core/Engine.h"
#include <SDL2/SDL.h>

BattleBox::BattleBox(int x_center, int y_center, int width, int height) : m_x_center(x_center), m_y_center(y_center), m_width(width), m_height(height) {
    m_obj_name = "BattleBox";
    m_z_index = 2;
}

void BattleBox::update() {}

void BattleBox::render() {
    const int BORDER_THICKNESS = 4;
    // Draw white background
    Engine::get().draw_rect(m_x_center, m_y_center, m_width, m_height, {255, 255, 255, 255}, true);

    // Draw inner black box
    double inner_width = m_width - 2 * BORDER_THICKNESS;
    double inner_height = m_height - 2 * BORDER_THICKNESS;
    Engine::get().draw_rect(m_x_center, m_y_center, static_cast<int>(inner_width), static_cast<int>(inner_height), {0, 0, 0, 255}, true);
}
