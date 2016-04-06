#include "Board.h"

Board::Board():grid{{false}}{
    //ctor
}

Board::~Board(){
    //dtor
}


void Board::render(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xf0);
    for (int x = 0; x < blockCountX; ++x) {
        for (int y = 0; y < blockCountY; ++y){
            if (grid[x][y]) {
                SDL_Rect rect;
                rect.x = x * WINDOW_WIDTH / blockCountX + 1;
                rect.y = y * WINDOW_WIDTH / blockCountX + 1;
                rect.w = WINDOW_WIDTH / blockCountX - 2;
                rect.h = WINDOW_WIDTH / blockCountX - 2;

                SDL_RenderFillRect(renderer, &rect);
            } else {
                SDL_RenderDrawPoint(renderer, x * WINDOW_WIDTH / blockCountX + WINDOW_WIDTH / blockCountX / 2,
                                  y * WINDOW_WIDTH / blockCountX + WINDOW_WIDTH / blockCountX / 2);
            }
        }
    }

}

bool Board::isCollision(const Piece &t) const
{
  for (int x = 0; x < 4; ++x)
    for (int y = 0; y < 4; ++y)
      if (t.isBlock(x, y)){
        int wx = t.getX() + x;
        int wy = t.getY() + y;
        if (wx < 0 || wx >= blockCountX || wy < 0 || wy >= blockCountY)
          return true;
        if (grid[wx][wy])
          return true;
      }
  return false;
}

void Board::unite(const Piece &t) {
    for (int x = 0; x < 4; ++x){
        for (int y = 0; y < 4; ++y){
            if (t.isBlock(x, y)) {
                grid[t.getX() + x][t.getY() + y] = true;
            }
        }
    }


    verifyLines();
}

void Board::verifyLines(){
    for (int y = blockCountY - 1; y >= 0; --y) {
    bool solid = true;
    for (int x = 0; x < blockCountX; ++x) {
      if (!grid[x][y]) {
        solid = false;
        break;
      }
    }

    if (solid) {
        for (int yy = y - 1; yy >= 0; --yy) {
            for (int x = 0; x < blockCountX; ++x){
                grid[x][yy + 1] = grid[x][yy];
            }
        }
      //for (int x = 0; x < blockCountX; ++x)
        //grid[x][0] = false;
        verifyLines();
    }
  }
}
