#include "BattleText.h"
#include "BattleBox.h"
#include "GameManager.h"
#include "GameplayTypes.h"
#include "Turn.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include <algorithm>
#include <cassert>

BattleText::BattleText() {
    m_obj_name = "BattleText";
    m_z_index = 3;

    m_font = ResourceManager::get().get_font("fonts/determination-mono.otf", static_cast<int>(Engine::SCREEN_HEIGHT * 0.07));
    // printf("[DEBUG] BattleText created\n");
}

void BattleText::update() {
    m_time_elapsed_since_spawn += Engine::get().get_delta_time();

    if (static_cast<GameManager *>(Scene::get().find_object_by_name("GameManager"))->m_current_turn != Turn::PlayerTurn) {
        m_to_be_removed = true;
        return;
    }
}

void BattleText::render() {
    // Calculate how many characters to show
    // Ratio: (current_time / total_time) * total_chars
    double progress = std::min(1.0, m_time_elapsed_since_spawn / TOTAL_DURATION_MS);
    size_t char_count = static_cast<size_t>(progress * m_full_text.length());

    std::string current_text(m_full_text.substr(0, char_count));

    if (current_text.empty())
        return;

    SDL_Color color{255, 255, 255, 0};
    // int wrap_width = static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->width * 0.9;

    double padding_x = Engine::SCREEN_WIDTH * 0.023;
    double padding_y = Engine::SCREEN_HEIGHT * 0.048;
    double x_pos = (static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_x_center - static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_width / 2) + padding_x;
    double y_pos = (static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_y_center - static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->m_height / 2) + padding_y;

    Engine::get().draw_text(m_font, current_text.c_str(), static_cast<int>(x_pos), static_cast<int>(y_pos), color, false);
}
