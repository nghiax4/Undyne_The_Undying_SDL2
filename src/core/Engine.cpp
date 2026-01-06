#include "Engine.h"
#include <cstdio>

void Engine::init(const std::string &title) {
    assert(m_window == nullptr && "Engine already initialized");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        throw std::runtime_error("Mix_OpenAudio Error: " + std::string(Mix_GetError()));
    }
    if (TTF_Init() == -1) {
        throw std::runtime_error("TTF_Init Error: " + std::string(TTF_GetError()));
    }

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT), SDL_WINDOW_SHOWN);
    assert(m_window != nullptr);

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    assert(m_renderer != nullptr);

    m_last_tick = SDL_GetTicks();
}

void Engine::cleanup() {
    if (m_renderer)
        SDL_DestroyRenderer(m_renderer);
    if (m_window)
        SDL_DestroyWindow(m_window);
    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Engine::clear_screen() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

void Engine::present_screen() {
    SDL_RenderPresent(m_renderer);
}

SDL_Renderer *Engine::get_renderer() const {
    assert(m_renderer != nullptr);
    return m_renderer;
}

void Engine::update_time() {
    Uint32 now = SDL_GetTicks();
    m_delta_time = now - m_last_tick;
    m_last_tick = now;
}

Uint32 Engine::get_delta_time() const {
    return m_delta_time;
}

void Engine::draw_texture(const SmartTexture &tex, double x_center, double y_center, double width, double height, double angle_deg, Uint8 alpha) {
    assert(tex.get() != nullptr);
    assert(width > 0 && height > 0);

    SDL_Rect destination_rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};

    SDL_SetTextureBlendMode(tex.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tex.get(), alpha);
    SDL_RenderCopyEx(m_renderer, tex.get(), nullptr, &destination_rect, angle_deg, nullptr, SDL_FLIP_NONE);
}

void Engine::draw_rect(double x_center, double y_center, double width, double height, SDL_Color color, bool filled) {
    assert(width > 0 && height > 0);

    SDL_Rect destination_rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    if (filled) {
        SDL_RenderFillRect(m_renderer, &destination_rect);
    } else {
        SDL_RenderDrawRect(m_renderer, &destination_rect);
    }
}

void Engine::draw_text(const SmartFont &font, const std::string &text, double x, double y, SDL_Color color, bool center, Uint8 alpha) {
    assert(font.get() != nullptr);
    assert(!text.empty());

    // the TTF function may return NULL if text is empty
    SDL_Surface *surface = TTF_RenderText_Blended(font.get(), text.c_str(), color);

    assert(surface != nullptr);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
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

    SDL_RenderCopy(m_renderer, texture, nullptr, &destination_rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
