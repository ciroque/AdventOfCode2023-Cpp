//
// Created by ciroque on 05/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY04_PART1_H
#define ADVENT_OF_CODE_2023_C__DAY04_PART1_H

#include <cmath>

#include "Day.h"
#include "../Solution.h"
#include "ScratchCard.h"

namespace Day04 {

    class Part1 : public Day {
    private:

        static std::vector<unsigned long> CalculateGameScores(std::vector<ScratchCard>& scratchCards);

        static unsigned long CalculateAnswer(const std::vector<unsigned long>& gameScores);

    public:
        std::string Solve(const std::string& puzzleInputFilename);
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_PART1_H
