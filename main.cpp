#include <iostream>

#include "Day01/Part1.h"
#include "Day01/Part2.h"

#include "Day02/Part1.h"

void drawSeparator() {
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

int main() {
    drawSeparator();

    std::cout << "Running Day 1, Part 1..." << std::endl;
    auto day01Part01 = Day01::Part1();
    auto day01Part01Solution = day01Part01.Solve(std::string("../Day01/puzzle-input.dat"));
    std::cout << "Answer: " << day01Part01Solution << std::endl;

    drawSeparator();

    std::cout << "Running Day 1, Part 2..." << std::endl;
    auto day01Part02 = Day01::Part2();
    auto day01Part02Solution = day01Part02.Solve(std::string("../Day01/puzzle-input.dat"));
    std::cout << "Answer: " << day01Part02Solution << std::endl;

    drawSeparator();

    std::cout << "Running Day 2, Part 1..." << std::endl;
    auto day02Part01 = Day02::Part1();
    auto wtf = day02Part01.Solve(std::string("../Day02/part-one-puzzle-input.dat"));

    drawSeparator();

    return 0;
}
