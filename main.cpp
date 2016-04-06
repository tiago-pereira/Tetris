
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"

int main(int argc, char* args[]) {

    Game game;
    while (game.loop());

    return 0;
}
