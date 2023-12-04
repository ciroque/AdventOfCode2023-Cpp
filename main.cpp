#include <iostream>

#include "Day01/Part1.h"
#include "Day01/Part2.h"

#include "Day02/Part1.h"
#include "Day02/Part2.h"
#include "Day03/Part1.h"

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
    auto partOneTargets = std::map<std::string, unsigned long> {
        {"red", 12},
        {"green", 13},
        {"blue", 14}
    };

    auto day02Part1 = Day02::Part1();
    auto day02Part01Solution = day02Part1.Solve(std::string("../Day02/puzzle-input.dat"), partOneTargets);
    std::cout << "Answer: " << day02Part01Solution << std::endl;

    drawSeparator();

    std::cout << "Running Day 2, Part 2..." << std::endl;
    auto day02Part2 = Day02::Part2();
    auto day02Part2Solution = day02Part2.Solve(std::string("../Day02/puzzle-input.dat"));
    std::cout << "Answer: " << day02Part2Solution << std::endl;

    drawSeparator();

    std::cout << "Running Day 3, Part 1..." << std::endl;
    auto day03Part1 = Day03::Part1();
    auto day03Part1Solution = day03Part1.Solve(std::string("../Day03/puzzle-input.dat"));
    std::cout << "Answer: " << day03Part1Solution << std::endl;

    drawSeparator();

    return 0;
}
