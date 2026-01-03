#include "Utils.h"
#include "GameObject.h"
#include "Globals.h"
#include "core/Engine.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <algorithm>
#include <map>
#include <random>

SDL_Texture *loadTexture(std::string path) {
    static std::map<std::string, SDL_Texture *> texture_cache;

    auto texture_cache_find_iterator = texture_cache.find(path);
    if (texture_cache_find_iterator != texture_cache.end()) {
        return texture_cache_find_iterator->second;
    }

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        throw std::runtime_error("Unable to load image " + path + "! SDL_image Error: " + IMG_GetError());
    }
    // Create texture from surface pixels
    SDL_Texture *newTexture = SDL_CreateTextureFromSurface(Engine::get().get_renderer(), loadedSurface);
    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    if (newTexture == NULL) {
        throw std::runtime_error("Unable to create texture from " + path + "! SDL Error: " + SDL_GetError());
    }

    texture_cache[path] = newTexture;

    return newTexture;
}

GameObject *find_object_by_name(std::string obj_name) {
    for (auto &obj : objs) {
        if (obj->obj_name == obj_name) {
            return obj.get();
        }
    }

    throw std::runtime_error("Cannot find object with name " + obj_name);
}

bool object_by_name_exists(std::string obj_name) {
    for (const auto &obj : objs) {
        if (obj->obj_name == obj_name) {
            return true;
        }
    }

    return false;
}

void _print_all_objs_names() {
    printf("All objects names:\n");
    for (const auto &obj : objs) {
        printf("- %s\n", obj->obj_name.c_str());
    }
    printf("\n");
}

void _remove_objs_that_are_to_be_removed() {
    objs.erase(
        std::remove_if(objs.begin(), objs.end(),
                       [](const std::unique_ptr<GameObject> &obj) {
                           return obj->to_be_removed;
                       }),
        objs.end());
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

void play_sound_effect(std::string path) {
    // Instead of using Mix_FreeChunk, use a cache to keep chunks in memory so we don't accidentally free audio while it's playing (and to avoid slow disk I/O)
    static std::map<std::string, Mix_Chunk *> sound_cache;

    Mix_Chunk *chunk = nullptr;

    if (sound_cache.find(path) == sound_cache.end()) {
        chunk = Mix_LoadWAV(path.c_str());
        if (!chunk) {
            throw std::runtime_error(std::string("Failed to load SFX: ") + Mix_GetError());
        }
        sound_cache[path] = chunk;
    } else {
        chunk = sound_cache[path];
    }

    Mix_PlayChannel(-1, chunk, 0); // -1 = first free channel, 0 = play once
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int get_random(int low, int high) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(low, high);
    int result = dis(gen);
    // printf("[DEBUG] get_random(%d, %d) returned %d\n", low, high, result);
    return result;
}

double get_random(double low, double high) {
    static std::random_device rd;  // seed source (non-deterministic)
    static std::mt19937 gen(rd()); // Mersenne Twister engine

    std::uniform_real_distribution<double> dist(low, high);
    return dist(gen);
}
