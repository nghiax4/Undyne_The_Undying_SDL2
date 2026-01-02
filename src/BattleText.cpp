#include "BattleText.h"
#include "Globals.h"
#include <algorithm>
#include <cassert>

BattleText::BattleText() {
    obj_name = "BattleText";
    z_index = 3;

    int font_size = SCREEN_HEIGHT * 0.07;
    font.reset(TTF_OpenFont("fonts/determination-mono.otf", font_size));
    // printf("[DEBUG] BattleText created\n");
}

void BattleText::update() {
    time_elapsed_since_spawn += deltaTime;

    if (current_turn != Turn::PlayerTurn) {
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

    SDL_Color color = {255, 255, 255};
    int wrap_width = global_battlebox->width * 0.9;

    // TTF_RenderText_Blended_Wrapped may return NULL if current_text is empty
    if (!current_text.empty()) {
        SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(font.get(), current_text.c_str(), color, wrap_width);

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        int padding_x = SCREEN_WIDTH * 0.023;
        int padding_y = SCREEN_HEIGHT * 0.048;

        int x_pos = (global_battlebox->x_center - global_battlebox->width / 2) + padding_x;
        int y_pos = (global_battlebox->y_center - global_battlebox->height / 2) + padding_y;

        SDL_Rect dst_rect = {x_pos, y_pos, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dst_rect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}
