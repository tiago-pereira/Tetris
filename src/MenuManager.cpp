#include "MenuManager.h"

MenuManager::MenuManager():
    currentGameState(eMainMenu),
    mainMenu(new MainMenu())
{}

MenuManager::~MenuManager()
{
    //dtor
}

int MenuManager::getCurrentStateID(){
    return currentGameState;
}


void MenuManager::draw(SDL_Renderer *renderer){
}

void MenuManager::update(SDL_Renderer *renderer){
    switch(currentGameState){
        case eMainMenu:{
            mainMenu->draw(renderer);
        }
        break;
        case eGame: {
        }
        break;
        default:
        break;
    }
}
