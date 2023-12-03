//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___PART1_H
#define ADVENT_OF_CODE_2023_C___PART1_H

#include <vector>

#include "Day.h"

namespace Day01 {
    class Part1 : public Day::Day {

    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static const int CALIBRATION_VALUE_EXTRACT_INDEX = 0;
        static const int CALIBRATION_VALUE_INSERT_INDEX = 0;
        static const int CALIBRATION_VALUE_INSERT_LENGTH = 2;

        static std::string RemoveCharactersFromLine(const std::string& line);
    };
}



#endif //ADVENT_OF_CODE_2023_C___PART1_H
