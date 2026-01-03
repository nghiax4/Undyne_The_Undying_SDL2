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
