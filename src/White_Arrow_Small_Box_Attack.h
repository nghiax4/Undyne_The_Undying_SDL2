#pragma once
#include "GameObject.h"

#include "Utils.h"
#include "core/Engine.h"

struct White_Arrow_Small_Box_Attack : public GameObject {
    static constexpr double SPRITE_WIDTH_TO_HEIGHT = 60.0 / 196;
    static constexpr double GETTING_READY_V_Y = Engine::SCREEN_HEIGHT * 0.00015;
    static constexpr double CHARGE_V_Y = Engine::SCREEN_HEIGHT * 0.0008;

    bool m_played_ready_sound = false;
    bool m_played_charge_sound = false;

    enum class State { GettingReady,
                       Freeze,
                       Charge };
    State m_state = State::GettingReady;
    double m_x_center, m_y_center, m_width, m_height;
    Uint32 m_time_elapsed_since_state_change = 0;

    Uint32 m_time_getting_ready_ms;
    static constexpr Uint32 TIME_FOR_FREEZE = 250;

    SmartTexture m_texture;

    White_Arrow_Small_Box_Attack(double x_center, double y_center, std::string obj_name, Uint32 total_time_before_charge_ms = 750);

    virtual void update() override;
    virtual void render() override;
};
