#include "BattleBox.h"

#include "core/Engine.h"
#include <SDL2/SDL.h>

BattleBox::BattleBox(int x_center, int y_center, int width, int height) : x_center(x_center), y_center(y_center), width(width), height(height) {
    obj_name = "BattleBox";
    z_index = 2;
}

void BattleBox::update() {}

void BattleBox::render() {
    const int BORDER_THICKNESS = 4;
    // Draw white background
    Engine::get().draw_rect(x_center, y_center, width, height, {255, 255, 255, 255}, true);

    // Draw inner black box
    int inner_width = width - 2 * BORDER_THICKNESS;
    int inner_height = height - 2 * BORDER_THICKNESS;
    Engine::get().draw_rect(x_center, y_center, inner_width, inner_height, {0, 0, 0, 255}, true);
}
