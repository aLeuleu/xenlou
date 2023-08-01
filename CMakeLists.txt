cmake_minimum_required(VERSION 3.24)
project(xenlou)

set(CMAKE_CXX_STANDARD 17)

add_executable(xenlou main.cpp)


# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include the SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})


# Link your executable with the SDL2 libraries
target_link_libraries(xenlou ${SDL2_LIBRARIES})