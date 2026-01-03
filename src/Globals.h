#pragma once
#include "BattleBox.h"
#include "GameObject.h"
#include "Turn.h"
#include <memory>
#include <vector>

// extern BattleBox *global_battlebox;
extern int time_since_enemy_turn;
// extern int current_attack_idx;
// extern SDL_Event event;
// extern Turn current_turn;
// extern std::vector<Uint8> prev_keyboard_state;
// extern std::vector<Uint8> cur_keyboard_state;

// Direction represents where the arrow points
enum class Direction { UP,
                       DOWN,
                       LEFT,
                       RIGHT };

enum class ArrowType { Blue,
                       Yellow };
