//
// Created by ciroque on 05/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY04_PART2_H
#define ADVENT_OF_CODE_2023_C__DAY04_PART2_H

#include <chrono>
#include <iostream>

#include "Day.h"

namespace Day04 {

    class Part2 : public Day {
    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static std::vector<ScratchCard> CalculateBonusScratchCards(std::vector<ScratchCard> scratchCards);
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_PART2_H
