# cmake_minimum_required(VERSION 3.22)

# # add_subdirectory("dependency/SDL2")
# add_subdirectory("dependency/SDL2_ttf")
# # add_subdirectory("dependency/SDL2_image")

# project(Calculator)

# file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
# # add_executable(${PROJECT_NAME} ${MY_SOURCES})
# # target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
# # target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image SDL2)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR/dependency/SDL2_ttf/cmake/})
# # list(APPEND CMAKE_PREFIX_PATH "~$/mnt/d/vslib_visualc/SDL2_image-2.6.2/cmakes")

# find_package(SDL2 REQUIRED)
# # find_package(SDL2_image REQUIRED)
# find_package(SDL2_ttf REQUIRED)

# add_executable(${PROJECT_NAME} ${MY_SOURCES}) 
# target_include_directories(${PROJECT_NAME} PUBLIC dependency/SDL2_ttf/include) #${SDL_IMAGE_INCLUDE_DIRS} ${SDL_TTF_INCLUDE_DIRS})
# target_link_directories(${PROJECT_NAME} PRIVATE dependency/SDL2_ttf/lib)
# target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_ttf )

cmake_minimum_required(VERSION 3.22)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)
project(CALCULATOR)

# Set the path to SDL2
set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependency/SDL2/")

# Set the path to SDL2_ttf
set(SDL2_TTF_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependency/SDL2_ttf/")

# Set the path to SDL2_image
set(SDL2_IMAGE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependency/SDL2_image/")

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find SDL2_ttf
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

# Find SDL2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# include your header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# Add your source files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
add_executable(${PROJECT_NAME} ${MY_SOURCES})

# Link SDL2, SDL2_ttf, and SDL2_image libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

