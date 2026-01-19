#pragma once
#include "core/Components.h"
#include <SDL2/SDL.h>
#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <typeindex>
#include <unordered_map>

// Base class for all game objects
class GameObject {
  public:
    std::string m_obj_name;
    bool m_show = true;
    bool m_to_be_removed = false;
    int m_z_index = 0;

    // Container for components: Map<Type, ComponentPointer>
    std::unordered_map<std::type_index, std::unique_ptr<Component>> m_components;

    template <typename T, typename... Args>
    void *add_component(Args &&...args) {
        assert(!has_component<T>());
        m_components[std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
        return get_component<T>();
    }

    template <typename T>
    T *get_component() {
        assert(has_component<T>());
        return static_cast<T *>(m_components.find(std::type_index(typeid(T)))->second.get());
    }

    template <typename T>
    bool has_component() {
        return m_components.find(std::type_index(typeid(T))) != m_components.end();
    }

    GameObject() = default;
    GameObject(GameObject &&) = default;
    GameObject &operator=(GameObject &&) = default;
    virtual ~GameObject() = default;

    virtual void update();
    virtual void render();
};
