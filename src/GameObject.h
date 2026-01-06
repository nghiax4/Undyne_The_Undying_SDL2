#pragma once
#include <SDL2/SDL.h>
#include <string>

// Base class for all game objects
class GameObject {
  public:
    std::string m_obj_name;
    bool m_show = true;
    bool m_to_be_removed = false;
    int m_z_index = 0;
    virtual void update();
    virtual void render();

    virtual ~GameObject() = default;
};
