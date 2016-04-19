#ifndef MAINMENU_H
#define MAINMENU_H

#include "SDL2/SDL.h"

class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void draw(SDL_Renderer *renderer);
    protected:
    private:
};

#endif // MAINMENU_H
