#include "Player_EnemyTurn.h"
#include "BattleBox.h"
#include "HealthPointText.h"
#include "Ring_Spear.h"
#include "Spinning_Arrow.h"
#include "Utils.h"
#include "White_Arrow_Medium_Box_Attack.h"
#include "White_Arrow_Small_Box_Attack.h"
#include "core/Engine.h"
#include "core/Scene.h"
#include "core/Input.h"

template <typename AttackType>
void apply_collision_logic_for_type(Player_EnemyTurn *player) {
    const double PLAYER_ARROW_COLLISION_DISTANCE = 20.0;
    const int DAMAGE_AMOUNT = 13;

    HealthPointText *hp_text_obj = static_cast<HealthPointText *>(Scene::get().find_object_by_name("HealthPointText"));

    for (auto &game_obj : Scene::get().get_objects()) {
        AttackType *specific_attack = dynamic_cast<AttackType *>(game_obj.get());

        if (specific_attack == nullptr)
            continue;

        double distance_to_attack = distance(player->x_center, player->y_center, specific_attack->x_center, specific_attack->y_center);
        bool is_colliding = distance_to_attack <= PLAYER_ARROW_COLLISION_DISTANCE;

        if (is_colliding) {
            if (!player->enable_invisbility_frame) {
                player->enable_invisbility_frame = true;
                player->render_texture_transparent = true;
                player->time_elapsed_since_invisibility_frame = 0;

                hp_text_obj->hp -= DAMAGE_AMOUNT;
                play_sound_effect("audio/damage_taken.ogg");
            }
            game_obj->to_be_removed = true;
        }
    }
}

Player_EnemyTurn::Player_EnemyTurn(int x_center, int y_center) : v_x(Engine::get().get_screen_width() * 0.0003), v_y(Engine::get().get_screen_width() * 0.0003), x_center(x_center), y_center(y_center), width(Engine::get().get_screen_width() * 0.03), height(Engine::get().get_screen_width() * 0.03) {
    texture = ResourceManager::get().get_texture("sprites/soul.png");
    obj_name = "Player_EnemyTurn";
    this->z_index = 3;
}

void Player_EnemyTurn::update() {
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

    int x_multiplier = 0;
    if (Input::get().is_key_down(SDL_SCANCODE_LEFT)) {
        x_multiplier = -1;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_RIGHT)) {
        x_multiplier = 1;
    }

    int y_multiplier = 0;
    if (Input::get().is_key_down(SDL_SCANCODE_UP)) {
        y_multiplier = -1;
    }
    if (Input::get().is_key_down(SDL_SCANCODE_DOWN)) {
        y_multiplier = 1;
    }

    x_center += x_multiplier * v_x * Engine::get().get_delta_time();
    y_center += y_multiplier * v_y * Engine::get().get_delta_time();

    x_center = std::max(x_center, (double)(global_battlebox->x_center - global_battlebox->width / 2 + width / 2));
    x_center = std::min(x_center, (double)(global_battlebox->x_center + global_battlebox->width / 2 - width / 2));

    y_center = std::max(y_center, (double)(global_battlebox->y_center - global_battlebox->height / 2 + height / 2));
    y_center = std::min(y_center, (double)(global_battlebox->y_center + global_battlebox->height / 2 - height / 2));

    apply_collision_logic_for_type<White_Arrow_Small_Box_Attack>(this);
    apply_collision_logic_for_type<White_Arrow_Medium_Box_Attack>(this);
    apply_collision_logic_for_type<Spinning_Arrow>(this);
    apply_collision_logic_for_type<Ring_Spear>(this);
}

void Player_EnemyTurn::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), (int)width, (int)height};
    SDL_SetTextureBlendMode(texture.get(), SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture.get(), render_texture_transparent ? 128 : 255);
    SDL_RenderCopy(Engine::get().get_renderer(), texture.get(), NULL, &rect);
}
