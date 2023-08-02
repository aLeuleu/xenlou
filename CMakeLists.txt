cmake_minimum_required(VERSION 3.24)
project(xenlou)

set(CMAKE_CXX_STANDARD 17)

add_executable(xenlou main.cpp Game.cpp)


# Add the SDL2 package
set(SDL2_DIR "/opt/homebrew/Cellar/sdl2/2.28.1/")

# SDL2 image
set(SDL2_IMAGE_DIR "/opt/homebrew/Cellar/sdl2_image/2.6.3_1")


# Include the SDL2 headers
include_directories(${SDL2_DIR}/include/SDL2)
include_directories(${SDL2_IMAGE_DIR}/include/SDL2)

# Link your executable with the SDL2 libraries
target_link_libraries(xenlou ${SDL2_DIR}/lib/libSDL2.dylib)
target_link_libraries(xenlou ${SDL2_IMAGE_DIR}/lib/libSDL2_image.dylib)




