cmake_minimum_required(VERSION 3.22)
project(SDL2_ttf)

add_library(SDL2_ttf INTERFACE)
target_include_directories(SDL2_ttf INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")