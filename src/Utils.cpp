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

void _print_all_objs_names() {
    printf("All objects names:\n");
    for (const auto &obj : objs) {
        printf("- %s\n", obj->obj_name.c_str());
    }
    printf("\n");
}

void _remove_objs_that_are_to_be_removed() {
    std::vector<GameObject *> new_objs;
    for (const auto &obj : objs) {
        if (!obj->to_be_removed) {
            new_objs.push_back(obj);
        }
    }

    objs = new_objs;
}

void _verify_objs_correct() {
    for (int i = 0; i < objs.size(); i++) {
        if (objs[i]->obj_name.empty()) {
            throw std::runtime_error("Obj at index " + std::to_string(i) + " have empty name");
        }
    }

    for (int i = 0; i < objs.size(); i++) {
        for (int j = i + 1; j < objs.size(); j++) {
            if (objs[i]->obj_name == objs[j]->obj_name) {
                throw std::runtime_error("Obj at index " + std::to_string(i) + " and " + std::to_string(j) + " have same name");
            }
        }
    }
}

void _print_objs_names() {
    printf("[");
    for (const auto &obj : objs) {
        printf("'%s', ", obj->obj_name.c_str());
    }
    printf("]\n");
}