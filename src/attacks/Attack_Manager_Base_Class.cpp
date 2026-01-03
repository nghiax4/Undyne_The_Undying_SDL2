#include "Attack_Manager_Base_Class.h"
#include "Arrow_For_Green_Attack.h"
#include "Globals.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include <Arrow_For_Green_Attack.h>
#include <algorithm>

Attack_Manager_Base_Class::Attack_Manager_Base_Class(int _attack_id) : attack_id(_attack_id) {
    attack_prefix = "Attack_" + std::to_string(attack_id);
    obj_name = "Attack_Manager_" + std::to_string(attack_id);
}

void Attack_Manager_Base_Class::update() {
    time_elapsed_since_creation += Engine::get().get_delta_time();
}

void Attack_Manager_Base_Class::ready_to_be_removed() {
    this->to_be_removed = true;
}

void Attack_Manager_Base_Class::_teardown_green_mode() {
    this->to_be_removed = true;

    GameObject *player = Scene::get().find_object_by_name("Player_EnemyTurn_Green");
    player->to_be_removed = true;

    GameObject *shield = Scene::get().find_object_by_name("Shield");
    shield->to_be_removed = true;

    // Remove all arrows/attacks specific to this attack
    for (auto &obj : Scene::get().get_objects()) {
        if (obj->obj_name.find(attack_prefix) == 0) {
            obj->to_be_removed = true;
        }
    }
}

Arrow_For_Green_Attack *Attack_Manager_Base_Class::create_arrow_for_green_attack(double x, double y, double v_x, double v_y, Direction direction, int arrow_number, ArrowType type) {
    std::string arrow_name = attack_prefix + "_Arrow_For_Green_Attack_" + std::to_string(arrow_number);
    return new Arrow_For_Green_Attack(x, y, v_x, v_y, direction, arrow_name, type);
}

Arrow_For_Green_Attack *Attack_Manager_Base_Class::create_arrow_for_green_attack_with_impact_time(Direction direction, double speed, int time_to_impact_ms, int arrow_number, ArrowType type) {
    assert(speed > 0);
    assert(time_to_impact_ms > 0);

    if (type == ArrowType::Yellow) {
        // Yellow arrows have rotation which makes the arrow stop moving toward to the soul, so we need to subtract the rotation time
        double rotation_duration_ms = 180.0 / Arrow_For_Green_Attack::ROTATION_SPEED_DEGREE_PER_MS;
        time_to_impact_ms = std::max(time_to_impact_ms - rotation_duration_ms, 0.0);
    }

    double target_x = Engine::get().get_screen_width() / 2.0;
    double target_y = Engine::get().get_screen_height() / 2.0;
    double distance_to_travel = speed * time_to_impact_ms;

    double start_x = target_x;
    double start_y = target_y;
    double v_x = 0, v_y = 0;

    // Invert spawn logic for Yellow arrows so they start "behind" the player
    if (direction == Direction::LEFT) {
        if (type == ArrowType::Blue) {
            start_x = target_x + distance_to_travel; // Spawns Right
            v_x = -speed;
        } else {
            start_x = target_x - distance_to_travel; // Spawns Left (Backwards)
            v_x = speed;                             // Moves Right (Towards Player)
        }
    } else if (direction == Direction::RIGHT) {
        if (type == ArrowType::Blue) {
            start_x = target_x - distance_to_travel;
            v_x = speed;
        } else {
            start_x = target_x + distance_to_travel;
            v_x = -speed;
        }
    } else if (direction == Direction::UP) {
        if (type == ArrowType::Blue) {
            start_y = target_y + distance_to_travel;
            v_y = -speed;
        } else {
            start_y = target_y - distance_to_travel;
            v_y = speed;
        }
    } else if (direction == Direction::DOWN) {
        if (type == ArrowType::Blue) {
            start_y = target_y - distance_to_travel;
            v_y = speed;
        } else {
            start_y = target_y + distance_to_travel;
            v_y = -speed;
        }
    }

    return create_arrow_for_green_attack(start_x, start_y, v_x, v_y, direction, arrow_number, type);
}
