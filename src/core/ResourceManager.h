#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <map>
#include <memory>
#include <string>

// Custom deleters for smart pointers
struct TextureDeleter {
    void operator()(SDL_Texture *t) const {
        if (t)
            SDL_DestroyTexture(t);
    }
};
struct FontDeleter {
    void operator()(TTF_Font *f) const {
        if (f)
            TTF_CloseFont(f);
    }
};
struct ChunkDeleter {
    void operator()(Mix_Chunk *c) const {
        if (c)
            Mix_FreeChunk(c);
    }
};
struct MusicDeleter {
    void operator()(Mix_Music *m) const {
        if (m)
            Mix_FreeMusic(m);
    }
};

using SmartTexture = std::shared_ptr<SDL_Texture>; // Shared because multiple objects use the same sprite
using SmartFont = std::shared_ptr<TTF_Font>;
using SmartChunk = std::shared_ptr<Mix_Chunk>;
using SmartMusic = std::shared_ptr<Mix_Music>;

class ResourceManager {
  public:
    static ResourceManager &get() {
        static ResourceManager instance;
        return instance;
    }

    // If the resource is already loaded, these returns the existing one. Otherwise, they loads it.
    SmartTexture get_texture(const std::string &path);
    SmartFont get_font(const std::string &path, int size);
    SmartChunk get_sound(const std::string &path);
    SmartMusic get_music(const std::string &path);

    void clear();

  private:
    ResourceManager() = default;

    std::map<std::string, SmartTexture> m_textures;
    std::map<std::string, SmartChunk> m_sounds;
    std::map<std::string, SmartMusic> m_music;
    // Fonts are unique by Path + Font size
    std::map<std::string, SmartFont> m_fonts;
};
