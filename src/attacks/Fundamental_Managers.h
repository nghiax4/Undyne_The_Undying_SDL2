#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Circle_Spawn_Manager.h"
#include "Green_Mode_Manager.h"
#include "Red_Mode_Manager.h"
#include <functional>

// 1. Green Mode (Shield vs Arrows)
struct Generic_Green_Mode_Manager : public Green_Mode_Manager {
    using SetupFunc = std::function<void(Generic_Green_Mode_Manager *)>;
    SetupFunc setup_logic;

    Generic_Green_Mode_Manager(int attack_id, int duration_ms, SetupFunc setup_logic);
};

// 2. Falling Sky Arrows (Refactored Attack 3)
struct Falling_Sky_Arrows_Manager : public Red_Mode_Manager {
    int time_between_arrows_ms;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created_counter = 0;

    Falling_Sky_Arrows_Manager(int attack_id, int duration_ms, int time_between_arrows_ms);
    void update() override;
};

// 3. Player Targeted Arrows (Refactored Attack 4)
struct Player_Targeted_Arrows_Manager : public Red_Mode_Manager {
    int time_between_arrows_ms;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created_counter = 0;

    Player_Targeted_Arrows_Manager(int attack_id, int duration_ms, int time_between_arrows_ms);
    void update() override;
};

// 4. Spinning Arrow Circles (Refactored Attack 8, 9, 15)
struct Generic_Spinning_Arrow_Circle_Manager : public Circle_Spawn_Manager {
    Generic_Spinning_Arrow_Circle_Manager(int attack_id, int duration_ms, int interval_ms);
    void spawn_on_ring(double center_x, double center_y) override;
};

// 5. Ring Spears (Refactored Attack 14)
struct Generic_Ring_Spear_Manager : public Circle_Spawn_Manager {
    // Allows changing difficulty mid-attack (e.g. speed up after 5 seconds)
    using IntervalCalculator = std::function<int(int time_elapsed)>;
    IntervalCalculator get_interval_func;

    Generic_Ring_Spear_Manager(int attack_id, int duration_ms, double radius, IntervalCalculator get_interval_func);
    void update() override;
    void spawn_on_ring(double center_x, double center_y) override;
};
