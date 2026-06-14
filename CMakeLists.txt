cmake_minimum_required(VERSION 3.20)

project(sort-visualizer LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.c win_utils.c)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)