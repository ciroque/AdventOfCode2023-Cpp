//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___DAY_H
#define ADVENT_OF_CODE_2023_C___DAY_H

#include <vector>
#include <string>

#include "../Solution.h"

namespace Day01 {
    class Day : public Solution {

        static std::string ResolveSingleDigitCalibrationValue(const std::string& calibrationValue);

        static std::string ResolveMultiDigitCalibrationValue(const std::string& calibrationValue);

    protected:
        static std::vector<std::string> LoadPuzzleData(const std::string& puzzleInputFilename);

        static std::vector<std::string> ResolveCalibrationValues(const std::vector<std::string>& puzzleDataOnlyNumbers);

        static std::vector<unsigned long> ResolveCalibrationNumericValues(const std::vector<std::string> &puzzleDataOnlyNumbers);

        static std::vector<std::string> RemoveCharactersFromPuzzleInput(const std::vector<std::string>& puzzleData);

    public:
        static unsigned long SumCalibrationValues(const std::vector<unsigned long>& calibrationValues);
    };
}

#endif //ADVENT_OF_CODE_2023_C___DAY_H
