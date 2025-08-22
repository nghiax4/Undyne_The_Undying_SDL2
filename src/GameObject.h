#pragma once
#include <SDL2/SDL.h>
#include <string>

// Base class for all game objects
class GameObject {
  public:
    std::string obj_name;
    int z_index = 0;
    virtual void update();
    virtual void render();
};