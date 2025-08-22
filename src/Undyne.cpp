#include "Undyne.h"
#include "Utils.h"

Undyne::Undyne(int x_center, int y_center, int height) : x_center(x_center), y_center(y_center), height(height), width(height * UNDYNE_SPRITE_WIDTH_OVER_HEIGHT) { obj_name = "Undyne"; }

void Undyne::update() {
    time_elapsed_since_last_sprite_frame += deltaTime;
    if (time_elapsed_since_last_sprite_frame > MILLISECOND_BETWEEN_SPRITE_FRAME) {
        current_sprite_frame = (current_sprite_frame + 1) % NUM_OF_SPRITE_FRAMES;
        time_elapsed_since_last_sprite_frame = 0;
    }
}

void Undyne::render() {
    std::string current_sprite_frame_correctlength = std::to_string(current_sprite_frame);
    while (current_sprite_frame_correctlength.size() < 3)
        current_sprite_frame_correctlength = "0" + current_sprite_frame_correctlength;
    std::string sprite_filename = "sprites/undyne_sprite/frame_" + current_sprite_frame_correctlength + ".png";

    SDL_Texture *texture = loadTexture(renderer, sprite_filename);
    SDL_Rect *rect = new SDL_Rect({x_center - width / 2, y_center - height / 2, width, height});
    SDL_RenderCopy(renderer, texture, NULL, rect);
}