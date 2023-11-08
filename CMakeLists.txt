cmake_minimum_required(VERSION 3.26)
project(2048_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(2048_Game main.cpp
        Plateau.h
        Partie.h
        Direction.h
        Plateau.cpp
        Partie.cpp)
