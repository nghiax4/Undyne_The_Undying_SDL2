#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include <string>

struct GameObject;

// Define a functor (a struct that acts like a function) to destroy textures
struct TextureDeleter {
    void operator()(SDL_Texture *t) const {
        if (t)
            SDL_DestroyTexture(t);
    }
};

using SmartTexture = std::unique_ptr<SDL_Texture, TextureDeleter>;

SDL_Texture *loadTexture(std::string path);

void _print_all_objs_names();

void _verify_objs_correct();

void _print_objs_names();

void play_sound_effect(std::string path);

double distance(double x1, double y1, double x2, double y2);

int get_random(int low, int high);

double get_random(double low, double high);
