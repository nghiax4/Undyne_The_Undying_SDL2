#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <cassert>
#include <stdexcept>
#include <string>

class Engine {
  public:
    static Engine &get() {
        static Engine instance;
        return instance;
    }

    void init(const std::string &title, int width, int height);
    void cleanup();
    void clear_screen();
    void present_screen();

    SDL_Renderer *get_renderer() const;
    int get_screen_width() const;
    int get_screen_height() const;
    double get_delta_time() const;
    void update_time();

    // Prevent cloning
    Engine(const Engine &) = delete;
    void operator=(const Engine &) = delete;

  private:
    Engine() = default;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int screen_width = 0;
    int screen_height = 0;

    Uint32 last_tick = 0;
    double delta_time = 0.0;
};
