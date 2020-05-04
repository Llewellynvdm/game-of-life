cmake_minimum_required(VERSION 3.16)
project(game-of-life)

set(CMAKE_CXX_STANDARD 14)

add_executable(game-of-life src/main.cpp src/Message.cpp src/Message.h src/color.h src/GetInput.cpp src/GetInput.h src/GameOfLife.cpp src/GameOfLife.h src/Game.cpp src/Game.h src/Patterns.cpp src/Patterns.h src/Util.cpp src/Util.h)