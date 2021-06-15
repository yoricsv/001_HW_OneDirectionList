#ifndef _IOSTREAM
#define _IOSTREAM
#endif // _IOSTREAM

#include "promptsubmenu.h"

PromptSubMenu::PromptSubMenu()
{

}

int PromptSubMenu::showMenu(/*int &choice*/)
{
    std::cout << "Choose what you want to do:" << std::endl;

    std::cout << "\t    1  - Add a new element at the beginning\n";
    std::cout << "\t    2  - Add a new element by index\n";
    std::cout << "\t    3  - Add a new element to the end of the List\n";

    std::cout << "\t    4  - Get the number of items in a List\n";

    std::cout << "\t    5  - Show List\n";

    std::cout << "\t    6  - Delete the first element of the List\n";
    std::cout << "\t    7  - Delete an element by index\n";
    std::cout << "\t    8  - Delete the last element at the end of the List\n";

    std::cout << "\t    9  - Remove a List\n";

    std::cout << "\t    10 - Exit\n";

    std::cin >> sub_action;

    if(0 < sub_action % max_sub_actions)
        return sub_action;
    else
        exit(0);
}
