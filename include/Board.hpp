#ifndef BOARD_H
#define BOARD_H

#include <SDL2/SDL.h>
#include "constants.h"
#include "Piece.h"

class Board
{
    public:
        Board();
        virtual ~Board();
        void render(SDL_Renderer *renderer);
        enum { blockCountX = 10, blockCountY = 20 };
        bool isCollision(const Piece &t) const;
        void unite(const Piece &);
    protected:
    private:
        void verifyLines();
        bool grid[blockCountX][blockCountY];
};

#endif // BOARD_H
