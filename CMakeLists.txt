cmake_minimum_required(VERSION 3.29)
project(Pig_Dice_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pig_Dice_2_0
    Die.cpp
    Die.h
    Game.cpp
    Game.h
    main.cpp
    Turn.cpp
    Turn.h)
