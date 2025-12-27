#include "AttackRegistry.h"
#include "Fundamental_Managers.h"

// Standard Speeds
const double SPD_X = SCREEN_WIDTH * 0.001;
const double SPD_Y = SCREEN_HEIGHT * 0.001;
const double SLOW_Y = SCREEN_HEIGHT * 0.0002;
const double MED_X = SCREEN_WIDTH * 0.00075;
const double MED_Y = SCREEN_HEIGHT * 0.00075;

// Helper to register all attacks on startup
static struct Attack_Definitions_Loader {
    Attack_Definitions_Loader() {
        // --- Attack 0 ---
        AttackRegistry::register_attack(0, []() {
            return new Generic_Green_Mode_Manager(0, 10000, [](Generic_Green_Mode_Manager *m) {
                m->schedule_arrow(Direction::DOWN, 3500, SLOW_Y);
                m->schedule_arrow(Direction::DOWN, 4250, SLOW_Y);
                m->schedule_arrow(Direction::DOWN, 5000, SLOW_Y);
                m->schedule_arrow(Direction::LEFT, 5000, SPD_X);
                m->schedule_arrow(Direction::UP, 5400, SPD_Y);
                m->schedule_arrow(Direction::RIGHT, 5800, SPD_X);
                m->schedule_arrow(Direction::DOWN, 6200, SPD_Y);
                m->schedule_arrow(Direction::RIGHT, 6600, SPD_X);
                m->schedule_arrow(Direction::UP, 7000, SPD_Y);
                m->schedule_arrow(Direction::LEFT, 7400, SPD_X);
                m->schedule_arrow(Direction::UP, 7800, SPD_Y);
                m->schedule_arrow(Direction::RIGHT, 8200, SPD_X);
                m->schedule_arrow(Direction::DOWN, 8600, SPD_Y);
            });
        });

        // --- Attack 1 ---
        AttackRegistry::register_attack(1, []() {
            return new Generic_Green_Mode_Manager(1, 5000, [](Generic_Green_Mode_Manager *m) {
                m->schedule_arrow(Direction::RIGHT, 1000, SPD_X);
                m->schedule_arrow(Direction::LEFT, 1300, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 1600, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 1750, SPD_X);
                m->schedule_arrow(Direction::LEFT, 2050, SPD_X);
                m->schedule_arrow(Direction::LEFT, 2350, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 2750, SPD_X);
                m->schedule_arrow(Direction::LEFT, 3000, SPD_X);
                m->schedule_arrow(Direction::LEFT, 3150, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 3450, SPD_X);
                m->schedule_arrow(Direction::LEFT, 3700, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 4000, SPD_X);
                m->schedule_arrow(Direction::LEFT, 4300, SPD_X);
                m->schedule_arrow(Direction::RIGHT, 4600, SPD_X);
            });
        });

        // --- Attack 2 ---
        AttackRegistry::register_attack(2, []() {
            return new Generic_Green_Mode_Manager(2, 11000, [](Generic_Green_Mode_Manager *m) {
                double s_x = SCREEN_WIDTH * 0.0002;
                double s_y = SCREEN_HEIGHT * 0.0002;
                m->schedule_arrow(Direction::UP, 3500, s_y);
                m->schedule_arrow(Direction::DOWN, 3750, s_y);
                m->schedule_arrow(Direction::LEFT, 4000, s_x);
                m->schedule_arrow(Direction::DOWN, 4500, s_y);
                m->schedule_arrow(Direction::DOWN, 5000, s_y);
                m->schedule_arrow(Direction::LEFT, 5500, s_x);
                m->schedule_arrow(Direction::RIGHT, 5750, s_x);
                m->schedule_arrow(Direction::RIGHT, 5900, s_x);
                m->schedule_arrow(Direction::UP, 6250, s_y);
                m->schedule_arrow(Direction::LEFT, 6500, s_x);
                m->schedule_arrow(Direction::DOWN, 7000, s_y);
                m->schedule_arrow(Direction::DOWN, 7500, s_y);
                m->schedule_arrow(Direction::UP, 8000, s_y);
                m->schedule_arrow(Direction::DOWN, 8500, s_y);
                m->schedule_arrow(Direction::DOWN, 8650, s_y);
                m->schedule_arrow(Direction::LEFT, 8800, s_x);
                m->schedule_arrow(Direction::RIGHT, 8950, s_x);
                m->schedule_arrow(Direction::LEFT, 9100, s_x);
                m->schedule_arrow(Direction::RIGHT, 9250, s_x);
            });
        });

        // --- Attack 3 (Red Mode: Falling Arrows) ---
        AttackRegistry::register_attack(3, []() {
            return new Falling_Sky_Arrows_Manager(3, 8500, 450);
        });

        // --- Attack 4 (Red Mode: Targeted) ---
        AttackRegistry::register_attack(4, []() {
            return new Player_Targeted_Arrows_Manager(4, 8500, 400);
        });

        // --- Attack 5 ---
        AttackRegistry::register_attack(5, []() {
            return new Generic_Green_Mode_Manager(5, 6000, [](Generic_Green_Mode_Manager *m) {
                double sx = SCREEN_WIDTH * 0.0007;
                double sy = SCREEN_HEIGHT * 0.0004;
                double sy_fast = SCREEN_WIDTH * 0.0004;
                m->schedule_arrow(Direction::RIGHT, 1000, sx);
                m->schedule_arrow(Direction::DOWN, 1750, sy);
                m->schedule_arrow(Direction::LEFT, 2143, sx);
                m->schedule_arrow(Direction::UP, 2500, sy);
                m->schedule_arrow(Direction::LEFT, 2857, sx);
                m->schedule_arrow(Direction::RIGHT, 3750, sy_fast);
                m->schedule_arrow(Direction::DOWN, 4375, sy);
                m->schedule_arrow(Direction::UP, 5000, sy);
            });
        });

        // --- Attack 6 ---
        AttackRegistry::register_attack(6, []() {
            return new Generic_Green_Mode_Manager(6, 5500, [](Generic_Green_Mode_Manager *m) {
                m->schedule_arrow(Direction::DOWN, 700, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 850, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 1000, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 1150, SPD_Y);
                m->schedule_arrow(Direction::RIGHT, 1400, SPD_X);
                m->schedule_arrow(Direction::DOWN, 1650, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 1800, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 1950, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 2100, SPD_Y);
                m->schedule_arrow(Direction::LEFT, 2250, SPD_X);
                m->schedule_arrow(Direction::DOWN, 2600, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 2750, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 2900, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 3050, SPD_Y);
                m->schedule_arrow(Direction::RIGHT, 3220, SPD_X);
                m->schedule_arrow(Direction::DOWN, 3550, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 3700, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 3850, SPD_Y);
                m->schedule_arrow(Direction::DOWN, 4000, SPD_Y);
                m->schedule_arrow(Direction::LEFT, 4050, SPD_X);
            });
        });

        // --- Attack 7 ---
        AttackRegistry::register_attack(7, []() {
            return new Generic_Green_Mode_Manager(7, 6500, [](Generic_Green_Mode_Manager *m) {
                double sx = SCREEN_WIDTH * 0.0005;
                double sy = SCREEN_HEIGHT * 0.0005;
                m->schedule_arrow(Direction::RIGHT, 1067, sx);
                m->schedule_arrow(Direction::DOWN, 1400, sy);
                m->schedule_arrow(Direction::RIGHT, 1667, sx);
                m->schedule_arrow(Direction::DOWN, 2000, sy);
                m->schedule_arrow(Direction::RIGHT, 2233, sx);
                m->schedule_arrow(Direction::DOWN, 2600, sy);
                m->schedule_arrow(Direction::RIGHT, 2833, sx);
                m->schedule_arrow(Direction::DOWN, 3167, sy);
                m->schedule_arrow(Direction::LEFT, 3800, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 4067, sy, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 4400, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 4667, sy, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 5000, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 5267, sy, ArrowType::Yellow);
            });
        });

        // --- Attack 8 (Spinning Circle) ---
        AttackRegistry::register_attack(8, []() {
            return new Generic_Spinning_Arrow_Circle_Manager(8, 10000, 933);
        });

        // --- Attack 9 (Spinning Circle) ---
        AttackRegistry::register_attack(9, []() {
            return new Generic_Spinning_Arrow_Circle_Manager(9, 10000, 933);
        });

        // --- Attack 10 (Yellow Arrows) ---
        AttackRegistry::register_attack(10, []() {
            return new Generic_Green_Mode_Manager(10, 7000, [](Generic_Green_Mode_Manager *m) {
                double sx = SCREEN_WIDTH * 0.0012;
                double sy = SCREEN_HEIGHT * 0.0012;
                m->schedule_arrow(Direction::RIGHT, 1700, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 2033, sy, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 2366, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::DOWN, 2766, sy, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 2966, sy, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 3300, sx, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 3633, sy, ArrowType::Blue);
                m->schedule_arrow(Direction::RIGHT, 3966, sx, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 4766, sy, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 5100, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::RIGHT, 5433, sx, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 5766, sy, ArrowType::Yellow);
            });
        });

        // --- Attack 11 (Mixed Blue/Yellow) ---
        AttackRegistry::register_attack(11, []() {
            return new Generic_Green_Mode_Manager(11, 7000, [](Generic_Green_Mode_Manager *m) {
                m->schedule_arrow(Direction::RIGHT, 900, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 1234, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 1567, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 1867, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::RIGHT, 2200, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 2467, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::UP, 2800, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::UP, 3134, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::RIGHT, 3500, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 3767, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 4134, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 4500, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::RIGHT, 4800, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 5067, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::UP, 5367, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::UP, 5767, MED_Y, ArrowType::Yellow);
            });
        });

        // --- Attack 12 (Mixed) ---
        AttackRegistry::register_attack(12, []() {
            return new Generic_Green_Mode_Manager(12, 7000, [](Generic_Green_Mode_Manager *m) {
                m->schedule_arrow(Direction::RIGHT, 800, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 1333, MED_X, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 1567, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 2167, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 2400, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::RIGHT, 2933, MED_X, ArrowType::Yellow);
                m->schedule_arrow(Direction::DOWN, 3233, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::UP, 3800, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::RIGHT, 4067, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::LEFT, 4633, MED_X, ArrowType::Yellow);
                m->schedule_arrow(Direction::UP, 4833, MED_Y, ArrowType::Blue);
                m->schedule_arrow(Direction::DOWN, 5433, MED_Y, ArrowType::Yellow);
                m->schedule_arrow(Direction::LEFT, 5667, MED_X, ArrowType::Blue);
                m->schedule_arrow(Direction::RIGHT, 6233, MED_X, ArrowType::Yellow);
            });
        });

        // --- Attack 13 (Longest) ---
        AttackRegistry::register_attack(13, []() {
            return new Generic_Green_Mode_Manager(13, 12500, [](Generic_Green_Mode_Manager *m) {
                double sx = SCREEN_WIDTH * 0.00012;
                double sy = SCREEN_HEIGHT * 0.00012;
                m->schedule_arrow(Direction::DOWN, 5733, sy);
                m->schedule_arrow(Direction::LEFT, 5967, sx);
                m->schedule_arrow(Direction::DOWN, 6300, sy);
                m->schedule_arrow(Direction::DOWN, 6567, sy);
                m->schedule_arrow(Direction::RIGHT, 6800, sx);
                m->schedule_arrow(Direction::LEFT, 7067, sx);
                m->schedule_arrow(Direction::UP, 7467, sy);
                m->schedule_arrow(Direction::LEFT, 7733, sx);
                m->schedule_arrow(Direction::DOWN, 7967, sy);
                m->schedule_arrow(Direction::UP, 8133, sy);
                m->schedule_arrow(Direction::RIGHT, 8467, sx);
                m->schedule_arrow(Direction::LEFT, 8667, sx);
                m->schedule_arrow(Direction::UP, 8900, sy);
                m->schedule_arrow(Direction::UP, 9133, sy);
                m->schedule_arrow(Direction::RIGHT, 9467, sx);
                m->schedule_arrow(Direction::LEFT, 9700, sx);
                m->schedule_arrow(Direction::LEFT, 10000, sx);
                m->schedule_arrow(Direction::RIGHT, 10367, sx);
                m->schedule_arrow(Direction::UP, 10667, sy);
                m->schedule_arrow(Direction::UP, 10900, sy);
                m->schedule_arrow(Direction::UP, 11033, sy);
                m->schedule_arrow(Direction::LEFT, 11267, sx);
                m->schedule_arrow(Direction::DOWN, 11600, sy);
                m->schedule_arrow(Direction::DOWN, 11900, sy);
            });
        });

        // --- Attack 14 (Ring Spears) ---
        AttackRegistry::register_attack(14, []() {
            return new Generic_Ring_Spear_Manager(14, 12000, SCREEN_WIDTH * 0.25, [](int time_elapsed) {
                // If 5 seconds passed, spawn faster (333ms), else normal (633ms)
                return (time_elapsed > 5000) ? 333 : 633;
            });
        });

        // --- Attack 15 (Fast Spin) ---
        AttackRegistry::register_attack(15, []() {
            return new Generic_Spinning_Arrow_Circle_Manager(15, 10000, 800);
        });
    }
} loader;
