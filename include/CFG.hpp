#ifndef CFG_H
#define CFG_H

#include "MenuManager.h"

class CFG
{
    public:
        CFG();
        virtual ~CFG();

        static int WINDOW_WIDTH, WINDOW_HEIGHT;
        static MenuManager* getMM();
    protected:
    private:
        static MenuManager* menuManager;
};

#endif // CFG_H
