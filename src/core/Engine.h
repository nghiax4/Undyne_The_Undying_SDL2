#pragma once
#include "ResourceManager.h"
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

    void init(const std::string &title);
    void cleanup();
    void clear_screen();
    void present_screen();

    void draw_texture(const SmartTexture &tex, double x_center, double y_center, double width, double height, double angle_deg = 0, Uint8 alpha = 255);
    void draw_rect(double x_center, double y_center, double width, double height, SDL_Color color, bool filled);
    void draw_text(const SmartFont &font, const std::string &text, double x, double y, SDL_Color color, bool center, Uint8 alpha = 255);

    SDL_Renderer *get_renderer() const;
    double get_screen_width() const;
    double get_screen_height() const;
    Uint32 get_delta_time() const;
    void update_time();

    // Prevent cloning
    Engine(const Engine &) = delete;
    void operator=(const Engine &) = delete;

    static constexpr double SCREEN_WIDTH = 800;
    static constexpr double SCREEN_HEIGHT = 600;

  private:
    Engine() = default;

    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    Uint32 m_last_tick = 0;
    Uint32 m_delta_time = 0.0;
};
