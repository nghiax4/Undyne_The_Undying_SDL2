#pragma once
#include "Attack_Manager_Base_Class.h"
#include "Circle_Spawn_Manager.h"
#include "Green_Mode_Manager.h"
#include "Red_Mode_Manager.h"
#include <functional>

struct Three_Lane_Rising_Arrow_Attack : public Red_Mode_Manager {
    Uint32 m_time_between_arrows_ms;
    Uint32 m_arrow_prep_time_ms;
    Uint32 m_time_elapsed_since_last_arrow = 0;
    int m_arrows_created_counter = 0;

    Three_Lane_Rising_Arrow_Attack(int attack_id, Uint32 duration_ms, Uint32 time_between_arrows_ms, Uint32 arrow_prep_time_ms = 750);
    void update() override;
};

struct Random_Spawn_Player_Aimed_Arrow_Attack : public Red_Mode_Manager {
    Uint32 m_time_between_arrows_ms;
    Uint32 m_arrow_rotation_time_ms;
    Uint32 m_time_elapsed_since_last_arrow = 0;
    int m_arrows_created_counter = 0;

    Random_Spawn_Player_Aimed_Arrow_Attack(int attack_id, Uint32 duration_ms, Uint32 time_between_arrows_ms, Uint32 arrow_rotation_time_ms = 1000);
    void update() override;
};

struct Inward_Spiraling_Arrow_Ring_Attack : public Circle_Spawn_Manager {
    Inward_Spiraling_Arrow_Ring_Attack(int attack_id, Uint32 duration_ms, Uint32 interval_ms);
    void spawn_on_ring(double center_x, double center_y) override;
};

struct Contracting_Rotating_Spear_Ring_Attack : public Circle_Spawn_Manager {
    // Allows changing difficulty mid-attack (e.g. speed up after 5 seconds)
    using IntervalCalculator = std::function<Uint32(Uint32 time_elapsed)>;
    IntervalCalculator m_get_interval_func;

    Contracting_Rotating_Spear_Ring_Attack(int attack_id, Uint32 duration_ms, double radius, IntervalCalculator get_interval_func);
    void update() override;
    void spawn_on_ring(double center_x, double center_y) override;
};
