#include "CFG.h"

CFG::CFG(){
    //ctor
}

CFG::~CFG(){
    //dtor
}

MenuManager* CFG::menuManager = new MenuManager();

int CFG::WINDOW_WIDTH = 360;
int CFG::WINDOW_HEIGHT = 720;

MenuManager* CFG::getMM(){
    return menuManager;
}
