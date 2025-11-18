# Set cmake version and project name
cmake_minimum_required(VERSION 3.15)
project(PongGame CXX)

# Find the package for SDL2
find_package(SDL2 REQUIRED)

# Include the header directories
include_directories(${SDL2_INCLUDE_DIRS})

# Create the executable
add_executable(PongGame ball.hpp ball.cpp player.hpp player.cpp pong.cpp)

# Link the executable to SDL2
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
