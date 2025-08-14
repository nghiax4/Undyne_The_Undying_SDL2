#include "game.cpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

int main(int argc, char *args[]) {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
    while (game.running) {
        game.update();
    }
    return 0;
}
