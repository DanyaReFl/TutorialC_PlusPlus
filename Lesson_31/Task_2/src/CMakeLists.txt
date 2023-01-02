cmake_minimum_required(VERSION 3.23)

add_executable(Task_2 main.cpp ${CMAKE_SOURCE_DIR}/include/IGraph.h ${CMAKE_SOURCE_DIR}/include/ListGraph.h
        ${CMAKE_SOURCE_DIR}/include/MatrixGraph.h ${CMAKE_SOURCE_DIR}/include/TestView.h ListGraphClass.cpp MatrixGraphClass.cpp TestView.cpp)
TARGET_INCLUDE_DIRECTORIES(Task_2 PUBLIC ${CMAKE_SOURCE_DIR}/include)