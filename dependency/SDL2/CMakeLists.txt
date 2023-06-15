cmake_minimum_required(VERSION 3.22)
project(SDL2)

add_library(SDL2 INTERFACE)
target_include_directories(SDL2 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")