cmake_minimum_required(VERSION 3.28)
project(pholimorphizm_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(pholimorphizm_game main.cpp
        resources.qrc
        draw_hero.hpp
        draw_dragon.hpp
        write_text.hpp
        class.hpp
        show_gif.hpp)


target_link_libraries(pholimorphizm_game
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

