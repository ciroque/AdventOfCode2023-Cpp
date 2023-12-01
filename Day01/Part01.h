//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___PART01_H
#define ADVENT_OF_CODE_2023_C___PART01_H

#include <vector>

namespace Day01 {
    class Part01 {
    private:
        static std::vector<std::string> LoadPuzzleData(const std::string& puzzleInputFilename);
        static std::vector<std::string> RemoveCharactersFromPuzzleInput(const std::vector<std::string>& puzzleData);
        static std::string RemoveCharactersFromLine(const std::string& line);
        static std::vector<int> ResolveCalibrationValues(const std::vector<std::string>& puzzleDataOnlyNumbers);
        static std::string ResolveSingleDigitCalibrationValue(const std::string& calibrationValue);
        static std::string ResolveMultiDigitCalibrationValue(const std::string& calibrationValue);

        static const int CALIBRATION_VALUE_INSERT_INDEX = 0;
        static const int CALIBRATION_VALUE_EXTRACT_INDEX = 0;
        static const int CALIBRATION_VALUE_INSERT_LENGTH = 2;
    public:
        static std::string Solve(const std::string& puzzleInputFilename);

        static int SumCalibrationValues(std::vector<int> calibrationValues);
    };
}



#endif //ADVENT_OF_CODE_2023_C___PART01_H
