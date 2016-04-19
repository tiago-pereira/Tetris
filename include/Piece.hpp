#ifndef PIECE_H
#define PIECE_H

#include <SDL2/SDL.h>
#include "constants.h"

class Piece
{
    public:
        enum Type { I = 0, J, L, O, S, T, Z };

        Piece(Type);
        virtual ~Piece();
        void render(SDL_Renderer *renderer);
        void move(int dx, int dy);
        void rotate();
        bool isBlock(int x, int y) const;
        int getX() const;
        int getY() const;
    protected:
    private:
        Type type;
        int x;
        int y;
        int angle;
};

#endif // PIECE_H
