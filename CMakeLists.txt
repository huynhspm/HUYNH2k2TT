cmake_minimum_required(VERSION 3.7)

project(SDL2_GAME)

find_package(PkgConfig REQUIRED)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
message(STATUS "SDL2_INCLUDE_DIRS: ${SDL2_INCLUDE_DIRS}")

pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
include_directories(${SDL2_TTF_INCLUDE_DIRS})
message(STATUS "SDL2_TTF_INCLUDE_DIRS: ${SDL2_TTF_INCLUDE_DIRS}")

pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
message(STATUS "SDL2_MIXER_INCLUDE_DIRS: ${SDL2_MIXER_INCLUDE_DIRS}")

pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
message(STATUS "SDL2_IMAGE_INCLUDE_DIRS: ${SDL2_IMAGE_INCLUDE_DIRS}")

include_directories(${CMAKE_SOURCE_DIR}/header)

add_executable(SDL2_GAME src/Main.cpp)
target_link_libraries(SDL2_GAME ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})