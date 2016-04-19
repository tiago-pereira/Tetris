#ifndef PROGRAM_H
#define PROGRAM_H

#include <SDL2/SDL.h>
#include "Board.h"
#include "Piece.h"

class Program
{
    public:
        Program();
        virtual ~Program();
        bool start();
    protected:
    private:

        void update();
        void draw();
        void handleInput();
        void handlePlayerInput();
        void check(const Piece &p);
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event mainEvent;

        Board board;
        Piece piece;
        uint32_t moveTime;
};

#endif // PROGRAM_H
