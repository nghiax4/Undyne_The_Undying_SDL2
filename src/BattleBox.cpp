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

    SDL_Rect rect{x_center - width / 2, y_center - height / 2, width, height};
    SDL_Rect inner = {rect.x + BORDER_THICKNESS, rect.y + BORDER_THICKNESS, rect.w - 2 * BORDER_THICKNESS, rect.h - 2 * BORDER_THICKNESS};

    SDL_SetRenderDrawColor(Engine::get().get_renderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(Engine::get().get_renderer(), &rect);

    SDL_SetRenderDrawColor(Engine::get().get_renderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(Engine::get().get_renderer(), &inner);
}
