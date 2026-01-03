#include "HealthPointText.h"
#include "GameObject.h"
#include "Globals.h"
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
    SDL_Surface *surface = TTF_RenderText_Blended(font.get(), (std::string("HP: ") + std::to_string(hp)).c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Engine::get().get_renderer(), surface);

    int width = surface->w;
    int height = surface->h;
    SDL_Rect dstRect = {x_center - width / 2, y_center - height / 2, width, height};
    SDL_RenderCopy(Engine::get().get_renderer(), texture, NULL, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
