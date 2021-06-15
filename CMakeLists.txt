cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

    set (PROJECT_NAME    001_HW_OneDirectionList)
project (${PROJECT_NAME} LANGUAGES CXX)

    set (CMAKE_CXX_STANDARD           14)
    set (CMAKE_CXX_STANDARD_REQUIRED  ON)

add_executable(${PROJECT_NAME}
    src/main.cpp             src/inc/main.h
    src/list_template.cpp    src/inc/list_template.h
    src/promptmenu.cpp       src/inc/promptmenu.h
    src/promptsubmenu.cpp    src/inc/promptsubmenu.h
)
