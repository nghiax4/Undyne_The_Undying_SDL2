#include "BattleBox.h"

#include "core/Engine.h"
#include <SDL2/SDL.h>

BattleBox::BattleBox(int x_center, int y_center, int width, int height) {
    m_obj_name = "BattleBox";
    m_z_index = 2;

    add_component<Transform>(x_center, y_center, width, height);
}

void BattleBox::update() {}

void BattleBox::render() {
    const int BORDER_THICKNESS = 4;
    Transform *transform = get_component<Transform>();

    // Draw white background
    Engine::get().draw_rect(transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height, {255, 255, 255, 255}, true);

    // Draw inner black box
    double inner_width = transform->m_width - 2 * BORDER_THICKNESS;
    double inner_height = transform->m_height - 2 * BORDER_THICKNESS;
    Engine::get().draw_rect(transform->m_x_center, transform->m_y_center, static_cast<int>(inner_width), static_cast<int>(inner_height), {0, 0, 0, 255}, true);
}
