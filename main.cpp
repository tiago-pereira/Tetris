
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Game.h"
#include <iostream>
#include "constants.h"

int main(int argc, char* args[]) {

    Game game;
    while (game.loop());

    return 0;
}
