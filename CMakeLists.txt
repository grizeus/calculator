cmake_minimum_required(VERSION 3.22)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)

set(This calculator)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Set the path to SDL2
set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependency/SDL2/")

# Set the path to SDL2_ttf
set(SDL2_TTF_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependency/SDL2_ttf/")

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find SDL2_ttf
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# Debug mode
set(CMAKE_BUILD_TYPE Debug)

# test setup
enable_testing()

add_subdirectory(googletest)

set(Headers
    "include/Button.hpp"
    "include/Calculator.hpp"
    "include/Display.hpp"
    "include/InputBoard.hpp"
    "include/Operand.hpp"
    "include/SDL_Tools.hpp"
    "include/UI_Element.hpp"
)
set(Sources
    "src/Button.cpp"
    "src/Calculator.cpp"
    "src/Display.cpp"
    "src/InputBoard.cpp"
    "src/Operand.cpp"
    "src/SDL_Tools.cpp"
    "src/UI_Element.cpp"
    "src/main.cpp"
)

add_library(${This} STATIC ${Sources} ${Headers})

# Link SDL2
target_link_libraries(${This} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})

add_subdirectory(UT)