cmake_minimum_required(VERSION 3.28)
project(tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(tetris main.cpp)

target_link_libraries(tetris PRIVATE SFML::Graphics SFML::Window SFML::System)

