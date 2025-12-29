#include "Arrow_For_Green_Attack.h"
#include "Player_EnemyTurn_Green.h"
#include "Shield.h"
#include "Utils.h"
#include <algorithm>

Arrow_For_Green_Attack::Arrow_For_Green_Attack(double x_center, double y_center, double v_x, double v_y, Direction direction, std::string obj_name, ArrowType arrow_type) : x_center(x_center), y_center(y_center), v_x(v_x), v_y(v_y), direction(direction), arrow_type(arrow_type) {
    height = SCREEN_HEIGHT * 0.06;
    width = height * SPRITE_WIDTH_TO_HEIGHT_RATIO;

    this->obj_name = obj_name;
    z_index = 4;

    std::string sprite_path = arrow_type == ArrowType::Yellow ? "sprites/down_arrow_yellow.png" : "sprites/down_arrow.png";
    texture.reset(loadTexture(renderer, sprite_path));
}

void Arrow_For_Green_Attack::update() {
    if (state == State::APPROACHING_BEFORE_ROTATE || state == State::APPROACHING_AFTER_ROTATE) {
        x_center += v_x * deltaTime;
        y_center += v_y * deltaTime;
    }

    Player_EnemyTurn_Green *player = static_cast<Player_EnemyTurn_Green *>(find_object_by_name("Player_EnemyTurn_Green"));

    if (arrow_type == ArrowType::Yellow && state == State::APPROACHING_BEFORE_ROTATE) {
        double dist = distance(x_center, y_center, player->x_center, player->y_center);

        if (dist <= DISTANCE_FROM_SOUL_TO_FLIP) {
            state = State::ROTATING;
            orbit_radius = dist;

            double dx = x_center - player->x_center;
            double dy = y_center - player->y_center;
            // angle relative to soul
            orbit_angle_deg = std::atan2(dy, dx) * 180.0 / M_PI;

            target_orbit_angle_deg = orbit_angle_deg + 180.0;
        }
    }

    if (state == State::ROTATING) {
        double rotation_speed = ROTATION_SPEED_DEGREE_PER_MS * deltaTime;

        orbit_angle_deg = std::min(orbit_angle_deg + rotation_speed, target_orbit_angle_deg);

        double orbit_angle_rad = orbit_angle_deg * M_PI / 180.0;
        x_center = player->x_center + orbit_radius * std::cos(orbit_angle_rad);
        y_center = player->y_center + orbit_radius * std::sin(orbit_angle_rad);

        // While equality for double is discouraged, equality is guaranteed to happen here due to min() above
        if (orbit_angle_deg == target_orbit_angle_deg) {
            state = State::APPROACHING_AFTER_ROTATE;
            double current_speed = std::sqrt(v_x * v_x + v_y * v_y);

            if (direction == Direction::LEFT) {
                v_x = -current_speed;
                v_y = 0;
            } else if (direction == Direction::RIGHT) {
                v_x = current_speed;
                v_y = 0;
            } else if (direction == Direction::UP) {
                v_x = 0;
                v_y = -current_speed;
            } else if (direction == Direction::DOWN) {
                v_x = 0;
                v_y = current_speed;
            }
        }
    }

    if (object_by_name_exists("Shield")) {
        Shield *shield = static_cast<Shield *>(find_object_by_name("Shield"));

        if (distance(x_center, y_center, shield->x_center, shield->y_center) <= 20) {
            play_sound_effect("audio/shield_reflect.ogg");
            this->to_be_removed = true;
        }
    }
}

void Arrow_For_Green_Attack::render() {
    SDL_Rect rect{(int)(x_center - width / 2), (int)(y_center - height / 2), width, height};

    int angle;
    if (direction == Direction::DOWN) {
        angle = 0;
    }
    if (direction == Direction::RIGHT) {
        angle = 270;
    }
    if (direction == Direction::UP) {
        angle = 180;
    }
    if (direction == Direction::LEFT) {
        angle = 90;
    }

    SDL_RenderCopyEx(renderer, texture.get(), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}