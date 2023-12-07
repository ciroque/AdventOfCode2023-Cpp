//
// Created by ciroque on 05/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY04_DAY_H
#define ADVENT_OF_CODE_2023_C__DAY04_DAY_H

#include "ScratchCard.h"
#include <cmath>
#include "../Solution.h"

namespace Day04 {
    class Day : public Solution {

    protected:
        static std::vector<ScratchCard> BuildScratchCards(const std::vector<std::string>& puzzleData);
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_DAY_H
