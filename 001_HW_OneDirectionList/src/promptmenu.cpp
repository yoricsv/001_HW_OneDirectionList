#include "promptmenu.h"

PromptMenu::PromptMenu()
{

}

int PromptMenu::showMenu(/*int &choice */)
{
    std::cout << "Choose what you want to do:"       << std::endl;

    std::cout << "\t 1 - ADDING AN ELEMENT:"         << std::endl;
    std::cout << "\t 2 - COUNT ITEMS IN A LIST:"     << std::endl;
    std::cout << "\t 3 - DISPLAYING ALL LIST ITEMS:" << std::endl;
    std::cout << "\t 4 - DELETE SOME ELEMENT:"       << std::endl;
    std::cout << "\t 5 - REMOVE A LIST:"             << std::endl;

    std::cout << "\t0 - CLOSE PROGRAM:"              << std::endl;

    std::cin >> action;

    if(0 < action % max_actions)
        return action;
    else
        exit(0);
}
