cmake_minimum_required(VERSION 3.23)

add_executable(Task_2 main.cpp ${CMAKE_SOURCE_DIR}/include/header.h ${CMAKE_SOURCE_DIR}/include/Circle.h
        ${CMAKE_SOURCE_DIR}/include/Rectangle.h ${CMAKE_SOURCE_DIR}/include/Triangle.h Circle.cpp Rectangle.cpp Triangle.cpp)
TARGET_INCLUDE_DIRECTORIES(Task_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)