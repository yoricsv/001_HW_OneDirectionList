#pragma once
#ifndef _PROMPTMENU_H
#define _PROMPTMENU_H
#include "promptsubmenu.h"

unsigned action         = 0;

class PromptMenu
{
private:
    int max_actions = 6;    // (number of actions + 1)
public:
            PromptMenu();
    virtual ~PromptMenu();

    virtual int showMenu(/*int &choice */);
};

#endif // !_PROMPTMENU_H
