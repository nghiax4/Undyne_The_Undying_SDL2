#pragma once
#include "../GameObject.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class Scene {
  public:
    static Scene &get() {
        static Scene instance;
        return instance;
    }

    void update_all();
    void render_all();

    void spawn(std::unique_ptr<GameObject> obj);
    void clear();

    GameObject *find_object_by_name(const std::string &name);
    bool object_exists(const std::string &name);

    void cleanup_marked_objects();
    void debug_verify_nonempty_names();

    // Raw access if absolutely needed (try to avoid)
    const std::vector<std::unique_ptr<GameObject>> &get_objects() const {
        return objects;
    }

  private:
    Scene() = default;

    std::vector<std::unique_ptr<GameObject>> objects;

    static bool z_index_comparator(const std::unique_ptr<GameObject> &a, const std::unique_ptr<GameObject> &b);
};
