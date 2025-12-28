#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Circle_Spawn_Manager.h"
#include "Green_Mode_Manager.h"
#include "Red_Mode_Manager.h"
#include <functional>

struct Three_Lane_Rising_Arrow_Attack : public Red_Mode_Manager {
    int time_between_arrows_ms;
    int arrow_prep_time_ms;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created_counter = 0;

    Three_Lane_Rising_Arrow_Attack(int attack_id, int duration_ms, int time_between_arrows_ms, int arrow_prep_time_ms = 750);
    void update() override;
};

struct Random_Spawn_Player_Aimed_Arrow_Attack : public Red_Mode_Manager {
    int time_between_arrows_ms;
    int arrow_rotation_time_ms;
    int time_elapsed_since_last_arrow = 0;
    int arrows_created_counter = 0;

    Random_Spawn_Player_Aimed_Arrow_Attack(int attack_id, int duration_ms, int time_between_arrows_ms, int arrow_rotation_time_ms = 1000);
    void update() override;
};

struct Inward_Spiraling_Arrow_Ring_Attack : public Circle_Spawn_Manager {
    Inward_Spiraling_Arrow_Ring_Attack(int attack_id, int duration_ms, int interval_ms);
    void spawn_on_ring(double center_x, double center_y) override;
};

struct Contracting_Rotating_Spear_Ring_Attack : public Circle_Spawn_Manager {
    // Allows changing difficulty mid-attack (e.g. speed up after 5 seconds)
    using IntervalCalculator = std::function<int(int time_elapsed)>;
    IntervalCalculator get_interval_func;

    Contracting_Rotating_Spear_Ring_Attack(int attack_id, int duration_ms, double radius, IntervalCalculator get_interval_func);
    void update() override;
    void spawn_on_ring(double center_x, double center_y) override;
};
