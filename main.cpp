#include <iostream>

#include "Day01/Part01.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto dayOnePartOne = Day01::Part01(std::string("../Day01/puzzle-input.dat"));
    dayOnePartOne.Solve();

    return 0;
}
