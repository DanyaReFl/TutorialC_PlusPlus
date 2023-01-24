cmake_minimum_required(VERSION 3.24)
project(Lesson_34)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson_34 main.cpp)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")

find_package(Qt5 COMPONENTS

        Core

        Gui

        Widgets

        REQUIRED)

target_link_libraries(Lesson_34

        Qt5::Core

        Qt5::Gui

        Qt5::Widgets)