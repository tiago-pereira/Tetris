#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "MainMenu.h"
#include "SDL2/SDL.h"

class MenuManager
{
    public:
        MenuManager();
        virtual ~MenuManager();

        enum GameState {
            eMainMenu,
            eGameLoading,
            eGame,
            eAbout,
            eOptions,
            ePause,
        };

        int getCurrentStateID();

        void draw(SDL_Renderer *renderer);
        void update(SDL_Renderer *renderer);
    protected:
    private:
        GameState currentGameState;

        MainMenu* mainMenu;
};

#endif // MENUMANAGER_H
