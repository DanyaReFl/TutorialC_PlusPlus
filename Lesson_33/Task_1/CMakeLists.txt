cmake_minimum_required(VERSION 3.23)
project(Task_1)

set(CMAKE_CXX_STANDARD 14)


set(Boost_INCLUDE_DIR "C:\\boost_1_81_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_81_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Task_1 main.cpp)
target_link_libraries(Task_1 ${Boost_LIBRARIES})

if (MINGW)
    target_link_libraries(Task_1 ws2_32)
endif()