#include "Undyne.h"
#include "Utils.h"
#include "core/Engine.h"

Undyne::Undyne(double x_center, double y_center, double height) {
    m_obj_name = "Undyne";

    double width = height * UNDYNE_SPRITE_WIDTH_OVER_HEIGHT;
    add_component<Transform>(x_center, y_center, width, height);

    printf("[DEBUG] Loading Undyne sprites...\n");
    for (int i = 0; i < NUM_OF_SPRITE_FRAMES; ++i) {
        std::string frame_num = std::to_string(i);
        while (frame_num.size() < 3)
            frame_num = "0" + frame_num;

        std::string path = "sprites/undyne_sprite/frame_" + frame_num + ".png";

        m_sprite_frames.push_back(ResourceManager::get().get_texture(path));
    }
}

void Undyne::update() {
    m_time_elapsed_since_last_sprite_frame += Engine::get().get_delta_time();
    if (m_time_elapsed_since_last_sprite_frame >= MILLISECOND_BETWEEN_SPRITE_FRAME) {
        m_current_sprite_frame = (m_current_sprite_frame + 1) % NUM_OF_SPRITE_FRAMES;
        // Subtract precisely to preserve fractional time drifts rather than hard reset to 0
        m_time_elapsed_since_last_sprite_frame -= MILLISECOND_BETWEEN_SPRITE_FRAME;
    }
}

void Undyne::render() {
    Transform *transform = get_component<Transform>();
    Engine::get().draw_texture(m_sprite_frames[m_current_sprite_frame], transform->m_x_center, transform->m_y_center, transform->m_width, transform->m_height);
}
