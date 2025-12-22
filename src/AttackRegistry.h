#pragma once
#include <map>
#include <functional>
#include <stdexcept>
#include <string>
#include "Attack_Manager_Base_Class.h"

// Define a factory function type that returns a new instance of an attack manager
using AttackFactoryFunction = std::function<Attack_Manager_Base_Class*()>;

struct AttackRegistry {
    // Singleton map to store attack creators
    // Wrapped in a static function to prevent static intialization order issues
    static std::map<int, AttackFactoryFunction>& get_registry_map() {
        static std::map<int, AttackFactoryFunction> registry_map;
        return registry_map;
    }

    static void register_attack(int attack_id, AttackFactoryFunction factory_func) {
        std::map<int, AttackFactoryFunction>& map = get_registry_map();
        map[attack_id] = factory_func;
    }

    static Attack_Manager_Base_Class* create_attack(int attack_id) {
        std::map<int, AttackFactoryFunction>& map = get_registry_map();
        return map[attack_id]();
    }
};

// Helper struct for static registration in each Attack cpp file
template<typename T>
struct AutoRegisterAttack {
    AutoRegisterAttack(int attack_id) {
        AttackRegistry::register_attack(attack_id, []() { return new T(); });
    }
};