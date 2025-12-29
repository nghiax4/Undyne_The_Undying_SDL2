#pragma once
#include "GameObject.h"
#include "Globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include <memory>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

// Define a functor (a struct that acts like a function) to destroy textures
struct TextureDeleter {
    void operator()(SDL_Texture *t) const {
        if (t)
            SDL_DestroyTexture(t);
    }
};

using SmartTexture = std::unique_ptr<SDL_Texture, TextureDeleter>;

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

GameObject *find_object_by_name(std::string obj_name);

bool object_by_name_exists(std::string obj_name);

void _print_all_objs_names();

void _remove_objs_that_are_to_be_removed();

void _verify_objs_correct();

void _print_objs_names();

void play_sound_effect(std::string path);

double distance(double x1, double y1, double x2, double y2);

int get_random(int low, int high);

double get_random(double low, double high);