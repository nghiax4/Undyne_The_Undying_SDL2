#include "Utils.h"
#include "GameObject.h"

#include "core/Engine.h"
#include "core/Scene.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <algorithm>
#include <map>
#include <random>

// SDL_Texture *loadTexture(std::string path) {
//     static std::map<std::string, SDL_Texture *> texture_cache;

//     auto texture_cache_find_iterator = texture_cache.find(path);
//     if (texture_cache_find_iterator != texture_cache.end()) {
//         return texture_cache_find_iterator->second;
//     }

//     // Load image at specified path
//     SDL_Surface *loadedSurface = IMG_Load(path.c_str());
//     if (loadedSurface == NULL) {
//         throw std::runtime_error("Unable to load image " + path + "! SDL_image Error: " + IMG_GetError());
//     }
//     // Create texture from surface pixels
//     SDL_Texture *newTexture = SDL_CreateTextureFromSurface(Engine::get().get_renderer(), loadedSurface);
//     // Get rid of old loaded surface
//     SDL_FreeSurface(loadedSurface);

//     if (newTexture == NULL) {
//         throw std::runtime_error("Unable to create texture from " + path + "! SDL Error: " + SDL_GetError());
//     }

//     texture_cache[path] = newTexture;

//     return newTexture;
// }

void _print_all_objs_names() {
    printf("All objects names:\n");
    for (const auto &obj : Scene::get().get_objects()) {
        printf("- %s\n", obj->m_obj_name.c_str());
    }
    printf("\n");
}

void _verify_objs_correct() {
    for (size_t i = 0; i < Scene::get().get_objects().size(); i++) {
        if (Scene::get().get_objects()[i]->m_obj_name.empty()) {
            throw std::runtime_error("Obj at index " + std::to_string(i) + " have empty name");
        }
    }

    for (size_t i = 0; i < Scene::get().get_objects().size(); i++) {
        for (size_t j = i + 1; j < Scene::get().get_objects().size(); j++) {
            if (Scene::get().get_objects()[i]->m_obj_name == Scene::get().get_objects()[j]->m_obj_name) {
                throw std::runtime_error("Obj at index " + std::to_string(i) + " and " + std::to_string(j) + " have same name");
            }
        }
    }
}

void _print_objs_names() {
    printf("[");
    for (const auto &obj : Scene::get().get_objects()) {
        printf("'%s', ", obj->m_obj_name.c_str());
    }
    printf("]\n");
}

void play_sound_effect(std::string path) {
    SmartChunk chunk = ResourceManager::get().get_sound(path);
    Mix_PlayChannel(-1, chunk.get(), 0); // -1 = first free channel, 0 = play once
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
