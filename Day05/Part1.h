//
// Created by ciroque on 06/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY05_PART1_H
#define ADVENT_OF_CODE_2023_C__DAY05_PART1_H

#include <sstream>
#include <map>
#include <vector>

#include "Day.h"

namespace Day05 {

    class Part1 : public Day {
    private:
        std::vector<std::string> m_OrderedKeys;

    public:
        std::string Solve(const std::string& puzzleInputFilename);

        std::map<std::string, std::vector<std::string>> PartitionPuzzleData(const std::vector<std::string>& puzzleInput);
    };

} // Day05

#endif //ADVENT_OF_CODE_2023_C__DAY05_PART1_H
