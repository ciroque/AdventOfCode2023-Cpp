//
// Created by ciroque on 01/12/23.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <numeric>

#include "Part1.h"
#include "Day.h"


std::string Day01::Part1::Solve(const std::string& puzzleInputFilename) {
    auto puzzleData = Day::LoadPuzzleData(puzzleInputFilename);
    auto puzzleDataOnlyNumbers = RemoveCharactersFromPuzzleInput(puzzleData);
    auto calibrationValues = ResolveCalibrationValues(puzzleDataOnlyNumbers);
    auto calibrationNumericValues = ResolveCalibrationNumericValues(puzzleDataOnlyNumbers);
    auto calibrationValuesSum = SumCalibrationValues(calibrationNumericValues);

    return std::to_string(calibrationValuesSum);
}

std::string Day01::Part1::RemoveCharactersFromLine(const std::string& line) {
    std::string onlyNumbers;
    for(auto& character : line) {
        if(isdigit(character)) {
            onlyNumbers.push_back(character);
        }
    }
    return onlyNumbers;
}

