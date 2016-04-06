#include "Game.h"
#include <iostream>
#include <stdio.h>
#include "constants.h"

Game::Game():piece(static_cast<Piece::Type>(rand() % 7)),moveTime(SDL_GetTicks()){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error SDL_Init(SDL_INIT_VIDEO)");
    }

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL, &window, &renderer);
    SDL_SetWindowPosition(window, 500, 126);
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::loop(){

    SDL_Event event;


    if (SDL_WaitEventTimeout(&event, 250)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_DOWN: {
                        Piece p = piece;
                        p.move(0,1);
                        if (!board.isCollision(p)) {
                            piece = p;
                        }
                    }
                    break;
                    case SDLK_RIGHT: {
                        Piece p = piece;
                        p.move(1,0);
                        if (!board.isCollision(p)) {
                            piece = p;
                        }
                    }
                    break;
                    case SDLK_LEFT: {
                        Piece p = piece;
                        p.move(-1,0);
                        if (!board.isCollision(p)) {
                            piece = p;
                        }
                    }
                    break;
                    case SDLK_UP: {
                        Piece p = piece;
                        p.rotate();
                        if (!board.isCollision(p)) {
                            piece = p;
                        }
                    }
                    break;
                }
            }
            break;
            case SDL_QUIT:
                return false;
        }
    }


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer);

    board.render(renderer);
    piece.render(renderer);



    if (SDL_GetTicks() > moveTime) {
        Piece p = piece;
        p.move(0, 1);
        moveTime += 1000;
        check(p);

    }



    SDL_RenderPresent(renderer);


    return true;
}

void Game::check(const Piece &p){
  if (board.isCollision(p)) {
    board.unite(piece);
    piece = Piece{static_cast<Piece::Type>(rand() % 7)};

    if (board.isCollision(piece)){
        //restarts game
      board = Board();
    }
  } else {
    piece = p;
  }
}
