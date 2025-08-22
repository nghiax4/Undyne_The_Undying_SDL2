#include "GameObject.h"
#include "stdio.h"
#include "stdlib.h"
#include <SDL2/SDL.h>
#include <string>

struct Player : public GameObject {
    int x_center, y_center, width, height;
    SDL_Texture *player_texture;

    Player(int x_center, int y_center, int width, int height, std::string path, int z_index);

    virtual void update() override;

    virtual void render() override;
};