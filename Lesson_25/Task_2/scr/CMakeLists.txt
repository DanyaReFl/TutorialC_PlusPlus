cmake_minimum_required(VERSION 3.23)

add_executable(Task_2 main.cpp ${CMAKE_SOURCE_DIR}/include/head.h cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)
TARGET_INCLUDE_DIRECTORIES(Task_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)