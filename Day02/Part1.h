//
// Created by ciroque on 02/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY02_PART1_H
#define ADVENT_OF_CODE_2023_C__DAY02_PART1_H

#include "Day.h"
#include "Game.h"

namespace Day02 {
class Part1 : public Day02::Day {
    public:
        Part1() = default;
        std::string Solve(const std::string& puzzleInputFilename) override;
    };
} // Day

#endif //ADVENT_OF_CODE_2023_C___PART1_H
