#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Fundamental_Managers.h"
#include "Utils.h"
#include "core/Engine.h"
#include <functional>
#include <map>
#include <stdexcept>
#include <string>

using AttackFactoryFunction = std::function<Attack_Manager_Base_Class *()>;

struct AttackRegistry {
    // Singleton map to store attack creators
    // Wrapped in a static function to prevent static intialization order fiasco
    static std::map<int, AttackFactoryFunction> &get_registry_map() {
        static std::map<int, AttackFactoryFunction> registry_map;
        return registry_map;
    }

    static void register_attack(int attack_id, AttackFactoryFunction factory_func) {
        std::map<int, AttackFactoryFunction> &map = get_registry_map();
        map[attack_id] = factory_func;
    }

    static Attack_Manager_Base_Class *create_attack(int attack_id) {
        std::map<int, AttackFactoryFunction> &map = get_registry_map();

        if (attack_id <= 15) {
            return map.at(attack_id)();
        } else {
            int random_pick = get_random(0, 3);
            const int DURATION = 10000;

            if (random_pick == 0) {
                return new Contracting_Rotating_Spear_Ring_Attack(attack_id, DURATION, Engine::get().get_screen_width() * 0.25, [](int time_elapsed) {
                    return (time_elapsed > 5000) ? 333 : 633;
                });
            } else if (random_pick == 1) {
                return new Inward_Spiraling_Arrow_Ring_Attack(attack_id, DURATION, 800);
            } else if (random_pick == 2) {
                return new Random_Spawn_Player_Aimed_Arrow_Attack(attack_id, DURATION, 233, 1000);
            } else {
                return new Three_Lane_Rising_Arrow_Attack(attack_id, DURATION, 633, 917);
            }
        }
    }
};

// Helper struct for static registration in each Attack cpp file
template <typename T>
struct AutoRegisterAttack {
    AutoRegisterAttack(int attack_id) {
        AttackRegistry::register_attack(attack_id, []() {
            return new T();
        });
    }
};
