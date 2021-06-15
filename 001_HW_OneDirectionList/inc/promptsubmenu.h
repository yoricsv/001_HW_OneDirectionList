#pragma once
#ifndef _PROMPTSUBMENU_H
#define _PROMPTSUBMENU_H


unsigned sub_action     = 0;

//template <typename T>
class PromptSubMenu : public PromptMenu //<T>
{
private:
    int max_sub_actions = 10;   // (number of actions + 1)
public:
    PromptSubMenu();
    int showMenu(/*int &choice */) override;
};

#endif // _PROMPTSUBMENU_H
