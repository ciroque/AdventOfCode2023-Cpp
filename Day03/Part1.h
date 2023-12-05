//
// Created by ciroque on 04/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY03_PART1_H
#define ADVENT_OF_CODE_2023_C__DAY03_PART1_H

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>

#include "../Solution.h"
#include "Location.h"
#include "NumberLocation.h"
#include "Day.h"

namespace Day03 {

    class Part1 : public Day {
    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static std::vector<NumberLocation>
        FindAdjacentNumberIndices(std::vector<std::string> symbolIndices, const std::vector<NumberLocation>& numberIndices);

        static bool isSymbol(char character);

        static unsigned long SumAdjacentNumbers(const std::vector<NumberLocation>& adjacentNumberIndices);

        static std::map<char, unsigned long> FindUniqueCharacters(const std::vector<std::string>& puzzleData);
    };

} // Day03

#endif //ADVENT_OF_CODE_2023_C__DAY03_PART1_H
