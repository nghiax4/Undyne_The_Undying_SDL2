#include "core/Scene.h"
#include <cstdio>
#include <stdexcept>

void Scene::update_all() {
    // Using index-based loop to handle objects spawning new objects during update
    for (size_t i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
}

void Scene::render_all() {
    std::sort(objects.begin(), objects.end(), z_index_comparator);

    for (auto &obj : objects) {
        if (obj->show) {
            obj->render();
        }
    }
}

void Scene::spawn(std::unique_ptr<GameObject> obj) {
    objects.push_back(std::move(obj));
}

void Scene::clear() {
    objects.clear();
}

GameObject *Scene::find_object_by_name(const std::string &name) {
    for (auto &obj : objects) {
        if (obj->obj_name == name)
            return obj.get();
    }
    throw std::runtime_error("Scene: Cannot find object with name " + name);
}

bool Scene::object_exists(const std::string &name) {
    for (const auto &obj : objects) {
        if (obj->obj_name == name)
            return true;
    }
    return false;
}

void Scene::cleanup_marked_objects() {
    objects.erase(
        std::remove_if(objects.begin(), objects.end(),
                       [](const std::unique_ptr<GameObject> &obj) {
                           return obj->to_be_removed;
                       }),
        objects.end());
}

void Scene::debug_verify_nonempty_names() {
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i]->obj_name.empty()) {
            throw std::runtime_error("Scene: Object at index " + std::to_string(i) + " has empty name");
        }
    }
}

bool Scene::z_index_comparator(const std::unique_ptr<GameObject> &a, const std::unique_ptr<GameObject> &b) {
    return a->z_index < b->z_index;
}
