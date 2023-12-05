//
// Created by ciroque on 04/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY03_DAY_H
#define  ADVENT_OF_CODE_2023_C__DAY03_DAY_H
#include "../Solution.h"
#include "NumberLocation.h"

namespace Day03 {
    class Day : public Solution {
    protected:
        static std::vector<NumberLocation> FindNumberIndices(const std::vector<std::string>& puzzleData);

    };
} // Day03

#endif //ADVENT_OF_CODE_2023_C__DAY03_DAY_H
