#include "Undyne.h"
#include "Utils.h"
#include "core/Engine.h"

Undyne::Undyne(int x_center, int y_center, int height) : x_center(x_center), y_center(y_center), height(height), width(height * UNDYNE_SPRITE_WIDTH_OVER_HEIGHT) {
    obj_name = "Undyne";

    printf("[DEBUG] Loading Undyne sprites...\n");
    for (int i = 0; i < NUM_OF_SPRITE_FRAMES; ++i) {
        std::string frame_num = std::to_string(i);
        while (frame_num.size() < 3)
            frame_num = "0" + frame_num;

        std::string path = "sprites/undyne_sprite/frame_" + frame_num + ".png";

        sprite_frames.push_back(ResourceManager::get().get_texture(path));
    }
}

void Undyne::update() {
    time_elapsed_since_last_sprite_frame += Engine::get().get_delta_time();
    if (time_elapsed_since_last_sprite_frame >= MILLISECOND_BETWEEN_SPRITE_FRAME) {
        current_sprite_frame = (current_sprite_frame + 1) % NUM_OF_SPRITE_FRAMES;
        // Subtract precisely to preserve fractional time drifts rather than hard reset to 0
        time_elapsed_since_last_sprite_frame -= MILLISECOND_BETWEEN_SPRITE_FRAME;
    }
}

void Undyne::render() {
    SDL_Texture *texture = sprite_frames[current_sprite_frame].get();
    SDL_Rect rect = {x_center - width / 2, y_center - height / 2, width, height};

    SDL_RenderCopy(Engine::get().get_renderer(), texture, NULL, &rect);
}
