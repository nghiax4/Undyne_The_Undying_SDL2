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
    obj_name = "BattleText";
    z_index = 3;

    int font_size = Engine::get().get_screen_height() * 0.07;
    font = ResourceManager::get().get_font("fonts/determination-mono.otf", font_size);
    // printf("[DEBUG] BattleText created\n");
}

void BattleText::update() {
    time_elapsed_since_spawn += Engine::get().get_delta_time();

    if (static_cast<GameManager *>(Scene::get().find_object_by_name("GameManager"))->current_turn != Turn::PlayerTurn) {
        this->to_be_removed = true;
        return;
    }
}

void BattleText::render() {
    // Calculate how many characters to show
    // Ratio: (current_time / total_time) * total_chars
    double progress = std::min(1.0, time_elapsed_since_spawn / TOTAL_DURATION_MS);
    int char_count = static_cast<int>(progress * full_text.length());

    std::string current_text = full_text.substr(0, char_count);

    if (current_text.empty())
        return;

    SDL_Color color{255, 255, 255, 0};
    // int wrap_width = static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->width * 0.9;

    int padding_x = Engine::get().get_screen_width() * 0.023;
    int padding_y = Engine::get().get_screen_height() * 0.048;
    int x_pos = (static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->x_center - static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->width / 2) + padding_x;
    int y_pos = (static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->y_center - static_cast<BattleBox *>(Scene::get().find_object_by_name("BattleBox"))->height / 2) + padding_y;

    Engine::get().draw_text(font, current_text.c_str(), x_pos, y_pos, color, false);
}
