cmake_minimum_required(VERSION 3.23)

add_executable(Task_3 main.cpp  ${CMAKE_SOURCE_DIR}/include/functionHeader.h functionRegistry.cpp )
target_include_directories(Task_3 PUBLIC ${CMAKE_SOURCE_DIR}/include)