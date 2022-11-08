cmake_minimum_required(VERSION 3.23)

add_executable(Task_3 main.cpp ${CMAKE_SOURCE_DIR}/include/header.h head_company.cpp middleManager.cpp subordinates.cpp)
TARGET_INCLUDE_DIRECTORIES(Task_3 PUBLIC ${CMAKE_SOURCE_DIR}/include)