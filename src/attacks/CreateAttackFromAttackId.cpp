#include "CreateAttackFromAttackId.h"
#include "Fundamental_Managers.h"
#include "Utils.h"
#include "core/Engine.h"
#include <stdexcept>

constexpr double SPD_X = Engine::SCREEN_WIDTH * 0.001;
constexpr double SPD_Y = Engine::SCREEN_HEIGHT * 0.001;
constexpr double SLOW_Y = Engine::SCREEN_HEIGHT * 0.0002;
constexpr double MED_X = Engine::SCREEN_WIDTH * 0.00075;
constexpr double MED_Y = Engine::SCREEN_HEIGHT * 0.00075;

Attack_Manager_Base_Class *create_attack(int attack_id) {
    if (attack_id <= 15) {
        switch (attack_id) {
        case 0: {
            return new Green_Mode_Manager(0, 10000, {
                                                        {Direction::DOWN, 3500, SLOW_Y},
                                                        {Direction::DOWN, 4250, SLOW_Y},
                                                        {Direction::DOWN, 5000, SLOW_Y},
                                                        {Direction::LEFT, 5000, SPD_X},
                                                        {Direction::UP, 5400, SPD_Y},
                                                        {Direction::RIGHT, 5800, SPD_X},
                                                        {Direction::DOWN, 6200, SPD_Y},
                                                        {Direction::RIGHT, 6600, SPD_X},
                                                        {Direction::UP, 7000, SPD_Y},
                                                        {Direction::LEFT, 7400, SPD_X},
                                                        {Direction::UP, 7800, SPD_Y},
                                                        {Direction::RIGHT, 8200, SPD_X},
                                                        {Direction::DOWN, 8600, SPD_Y},
                                                    });
        }
        case 1: {
            return new Green_Mode_Manager(1, 5000, {
                                                       {Direction::RIGHT, 1000, SPD_X},
                                                       {Direction::LEFT, 1300, SPD_X},
                                                       {Direction::RIGHT, 1600, SPD_X},
                                                       {Direction::RIGHT, 1750, SPD_X},
                                                       {Direction::LEFT, 2050, SPD_X},
                                                       {Direction::LEFT, 2350, SPD_X},
                                                       {Direction::RIGHT, 2750, SPD_X},
                                                       {Direction::LEFT, 3000, SPD_X},
                                                       {Direction::LEFT, 3150, SPD_X},
                                                       {Direction::RIGHT, 3450, SPD_X},
                                                       {Direction::LEFT, 3700, SPD_X},
                                                       {Direction::RIGHT, 4000, SPD_X},
                                                       {Direction::LEFT, 4300, SPD_X},
                                                       {Direction::RIGHT, 4600, SPD_X},
                                                   });
        }
        case 2: {
            double s_x = Engine::SCREEN_WIDTH * 0.0002;
            double s_y = Engine::SCREEN_HEIGHT * 0.0002;
            return new Green_Mode_Manager(2, 11000, {
                                                        {Direction::UP, 3500, s_y},
                                                        {Direction::DOWN, 3750, s_y},
                                                        {Direction::LEFT, 4000, s_x},
                                                        {Direction::DOWN, 4500, s_y},
                                                        {Direction::DOWN, 5000, s_y},
                                                        {Direction::LEFT, 5500, s_x},
                                                        {Direction::RIGHT, 5750, s_x},
                                                        {Direction::RIGHT, 5900, s_x},
                                                        {Direction::UP, 6250, s_y},
                                                        {Direction::LEFT, 6500, s_x},
                                                        {Direction::DOWN, 7000, s_y},
                                                        {Direction::DOWN, 7500, s_y},
                                                        {Direction::UP, 8000, s_y},
                                                        {Direction::DOWN, 8500, s_y},
                                                        {Direction::DOWN, 8650, s_y},
                                                        {Direction::LEFT, 8800, s_x},
                                                        {Direction::RIGHT, 8950, s_x},
                                                        {Direction::LEFT, 9100, s_x},
                                                        {Direction::RIGHT, 9250, s_x},
                                                    });
        }
        case 3: {
            return new Three_Lane_Rising_Arrow_Attack(3, 8500, 450);
        }
        case 4: {
            return new Random_Spawn_Player_Aimed_Arrow_Attack(4, 8500, 400);
        }
        case 5: {
            double sx = Engine::SCREEN_WIDTH * 0.0007;
            double sy = Engine::SCREEN_HEIGHT * 0.0004;
            double sy_fast = Engine::SCREEN_WIDTH * 0.0004;
            return new Green_Mode_Manager(5, 6000, {
                                                       {Direction::RIGHT, 1000, sx},
                                                       {Direction::DOWN, 1750, sy},
                                                       {Direction::LEFT, 2143, sx},
                                                       {Direction::UP, 2500, sy},
                                                       {Direction::LEFT, 2857, sx},
                                                       {Direction::RIGHT, 3750, sy_fast},
                                                       {Direction::DOWN, 4375, sy},
                                                       {Direction::UP, 5000, sy},
                                                   });
        }
        case 6: {
            return new Green_Mode_Manager(6, 5500, {
                                                       {Direction::DOWN, 700, SPD_Y},
                                                       {Direction::DOWN, 850, SPD_Y},
                                                       {Direction::DOWN, 1000, SPD_Y},
                                                       {Direction::DOWN, 1150, SPD_Y},
                                                       {Direction::RIGHT, 1400, SPD_X},
                                                       {Direction::DOWN, 1650, SPD_Y},
                                                       {Direction::DOWN, 1800, SPD_Y},
                                                       {Direction::DOWN, 1950, SPD_Y},
                                                       {Direction::DOWN, 2100, SPD_Y},
                                                       {Direction::LEFT, 2250, SPD_X},
                                                       {Direction::DOWN, 2600, SPD_Y},
                                                       {Direction::DOWN, 2750, SPD_Y},
                                                       {Direction::DOWN, 2900, SPD_Y},
                                                       {Direction::DOWN, 3050, SPD_Y},
                                                       {Direction::RIGHT, 3220, SPD_X},
                                                       {Direction::DOWN, 3550, SPD_Y},
                                                       {Direction::DOWN, 3700, SPD_Y},
                                                       {Direction::DOWN, 3850, SPD_Y},
                                                       {Direction::DOWN, 4000, SPD_Y},
                                                       {Direction::LEFT, 4050, SPD_X},
                                                   });
        }
        case 7: {
            double sx = Engine::SCREEN_WIDTH * 0.0005;
            double sy = Engine::SCREEN_HEIGHT * 0.0005;
            return new Green_Mode_Manager(7, 6500, {
                                                       {Direction::RIGHT, 1067, sx},
                                                       {Direction::DOWN, 1400, sy},
                                                       {Direction::RIGHT, 1667, sx},
                                                       {Direction::DOWN, 2000, sy},
                                                       {Direction::RIGHT, 2233, sx},
                                                       {Direction::DOWN, 2600, sy},
                                                       {Direction::RIGHT, 2833, sx},
                                                       {Direction::DOWN, 3167, sy},
                                                       {Direction::LEFT, 3800, sx, ArrowType::Yellow},
                                                       {Direction::UP, 4067, sy, ArrowType::Yellow},
                                                       {Direction::LEFT, 4400, sx, ArrowType::Yellow},
                                                       {Direction::UP, 4667, sy, ArrowType::Yellow},
                                                       {Direction::LEFT, 5000, sx, ArrowType::Yellow},
                                                       {Direction::UP, 5267, sy, ArrowType::Yellow},
                                                   });
        }
        case 8: {
            return new Inward_Spiraling_Arrow_Ring_Attack(8, 10000, 933);
        }
        case 9: {
            return new Inward_Spiraling_Arrow_Ring_Attack(9, 10000, 933);
        }
        case 10: {
            double sx = Engine::SCREEN_WIDTH * 0.0012;
            double sy = Engine::SCREEN_HEIGHT * 0.0012;
            return new Green_Mode_Manager(10, 7000, {
                                                        {Direction::RIGHT, 1700, sx, ArrowType::Yellow},
                                                        {Direction::UP, 2033, sy, ArrowType::Yellow},
                                                        {Direction::LEFT, 2366, sx, ArrowType::Yellow},
                                                        {Direction::DOWN, 2766, sy, ArrowType::Yellow},
                                                        {Direction::UP, 2966, sy, ArrowType::Blue},
                                                        {Direction::LEFT, 3300, sx, ArrowType::Blue},
                                                        {Direction::DOWN, 3633, sy, ArrowType::Blue},
                                                        {Direction::RIGHT, 3966, sx, ArrowType::Blue},
                                                        {Direction::DOWN, 4766, sy, ArrowType::Yellow},
                                                        {Direction::LEFT, 5100, sx, ArrowType::Yellow},
                                                        {Direction::RIGHT, 5433, sx, ArrowType::Yellow},
                                                        {Direction::UP, 5766, sy, ArrowType::Yellow},
                                                    });
        }
        case 11: {
            return new Green_Mode_Manager(11, 7000, {
                                                        {Direction::RIGHT, 900, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 1234, MED_X, ArrowType::Blue},
                                                        {Direction::DOWN, 1567, MED_Y, ArrowType::Blue},
                                                        {Direction::DOWN, 1867, MED_Y, ArrowType::Yellow},
                                                        {Direction::RIGHT, 2200, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 2467, MED_X, ArrowType::Blue},
                                                        {Direction::UP, 2800, MED_Y, ArrowType::Blue},
                                                        {Direction::UP, 3134, MED_Y, ArrowType::Yellow},
                                                        {Direction::RIGHT, 3500, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 3767, MED_X, ArrowType::Blue},
                                                        {Direction::DOWN, 4134, MED_Y, ArrowType::Blue},
                                                        {Direction::DOWN, 4500, MED_Y, ArrowType::Yellow},
                                                        {Direction::RIGHT, 4800, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 5067, MED_X, ArrowType::Blue},
                                                        {Direction::UP, 5367, MED_Y, ArrowType::Blue},
                                                        {Direction::UP, 5767, MED_Y, ArrowType::Yellow},
                                                    });
        }
        case 12: {
            return new Green_Mode_Manager(12, 7000, {
                                                        {Direction::RIGHT, 800, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 1333, MED_X, ArrowType::Yellow},
                                                        {Direction::UP, 1567, MED_Y, ArrowType::Blue},
                                                        {Direction::DOWN, 2167, MED_Y, ArrowType::Yellow},
                                                        {Direction::LEFT, 2400, MED_X, ArrowType::Blue},
                                                        {Direction::RIGHT, 2933, MED_X, ArrowType::Yellow},
                                                        {Direction::DOWN, 3233, MED_Y, ArrowType::Blue},
                                                        {Direction::UP, 3800, MED_Y, ArrowType::Yellow},
                                                        {Direction::RIGHT, 4067, MED_X, ArrowType::Blue},
                                                        {Direction::LEFT, 4633, MED_X, ArrowType::Yellow},
                                                        {Direction::UP, 4833, MED_Y, ArrowType::Blue},
                                                        {Direction::DOWN, 5433, MED_Y, ArrowType::Yellow},
                                                        {Direction::LEFT, 5667, MED_X, ArrowType::Blue},
                                                        {Direction::RIGHT, 6233, MED_X, ArrowType::Yellow},
                                                    });
        }
        case 13: {
            double sx = Engine::SCREEN_WIDTH * 0.00012;
            double sy = Engine::SCREEN_HEIGHT * 0.00012;
            return new Green_Mode_Manager(13, 12500, {
                                                         {Direction::DOWN, 5733, sy},
                                                         {Direction::LEFT, 5967, sx},
                                                         {Direction::DOWN, 6300, sy},
                                                         {Direction::DOWN, 6567, sy},
                                                         {Direction::RIGHT, 6800, sx},
                                                         {Direction::LEFT, 7067, sx},
                                                         {Direction::UP, 7467, sy},
                                                         {Direction::LEFT, 7733, sx},
                                                         {Direction::DOWN, 7967, sy},
                                                         {Direction::UP, 8133, sy},
                                                         {Direction::RIGHT, 8467, sx},
                                                         {Direction::LEFT, 8667, sx},
                                                         {Direction::UP, 8900, sy},
                                                         {Direction::UP, 9133, sy},
                                                         {Direction::RIGHT, 9467, sx},
                                                         {Direction::LEFT, 9700, sx},
                                                         {Direction::LEFT, 10000, sx},
                                                         {Direction::RIGHT, 10367, sx},
                                                         {Direction::UP, 10667, sy},
                                                         {Direction::UP, 10900, sy},
                                                         {Direction::UP, 11033, sy},
                                                         {Direction::LEFT, 11267, sx},
                                                         {Direction::DOWN, 11600, sy},
                                                         {Direction::DOWN, 11900, sy},
                                                     });
        }
        case 14: {
            return new Contracting_Rotating_Spear_Ring_Attack(14, 12000, Engine::SCREEN_WIDTH * 0.25, [](int time_elapsed) {
                // If 5 seconds passed, spawn faster (333ms), else normal (633ms)
                return (time_elapsed > 5000) ? 333 : 633;
            });
        }
        case 15: {
            return new Inward_Spiraling_Arrow_Ring_Attack(15, 10000, 800);
        }
        default: {
            throw std::exception();
        }
        }
    } else {
        int random_pick = get_random(0, 3);
        const int DURATION = 10000;

        if (random_pick == 0) {
            return new Contracting_Rotating_Spear_Ring_Attack(attack_id, DURATION, Engine::SCREEN_WIDTH * 0.25, [](int time_elapsed) {
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
