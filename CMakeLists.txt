cmake_minimum_required(VERSION 3.12)
project(TRAP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TRAP main.cpp Board.h Board.cpp Game.h Game.cpp Player.h Player.cpp AutoPlayer.h AutoPlayer.cpp HumanPlayer.h HumanPlayer.cpp)