#include "Player_EnemyTurn.h"
#include "BattleBox.h"
#include "HealthPointText.h"
#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "White_Arrow_Small_Box_Attack.h"

Player_EnemyTurn::Player_EnemyTurn(int x_center, int y_center) : width(SCREEN_WIDTH * 0.03), height(SCREEN_WIDTH * 0.03) {
    texture = loadTexture(renderer, "sprites/soul.png");
    obj_name = "Player_EnemyTurn";
    this->z_index = 3;
}

void Player_EnemyTurn::update() {
    time_elapsed_since_invisibility_frame += deltaTime;
    time_elapsed_since_transparent += deltaTime;

    if (enable_invisbility_frame == true) {
        if (time_elapsed_since_transparent >= 140) {
            render_texture_transparent = !render_texture_transparent;
            time_elapsed_since_transparent = 0;
        }

        if (time_elapsed_since_invisibility_frame >= 700) {
            enable_invisbility_frame = false;
            render_texture_transparent = false;
            time_elapsed_since_invisibility_frame = 0;
        }
    }

    int x_multiplier = 0;
    if (cur_keyboard_state[SDL_SCANCODE_LEFT]) {
        x_multiplier = -1;
    }
    if (cur_keyboard_state[SDL_SCANCODE_RIGHT]) {
        x_multiplier = 1;
    }

    int y_multiplier = 0;
    if (cur_keyboard_state[SDL_SCANCODE_UP]) {
        y_multiplier = -1;
    }
    if (cur_keyboard_state[SDL_SCANCODE_DOWN]) {
        y_multiplier = 1;
    }

    x_center += x_multiplier * v_x * deltaTime;
    y_center += y_multiplier * v_y * deltaTime;

    x_center = std::max(x_center, (double)(global_battlebox->x_center - global_battlebox->width / 2 + width / 2));
    x_center = std::min(x_center, (double)(global_battlebox->x_center + global_battlebox->width / 2 - width / 2));

    y_center = std::max(y_center, (double)(global_battlebox->y_center - global_battlebox->height / 2 + height / 2));
    y_center = std::min(y_center, (double)(global_battlebox->y_center + global_battlebox->height / 2 - height / 2));

    const int PLAYER_ARROW_COLLISION_DISTANCE = 20;

    // First check for White_Arrow_Small_Box_Attack
    for (auto &obj : objs) {
        White_Arrow_Small_Box_Attack *arrow = dynamic_cast<White_Arrow_Small_Box_Attack *>(obj);
        if (arrow == nullptr)
            continue;

        HealthPointText *healthpoint = static_cast<HealthPointText *>(find_object_by_name("HealthPointText"));

        if (distance(x_center, y_center, arrow->x_center, arrow->y_center) <= PLAYER_ARROW_COLLISION_DISTANCE) {
            if (!enable_invisbility_frame) {
                enable_invisbility_frame = true;
                render_texture_transparent = true;
                time_elapsed_since_invisibility_frame = 0;
                healthpoint->hp -= 13;
                play_sound_effect("audio/damage_taken.ogg");
            }
            obj->to_be_removed = true;
            break;
        }
    }

    // Second check for White_Arrow_Medium_Box_Attack
    for (auto &obj : objs) {
        White_Arrow_Medium_Box_Attack *arrow = dynamic_cast<White_Arrow_Medium_Box_Attack *>(obj);
        if (arrow == nullptr)
            continue;

        HealthPointText *healthpoint = static_cast<HealthPointText *>(find_object_by_name("HealthPointText"));

        if (distance(x_center, y_center, arrow->x_center, arrow->y_center) <= PLAYER_ARROW_COLLISION_DISTANCE) {
            if (!enable_invisbility_frame) {
                enable_invisbility_frame = true;
                render_texture_transparent = true;
                time_elapsed_since_invisibility_frame = 0;
                healthpoint->hp -= 13;
                play_sound_effect("audio/damage_taken.ogg");
            }
            obj->to_be_removed = true;
            break;
        }
    }

    // Third check for Spinning_Arrow
    for (auto &obj : objs) {
        Spinning_Arrow *arrow = dynamic_cast<Spinning_Arrow *>(obj);
        if (arrow == nullptr)
            continue;

        HealthPointText *healthpoint = static_cast<HealthPointText *>(find_object_by_name("HealthPointText"));

        if (distance(x_center, y_center, arrow->x_center, arrow->y_center) <= PLAYER_ARROW_COLLISION_DISTANCE) {
            if (!enable_invisbility_frame) {
                enable_invisbility_frame = true;
                render_texture_transparent = true;
                time_elapsed_since_invisibility_frame = 0;
                healthpoint->hp -= 13;
                play_sound_effect("audio/damage_taken.ogg");
            }
            obj->to_be_removed = true;
            break;
        }
    }
}

void Player_EnemyTurn::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, render_texture_transparent ? 128 : 255);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}