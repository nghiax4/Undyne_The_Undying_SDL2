#include "ResourceManager.h"
#include "Engine.h"
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <stdexcept>

SmartTexture ResourceManager::get_texture(const std::string &path) {
    auto it = m_textures.find(path);
    if (it != m_textures.end()) {
        return it->second;
    }

    SDL_Surface *surface = IMG_Load(path.c_str());
    if (!surface) {
        throw std::runtime_error("ResourceManager: Failed to load image " + path + ": " + IMG_GetError());
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(Engine::get().get_renderer(), surface);
    SDL_FreeSurface(surface);

    if (!tex) {
        throw std::runtime_error("ResourceManager: Failed to create texture " + path + ": " + SDL_GetError());
    }

    SmartTexture smart_tex(tex, TextureDeleter());
    m_textures[path] = smart_tex;
    return smart_tex;
}

SmartFont ResourceManager::get_font(const std::string &path, int size) {
    std::string key = path + "_" + std::to_string(size);

    auto it = m_fonts.find(key);
    if (it != m_fonts.end()) {
        return it->second;
    }

    TTF_Font *font = TTF_OpenFont(path.c_str(), size);
    if (!font) {
        throw std::runtime_error("ResourceManager: Failed to load font " + path + ": " + TTF_GetError());
    }

    SmartFont smart_font(font, FontDeleter());
    m_fonts[key] = smart_font;
    return smart_font;
}

SmartChunk ResourceManager::get_sound(const std::string &path) {
    auto it = m_sounds.find(path);
    if (it != m_sounds.end()) {
        return it->second;
    }

    Mix_Chunk *chunk = Mix_LoadWAV(path.c_str());
    if (!chunk) {
        throw std::runtime_error("ResourceManager: Failed to load sound " + path + ": " + Mix_GetError());
    }

    SmartChunk smart_chunk(chunk, ChunkDeleter());
    m_sounds[path] = smart_chunk;
    return smart_chunk;
}

SmartMusic ResourceManager::get_music(const std::string &path) {
    auto it = m_music.find(path);
    if (it != m_music.end()) {
        return it->second;
    }

    Mix_Music *mus = Mix_LoadMUS(path.c_str());
    if (!mus) {
        throw std::runtime_error("ResourceManager: Failed to load music " + path + ": " + Mix_GetError());
    }

    SmartMusic smart_mus(mus, MusicDeleter());
    m_music[path] = smart_mus;
    return smart_mus;
}

void ResourceManager::clear() {
    m_textures.clear();
    m_fonts.clear();
    m_sounds.clear();
    m_music.clear();
}
