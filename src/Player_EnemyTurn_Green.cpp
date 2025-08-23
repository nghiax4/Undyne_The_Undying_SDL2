#include "Player_EnemyTurn_Green.h"
#include "GameObject.h"
#include "Utils.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

Player_EnemyTurn_Green::Player_EnemyTurn_Green(int x_center, int y_center) : x_center(x_center), y_center(y_center), width(SCREEN_WIDTH * 0.03), height(SCREEN_WIDTH * 0.03) {
    player_texture = loadTexture(renderer, "sprites/soul_green.png");
    obj_name = "Player_EnemyTurn_Green";
    z_index = 2;
}

void Player_EnemyTurn_Green::update() {}

void Player_EnemyTurn_Green::render() {
    SDL_Rect rect{x_center - width / 2, y_center - height / 2, width, height};
    SDL_RenderCopy(renderer, player_texture, NULL, &rect);
}