cmake_minimum_required(VERSION 3.22)
project(SDL2_image)

add_library(SDL2_image INTERFACE)
target_include_directories(SDL2_image INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")