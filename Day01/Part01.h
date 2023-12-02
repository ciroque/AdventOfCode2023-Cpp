//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___PART01_H
#define ADVENT_OF_CODE_2023_C___PART01_H

#include <vector>

#include "Day01.h"

namespace Day01 {
    class Part01 : public Day01::Day01 {

    public:
        std::string Solve(const std::string& puzzleInputFilename) override;

        static const int CALIBRATION_VALUE_EXTRACT_INDEX = 0;
        static const int CALIBRATION_VALUE_INSERT_INDEX = 0;
        static const int CALIBRATION_VALUE_INSERT_LENGTH = 2;

        static std::string RemoveCharactersFromLine(const std::string& line);
    };
}



#endif //ADVENT_OF_CODE_2023_C___PART01_H
