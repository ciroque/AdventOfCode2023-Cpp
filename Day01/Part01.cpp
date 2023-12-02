//
// Created by ciroque on 01/12/23.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <numeric>

#include "Part01.h"


std::string Day01::Part01::Solve(const std::string& puzzleInputFilename) {
    auto puzzleData = Day01::LoadPuzzleData(puzzleInputFilename);
    auto puzzleDataOnlyNumbers = Part01::RemoveCharactersFromPuzzleInput(puzzleData);
    auto calibrationValues = Part01::ResolveCalibrationValues(puzzleDataOnlyNumbers);
    auto calibrationValuesSum = Part01::SumCalibrationValues(calibrationValues);

    return std::to_string(calibrationValuesSum);
}

std::vector<std::string> Day01::Part01::RemoveCharactersFromPuzzleInput(const std::vector<std::string>& puzzleData) {
    std::vector<std::string> processedData;
    for(auto& line : puzzleData) {
        auto onlyNumbers = RemoveCharactersFromLine(line);
        processedData.push_back(onlyNumbers);
    }
    return processedData;
}

std::string Day01::Part01::RemoveCharactersFromLine(const std::string& line) {
    std::string onlyNumbers;
    for(auto& character : line) {
        if(isdigit(character)) {
            onlyNumbers.push_back(character);
        }
    }
    return onlyNumbers;
}

std::vector<int> Day01::Part01::ResolveCalibrationValues(const std::vector<std::string> &puzzleDataOnlyNumbers) {
    std::vector<int> calibrationValues;
    for(auto& line : puzzleDataOnlyNumbers) {
        if(line.size() == 1) {
            auto value = std::stoi(ResolveSingleDigitCalibrationValue(line));
            calibrationValues.push_back(value);
        } else {
            auto value = std::stoi(ResolveMultiDigitCalibrationValue(line));
            calibrationValues.push_back(value);
        }
    }
    return calibrationValues;
}

std::string Day01::Part01::ResolveSingleDigitCalibrationValue(const std::string &calibrationValue) {
    std::string resolvedCalibrationValue;
    resolvedCalibrationValue.insert(
            CALIBRATION_VALUE_INSERT_INDEX,
            CALIBRATION_VALUE_INSERT_LENGTH,
            calibrationValue.at(CALIBRATION_VALUE_EXTRACT_INDEX));
    return resolvedCalibrationValue;
}

std::string Day01::Part01::ResolveMultiDigitCalibrationValue(const std::string &calibrationValue) {
    std::string resolvedCalibrationValue;

    auto firstDigit = calibrationValue.at(CALIBRATION_VALUE_EXTRACT_INDEX);
    auto secondDigit = calibrationValue.at(calibrationValue.length() - 1);

    resolvedCalibrationValue.push_back(firstDigit);
    resolvedCalibrationValue.push_back(secondDigit);

    return resolvedCalibrationValue;
}

int Day01::Part01::SumCalibrationValues(const std::vector<int>& calibrationValues) {
    auto sum = std::reduce(calibrationValues.begin(), calibrationValues.end());
    return sum;
}
