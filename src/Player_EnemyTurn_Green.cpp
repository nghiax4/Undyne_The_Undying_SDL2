#include "Player_EnemyTurn_Green.h"
#include "Arrow_For_Green_Attack.h"
#include "GameObject.h"
#include "HealthPointText.h"
#include "Utils.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

Player_EnemyTurn_Green::Player_EnemyTurn_Green(int x_center, int y_center) : x_center(x_center), y_center(y_center), width(Engine::get().get_screen_width() * 0.03), height(Engine::get().get_screen_width() * 0.03) {
    texture = ResourceManager::get().get_texture("sprites/soul_green.png");
    obj_name = "Player_EnemyTurn_Green";
    z_index = 3;
}

void Player_EnemyTurn_Green::update() {
    time_elapsed_since_invisibility_frame += Engine::get().get_delta_time();
    time_elapsed_since_transparent += Engine::get().get_delta_time();

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

    for (auto &obj : Scene::get().get_objects()) {
        Arrow_For_Green_Attack *arrow = dynamic_cast<Arrow_For_Green_Attack *>(obj.get());
        if (arrow == nullptr)
            continue;

        HealthPointText *healthpoint = static_cast<HealthPointText *>(Scene::get().find_object_by_name("HealthPointText"));

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

void Player_EnemyTurn_Green::render() {
    Engine::get().draw_texture(texture, x_center, y_center, width, height, 0, render_texture_transparent ? 128 : 255);
}
