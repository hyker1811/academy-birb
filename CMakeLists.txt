cmake_minimum_required(VERSION 3.10)
project(academy_birb)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(academy_birb.exe src/main.cpp src/Bird.cpp src/Bird.h src/Pipe.cpp src/Pipe.h src/Game.cpp src/Game.h)

configure_file(assets/clouds.jpg clouds.jpg COPYONLY)
configure_file(assets/sprite.png sprite.png COPYONLY)

target_link_libraries(academy_birb.exe Qt5::Core Qt5::Widgets)