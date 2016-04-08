#include "Piece.h"
#include "CFG.h"

Piece::Piece(Type type):type(type),x(10/2-4/2),y(0),angle(0){
    //ctor
}

Piece::~Piece(){
    //dtor
}

void Piece::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Piece::getX() const {
    return x;
}

int Piece::getY() const {
    return y;
}

void Piece::rotate()
{
  angle += 3;
  angle %= 4;
}

void Piece::render(SDL_Renderer *renderer) {

    switch (type){
        case I:
            SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
        break;
        case J:
            SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, 0xff);
        break;
        case L:
            SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0xff, 0xff);
        break;
        case O:
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x7f, 0xff);
        break;
        case S:
            SDL_SetRenderDrawColor(renderer, 0xff, 0x7f, 0x00, 0xff);
        break;
        case T:
            SDL_SetRenderDrawColor(renderer, 0x7f, 0x40, 0x00, 0xff);
        break;
        case Z:
            SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);
        break;
    }

    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < 4; ++j) {
            if (isBlock(k, j)){
                SDL_Rect rect{(k + x) * CFG::WINDOW_WIDTH / 10 + 1, (j + y) * CFG::WINDOW_WIDTH / 10 + 1, CFG::WINDOW_WIDTH / 10 - 2, CFG::WINDOW_WIDTH / 10 - 2};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

bool Piece::isBlock(int x, int y) const {
  static const char *Shapes[][4] = {
    {
      " *  "
      " *  "
      " *  "
      " *  ",
      "    "
      "****"
      "    "
      "    ",
      " *  "
      " *  "
      " *  "
      " *  ",
      "    "
      "****"
      "    "
      "    ",
    },
    {
      "  * "
      "  * "
      " ** "
      "    ",
      "    "
      "*   "
      "*** "
      "    ",
      " ** "
      " *  "
      " *  "
      "    ",
      "    "
      "    "
      "*** "
      "  * ",
    },
    {
      " *  "
      " *  "
      " ** "
      "    ",
      "    "
      "*** "
      "*   "
      "    ",
      " ** "
      "  * "
      "  * "
      "    ",
      "  * "
      "*** "
      "    "
      "    ",
    },
    {
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
    },
    {
      "  * "
      " ** "
      " *  "
      "    ",
      "    "
      "**  "
      " ** "
      "    ",
      "  * "
      " ** "
      " *  "
      "    ",
      "    "
      "**  "
      " ** "
      "    ",
    },
    {
      " *  "
      " ** "
      " *  "
      "    ",
      "    "
      "*** "
      " *  "
      "    ",
      " *  "
      "**  "
      " *  "
      "    ",
      " *  "
      "*** "
      "    "
      "    ",
    },
    {
      " *  "
      " ** "
      "  * "
      "    ",
      "    "
      " ** "
      "**  "
      "    ",
      " *  "
      " ** "
      "  * "
      "    ",
      "    "
      " ** "
      "**  "
      "    ",
    },
  };
  return Shapes[type][angle][x + y * 4] == '*';
}
