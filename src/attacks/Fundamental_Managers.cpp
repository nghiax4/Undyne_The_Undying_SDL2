#include "Fundamental_Managers.h"
#include "BattleBox.h"
#include "Player_EnemyTurn.h"
#include "Ring_Spear.h"
#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "White_Arrow_Small_Box_Attack.h"

// --- 1. Green Mode ---
Generic_Green_Mode_Manager::Generic_Green_Mode_Manager(int attack_id, int duration_ms, SetupFunc setup_logic) : Green_Mode_Manager(attack_id, duration_ms), setup_logic(setup_logic) {
    this->setup_logic(this);
}

// --- 2. Falling Sky Arrows ---
Falling_Sky_Arrows_Manager::Falling_Sky_Arrows_Manager(int attack_id, int duration_ms, int time_between_arrows_ms) : Red_Mode_Manager(attack_id, duration_ms, 0.72, 0.12, 0.19), time_between_arrows_ms(time_between_arrows_ms) {}

void Falling_Sky_Arrows_Manager::update() {
    Red_Mode_Manager::update();
    time_elapsed_since_last_arrow += deltaTime;

    if (time_elapsed_since_last_arrow > time_between_arrows_ms) {
        std::vector<double> x_multipliers = {0.2, 0.5, 0.8};
        double x_pos = global_battlebox->x_center - global_battlebox->width / 2 + global_battlebox->width * x_multipliers.at(get_random(0, 2));
        double y_pos = global_battlebox->y_center + global_battlebox->height;

        std::string name = attack_prefix + "_Falling_Arrow_" + std::to_string(arrows_created_counter++);
        objs.push_back(new White_Arrow_Small_Box_Attack(x_pos, y_pos, name));

        time_elapsed_since_last_arrow = 0;
    }
}

// --- 3. Targeted Arrows ---
Player_Targeted_Arrows_Manager::Player_Targeted_Arrows_Manager(int attack_id, int duration_ms, int time_between_arrows_ms) : Red_Mode_Manager(attack_id, duration_ms, 0.63, 0.28, (double)(SCREEN_WIDTH * 0.28) / SCREEN_HEIGHT), time_between_arrows_ms(time_between_arrows_ms) {}

void Player_Targeted_Arrows_Manager::update() {
    Red_Mode_Manager::update();
    time_elapsed_since_last_arrow += deltaTime;

    if (time_elapsed_since_last_arrow > time_between_arrows_ms) {
        Player_EnemyTurn *player = static_cast<Player_EnemyTurn *>(find_object_by_name("Player_EnemyTurn"));

        double spawn_radius = get_random(SCREEN_WIDTH * 0.2, SCREEN_WIDTH * 0.3);
        double angle_deg = get_random(0, 360);
        double spawn_x = global_battlebox->x_center + spawn_radius * cos(angle_deg * M_PI / 180.0);
        double spawn_y = global_battlebox->y_center + spawn_radius * sin(angle_deg * M_PI / 180.0);

        std::string name = attack_prefix + "_Targeted_Arrow_" + std::to_string(arrows_created_counter++);
        objs.push_back(new White_Arrow_Medium_Box_Attack(spawn_x, spawn_y, player->x_center, player->y_center, name));

        time_elapsed_since_last_arrow = 0;
    }
}

// --- 4. Spinning Arrow Circles ---
Generic_Spinning_Arrow_Circle_Manager::Generic_Spinning_Arrow_Circle_Manager(int attack_id, int duration_ms, int interval_ms) : Circle_Spawn_Manager(attack_id, duration_ms, interval_ms, SCREEN_WIDTH * 0.35) {}

void Generic_Spinning_Arrow_Circle_Manager::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    const int ARROWS_PER_RING = 7;

    for (int i = 0; i < ARROWS_PER_RING; i++) {
        double angle = angle_offset + (360.0 / ARROWS_PER_RING) * i;
        std::string name = attack_prefix + "_Spinning_" + std::to_string(items_created_counter++);
        objs.push_back(new Spinning_Arrow(center_x, center_y, angle, spawn_radius, name));
    }
}

// --- 5. Ring Spears ---
Generic_Ring_Spear_Manager::Generic_Ring_Spear_Manager(int attack_id, int duration_ms, double radius, IntervalCalculator get_interval_func) : Circle_Spawn_Manager(attack_id, duration_ms, get_interval_func(0), radius), get_interval_func(get_interval_func) {}

void Generic_Ring_Spear_Manager::update() {
    // Update interval dynamically based on time
    current_interval = get_interval_func(time_elapsed_since_creation);
    Circle_Spawn_Manager::update();
}

void Generic_Ring_Spear_Manager::spawn_on_ring(double center_x, double center_y) {
    double angle_offset = get_random(0, 360);
    const int SPEARS_PER_RING = 6;

    for (int i = 0; i < SPEARS_PER_RING; i++) {
        double angle = angle_offset + (360.0 / SPEARS_PER_RING) * i;
        std::string name = attack_prefix + "_Spear_" + std::to_string(items_created_counter++);
        objs.push_back(new Ring_Spear(center_x, center_y, angle, spawn_radius, name));
    }
}
