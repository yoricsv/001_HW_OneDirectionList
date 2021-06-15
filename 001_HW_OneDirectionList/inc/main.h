#pragma once

#ifndef _MAIN_H
#define _MAIN_H

#ifndef _IOSTREAM_H
#define _IOSTREAM_H
#endif // !_IOSTREAM_H

#include "promptmenu.h"
#include "promptsubmenu.h"
#include "list_template.h"

//#define USE_RANDOM
#ifndef USE_RANDOM
#define USE_INCREMENT
#endif

#define USE_ABSTRACT_CLASS
#ifndef USE_ABSTRACT_CLASS
#define USE_BY_STRUCT_NODE
#endif


enum PROG_STATE
{
    EXIT,
    CREATE_LIST,
    AUTO,
    MANUALLY,
    AUTO_FILL_ARRAY_IN,
    MANUALLY_FILL_ARRAY_IN,

};

enum ACTIONS
{
    ADDING_AN_ELEMENT   = 1,
    COUNT_ITEMS,
    DISPLAY_LIST_ITEMS,
    DELETE_SOME_ELEMENT,
    REMOVE_A_LIST,
    CLOSE_PROGRAM
};

enum SUB_ACTIONS
{
    NEW_INTO_BEGIN      = 1,
    NEW_BY_INDEX,
    NEW_INTO_END,
    GET_RANGE,
    SHOW_LIST,
    DELETE_FIRST,
    DELETE_BY_INDEX,
    DELETE_LAST,
    REMOVE_ALL
};

unsigned program_state  = 0;


#endif // MAIN_H
