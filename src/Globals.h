#pragma once
#include "GameObject.h"
#include "Turn.h"
#include <vector>

extern std::vector<GameObject *> objs;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Renderer *renderer;
extern int time_since_enemy_turn;
extern int current_attack_idx;
extern double deltaTime;
extern SDL_Event event;
extern Turn current_turn;
extern std::vector<Uint8> prev_keyboard_state;
extern std::vector<Uint8> cur_keyboard_state;

enum class Direction { UP, DOWN, LEFT, RIGHT };