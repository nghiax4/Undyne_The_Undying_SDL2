#include "BattleBox.h"
#include "Globals.h"
#include <SDL2/SDL.h>

BattleBox::BattleBox(int x_center, int y_center, int width, int height) : x_center(x_center), y_center(y_center), width(width), height(height) { obj_name = "BattleBox"; }

void BattleBox::update() {}

void BattleBox::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect rect{x_center - width / 2, y_center - height / 2, width, height};
    SDL_RenderDrawRect(renderer, &rect);
}