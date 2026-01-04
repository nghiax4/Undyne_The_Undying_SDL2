#include "Engine.h"
#include <cstdio>

void Engine::init(const std::string &title, int width, int height) {
    assert(window == nullptr && "Engine already initialized");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        throw std::runtime_error("Mix_OpenAudio Error: " + std::string(Mix_GetError()));
    }
    if (TTF_Init() == -1) {
        throw std::runtime_error("TTF_Init Error: " + std::string(TTF_GetError()));
    }

    screen_width = width;
    screen_height = height;

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    assert(window != nullptr);

    renderer = SDL_CreateRenderer(window, -1, 0);
    assert(renderer != nullptr);

    last_tick = SDL_GetTicks();
}

void Engine::cleanup() {
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

void Engine::clear_screen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Engine::present_screen() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer *Engine::get_renderer() const {
    assert(renderer != nullptr);
    return renderer;
}

int Engine::get_screen_width() const {
    return screen_width;
}
int Engine::get_screen_height() const {
    return screen_height;
}

void Engine::update_time() {
    Uint32 now = SDL_GetTicks();
    delta_time = now - last_tick;
    last_tick = now;
}

double Engine::get_delta_time() const {
    return delta_time;
}

void Engine::draw_texture(const SmartTexture &tex, double x_center, double y_center, double width, double height, double angle_deg, Uint8 alpha) {
    assert(tex.get() != nullptr);
    assert(width > 0 && height > 0);

    SDL_Rect destination_rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};

    SDL_SetTextureBlendMode(tex.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tex.get(), alpha);
    SDL_RenderCopyEx(renderer, tex.get(), nullptr, &destination_rect, angle_deg, nullptr, SDL_FLIP_NONE);
}

void Engine::draw_rect(double x_center, double y_center, double width, double height, SDL_Color color, bool filled) {
    assert(width > 0 && height > 0);

    SDL_Rect destination_rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    if (filled) {
        SDL_RenderFillRect(renderer, &destination_rect);
    } else {
        SDL_RenderDrawRect(renderer, &destination_rect);
    }
}

void Engine::draw_text(const SmartFont &font, const std::string &text, double x, double y, SDL_Color color, bool center, Uint8 alpha) {
    assert(font.get() != nullptr);
    assert(!text.empty());

    // the TTF function may return NULL if text is empty
    SDL_Surface *surface = TTF_RenderText_Blended(font.get(), text.c_str(), color);

    assert(surface != nullptr);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, alpha);

    assert(texture != nullptr);

    SDL_Rect destination_rect;
    if (center) {
        // (x, y) is the center coordinate
        destination_rect = SDL_Rect{(int)(x - surface->w / 2), (int)(y - surface->h / 2), surface->w, surface->h};
    } else {
        // (x, y) is the top-left coordinate
        destination_rect = SDL_Rect{(int)x, (int)y, surface->w, surface->h};
    }

    SDL_RenderCopy(renderer, texture, nullptr, &destination_rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
