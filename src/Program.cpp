#include "Program.h"
#include "CFG.h"
#include "MenuManager.h"

Program::Program():piece(static_cast<Piece::Type>(rand() % 7)),moveTime(SDL_GetTicks()){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error SDL_Init(SDL_INIT_VIDEO)");
    }

    SDL_CreateWindowAndRenderer(CFG::WINDOW_WIDTH, CFG::WINDOW_HEIGHT, SDL_WINDOW_OPENGL, &window, &renderer);
    SDL_SetWindowPosition(window, 500, 126);
}

Program::~Program(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Program::start(){

    while(mainEvent.type != SDL_QUIT) {

        SDL_WaitEventTimeout(&mainEvent, 250);

        handleInput();
        update();
        draw();
    }

}

void Program::update(){

}

void Program::draw(){

}

void Program::handlePlayerInput(){


        switch (mainEvent.type) {
            case SDL_KEYDOWN: {
                Piece p = piece;

                switch (mainEvent.key.keysym.sym) {
                    case SDLK_DOWN: {
                        p.move(0,1);
                    }
                    break;
                    case SDLK_RIGHT: {
                        p.move(1,0);
                    }
                    break;
                    case SDLK_LEFT: {
                        p.move(-1,0);
                    }
                    break;
                    case SDLK_UP: {
                        p.rotate();
                    }
                    break;
                }

                switch (mainEvent.key.keysym.sym) {
                    case SDLK_DOWN:
                    case SDLK_RIGHT:
                    case SDLK_LEFT:
                    case SDLK_UP:
                        if (!board.isCollision(p)){
                            piece = p;
                        }
                    break;
                    default:
                    break;
                }




            }
            break;
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

}

void Program::handleInput(){

    switch(CFG::getMM()->getCurrentStateID()){
        case MenuManager::eMainMenu: {
            handlePlayerInput();
        }
        break;
        case MenuManager::eGame: {
            handlePlayerInput();
        }
        break;
        default:{
        }
        break;
    }



    SDL_RenderPresent(renderer);

}

void Program::check(const Piece &p){
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
