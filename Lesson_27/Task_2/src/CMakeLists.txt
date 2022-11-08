cmake_minimum_required(VERSION 3.23)

add_executable(Task_2 main.cpp  ${CMAKE_SOURCE_DIR}/include/Header.h Shape.cpp Circle.cpp Rectangle.cpp Square.cpp Triangle.cpp)
TARGET_INCLUDE_DIRECTORIES(Task_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)