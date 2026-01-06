#include "core/Scene.h"
#include <cstdio>
#include <stdexcept>

void Scene::update_all() {
    // Using index-based loop to handle objects spawning new objects during update
    for (size_t i = 0; i < m_objects.size(); i++) {
        m_objects[i]->update();
    }
}

void Scene::render_all() {
    std::sort(m_objects.begin(), m_objects.end(), z_index_comparator);

    for (auto &obj : m_objects) {
        if (obj->m_show) {
            obj->render();
        }
    }
}

void Scene::spawn(std::unique_ptr<GameObject> obj) {
    m_objects.push_back(std::move(obj));
}

void Scene::clear() {
    m_objects.clear();
}

GameObject *Scene::find_object_by_name(const std::string &name) {
    for (auto &obj : m_objects) {
        if (obj->m_obj_name == name)
            return obj.get();
    }
    throw std::runtime_error("Scene: Cannot find object with name " + name);
}

bool Scene::object_exists(const std::string &name) {
    for (const auto &obj : m_objects) {
        if (obj->m_obj_name == name)
            return true;
    }
    return false;
}

void Scene::cleanup_marked_objects() {
    m_objects.erase(
        std::remove_if(m_objects.begin(), m_objects.end(),
                       [](const std::unique_ptr<GameObject> &obj) {
                           return obj->m_to_be_removed;
                       }),
        m_objects.end());
}

void Scene::debug_verify_nonempty_names() {
    for (size_t i = 0; i < m_objects.size(); i++) {
        if (m_objects[i]->m_obj_name.empty()) {
            throw std::runtime_error("Scene: Object at index " + std::to_string(i) + " has empty name");
        }
    }
}

bool Scene::z_index_comparator(const std::unique_ptr<GameObject> &a, const std::unique_ptr<GameObject> &b) {
    return a->m_z_index < b->m_z_index;
}
