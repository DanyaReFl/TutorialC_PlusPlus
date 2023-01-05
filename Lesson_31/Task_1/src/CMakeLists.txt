cmake_minimum_required(VERSION 3.23)

add_executable(Task_1 main.cpp ${CMAKE_SOURCE_DIR}/include/Toy.h ${CMAKE_SOURCE_DIR}/include/shared_ptr_toy.h
        shared_ptr_toy.cpp )
TARGET_INCLUDE_DIRECTORIES(Task_1 PUBLIC ${CMAKE_SOURCE_DIR}/include)