#include <iostream>

#include "Day01/Part01.h"

int main() {
    std::cout << "Running Day 1, Part 1..." << std::endl;
    auto answer = Day01::Part01::Solve(std::string("../Day01/puzzle-input.dat"));
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}
