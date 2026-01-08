#include "White_Arrow_Small_Box_Attack.h"
#include "BattleBox.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include <algorithm>

White_Arrow_Small_Box_Attack::White_Arrow_Small_Box_Attack(double x_center, double y_center, std::string obj_name, Uint32 total_time_before_charge_ms) : m_x_center(x_center), m_y_center(y_center) {
    Transform *battle_box_transform = (Scene::get().find_object_by_name("BattleBox"))->get_component<Transform>();

    m_width = battle_box_transform->m_width * 0.25;
    m_height = m_width / SPRITE_WIDTH_TO_HEIGHT;
    m_texture = ResourceManager::get().get_texture("sprites/white_arrow.png");
    m_obj_name = obj_name;
    m_z_index = 5;

    m_time_getting_ready_ms = std::max(static_cast<Uint32>(0), total_time_before_charge_ms - TIME_FOR_FREEZE);
}

void White_Arrow_Small_Box_Attack::update() {
    const int TIME_FOR_CHARGE = 700;

    m_time_elapsed_since_state_change += Engine::get().get_delta_time();

    if (!m_played_ready_sound) {
        play_sound_effect("audio/white_arrow_getting_ready.ogg");
        m_played_ready_sound = true;
    }

    if (m_state == State::GettingReady && m_time_elapsed_since_state_change > m_time_getting_ready_ms) {
        m_state = State::Freeze;
        m_time_elapsed_since_state_change = 0;
    }

    if (m_state == State::Freeze && m_time_elapsed_since_state_change > TIME_FOR_FREEZE) {
        m_state = State::Charge;
        m_time_elapsed_since_state_change = 0;
        if (!m_played_charge_sound) {
            play_sound_effect("audio/white_arrow_charge.ogg");
            m_played_charge_sound = true;
        }
    }

    if (m_state == State::Charge && m_time_elapsed_since_state_change > TIME_FOR_CHARGE) {
        m_to_be_removed = true;
    }

    if (m_state == State::GettingReady) {
        m_y_center -= GETTING_READY_V_Y * Engine::get().get_delta_time();
    } else if (m_state == State::Freeze) {
    } else {
        m_y_center -= CHARGE_V_Y * Engine::get().get_delta_time();
    }
}

void White_Arrow_Small_Box_Attack::render() {
    Engine::get().draw_texture(m_texture, m_x_center, m_y_center, m_width, m_height);
}
