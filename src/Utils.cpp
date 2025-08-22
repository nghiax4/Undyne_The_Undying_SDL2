#include "GameObject.h"
#include "Globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path) {
    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

GameObject *find_object_by_name(std::string obj_name) {
    for (auto &obj : objs) {
        if (obj->obj_name == obj_name) {
            return obj;
        }
    }

    throw std::runtime_error("Cannot find object with name " + obj_name);
}