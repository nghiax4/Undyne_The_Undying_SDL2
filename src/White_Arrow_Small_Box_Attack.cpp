#include "White_Arrow_Small_Box_Attack.h"
#include "BattleBox.h"
#include "Utils.h"

White_Arrow_Small_Box_Attack::White_Arrow_Small_Box_Attack(double x_center, double y_center, std::string obj_name) : x_center(x_center), y_center(y_center) {
    BattleBox *battlebox = static_cast<BattleBox *>(find_object_by_name("BattleBox"));
    width = battlebox->width * 0.25;
    height = width / SPRITE_WIDTH_TO_HEIGHT;
    texture = loadTexture(renderer, "sprites/white_arrow.png");
    this->obj_name = obj_name;
    this->z_index = 5;
}

void White_Arrow_Small_Box_Attack::update() {
    const int TIME_FOR_GETTING_READY = 500;
    const int TIME_FOR_FREEZE = 250;
    const int TIME_FOR_CHARGE = 700;

    time_elapsed_since_state_change += deltaTime;

    if (!played_ready_sound) {
        play_sound_effect("audio/white_arrow_getting_ready.ogg");
        played_ready_sound = true;
    }

    if (state == State::GettingReady && time_elapsed_since_state_change > TIME_FOR_GETTING_READY) {
        state = State::Freeze;
        time_elapsed_since_state_change = 0;
    }

    if (state == State::Freeze && time_elapsed_since_state_change > TIME_FOR_FREEZE) {
        state = State::Charge;
        time_elapsed_since_state_change = 0;
        if (!played_charge_sound) {
            play_sound_effect("audio/white_arrow_charge.ogg");
            played_charge_sound = true;
        }
    }

    if (state == State::Charge && time_elapsed_since_state_change > TIME_FOR_CHARGE) {
        this->to_be_removed = true;
    }

    if (state == State::GettingReady) {
        y_center -= GETTING_READY_V_Y * deltaTime;
    } else if (state == State::Freeze) {
    } else {
        y_center -= CHARGE_V_Y * deltaTime;
    }
}

void White_Arrow_Small_Box_Attack::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}