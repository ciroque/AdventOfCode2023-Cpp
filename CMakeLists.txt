cmake_minimum_required(VERSION 3.26)
project(advent_of_code_2023_c__)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code_2023_c__ main.cpp
        "common.h"
        "Day01/Part1.cpp"
        "Day01/Part1.h"
        "Day01/Part1.cpp"
        Day01/Day.cpp
        Day01/Day.h
        Day01/Part2.cpp
        Day01/Part2.h
        Solution.cpp
        Solution.h
)
