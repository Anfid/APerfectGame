cmake_minimum_required(VERSION 3.9)
project(APerfectGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(SOURCE_FILES
        main.cpp headers/Game.h src/Game.cpp headers/globals.h src/globals.cpp headers/Graphics.h src/Graphics.cpp
        headers/Input.h src/Input.cpp headers/Scroll.h src/Scroll.cpp
        headers/Player.h headers/Sprite.h headers/AnimatedSprite.h headers/Movable.h src/Sprite.cpp src/AnimatedSprite.cpp src/Player.cpp src/Movable.cpp)

include_directories(headers)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")

    include_directories(SDL2/include/SDL2 SDL2_image/include/SDL2)
    link_directories(SDL2/lib SDL2_image/lib)

    add_executable(APerfectGame ${SOURCE_FILES})

    target_link_libraries(APerfectGame mingw32 SDL2main SDL2 SDL2_image)
endif()

if(UNIX AND NOT APPLE)
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

    add_executable(APerfectGame ${SOURCE_FILES})

    target_link_libraries(APerfectGame ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
endif()
