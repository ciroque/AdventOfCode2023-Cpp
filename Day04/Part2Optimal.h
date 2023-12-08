//
// Created by ciroque on 07/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY04_PART2OPTIMAL_H
#define ADVENT_OF_CODE_2023_C__DAY04_PART2OPTIMAL_H

#include <chrono>
#include <iostream>

#include "Day.h"

namespace Day04 {

    class Part2Optimal : public Day {
    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static std::map<unsigned long, unsigned long> CalculateWinCountMap(std::vector<ScratchCard> scratchCard);

        static std::map<unsigned long, unsigned long> CalculateFinalCounts(const std::map<unsigned long, unsigned long>& winCountMap);

        static unsigned long SumFinalCounts(const std::map<unsigned long, unsigned long>& finalCounts);
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_PART2OPTIMAL_H
