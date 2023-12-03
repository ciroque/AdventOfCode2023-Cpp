//
// Created by ciroque on 01/12/23.
//

#include "Part1.h"
#include <numeric>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include "Day.h"

std::vector<std::string> Day01::Day::LoadPuzzleData(const std::string &puzzleInputFilename) {
    std::cout << "Loading puzzle data from: " << puzzleInputFilename << "." << std::endl;

    std::string line;
    std::vector<std::string> puzzleData;

    std::ifstream puzzleDataFile(puzzleInputFilename);
    if(puzzleDataFile.fail()) {
        std::cout << "Failed to open file: " << puzzleInputFilename << std::endl;
    }

    if(puzzleDataFile.is_open()) {
        while(getline(puzzleDataFile, line)) {
            puzzleData.push_back(line);
        }
    }

    return puzzleData;
}

std::vector<std::string> Day01::Day::ResolveCalibrationValues(const std::vector<std::string> &puzzleDataOnlyNumbers) {
    std::vector<std::string> calibrationValues;
    for(auto& line : puzzleDataOnlyNumbers) {
        if(line.size() == 1) {
            auto value = ResolveSingleDigitCalibrationValue(line);
            calibrationValues.push_back(value);
        } else {
            auto value = ResolveMultiDigitCalibrationValue(line);
            calibrationValues.push_back(value);
        }
    }
    return calibrationValues;
}

std::vector<unsigned long> Day01::Day::ResolveCalibrationNumericValues(const std::vector<std::string> &puzzleDataOnlyNumbers) {
    std::vector<unsigned long> calibrationValues;
    for(auto& line : puzzleDataOnlyNumbers) {
        if(line.size() == 1) {
            auto value = std::stol(ResolveSingleDigitCalibrationValue(line));
            calibrationValues.push_back(value);
        } else {
            auto value = std::stol(ResolveMultiDigitCalibrationValue(line));
            calibrationValues.push_back(value);
        }
    }
    return calibrationValues;
}

std::string Day01::Day::ResolveSingleDigitCalibrationValue(const std::string &calibrationValue) {
    std::string resolvedCalibrationValue;
    resolvedCalibrationValue.insert(
            Part1::CALIBRATION_VALUE_INSERT_INDEX,
            Part1::CALIBRATION_VALUE_INSERT_LENGTH,
            calibrationValue.at(Part1::CALIBRATION_VALUE_EXTRACT_INDEX));
    return resolvedCalibrationValue;
}

std::string Day01::Day::ResolveMultiDigitCalibrationValue(const std::string &calibrationValue) {
    std::string resolvedCalibrationValue;

    auto firstDigit = calibrationValue.at(Part1::CALIBRATION_VALUE_EXTRACT_INDEX);
    auto secondDigit = calibrationValue.at(calibrationValue.length() - 1);

    resolvedCalibrationValue.push_back(firstDigit);
    resolvedCalibrationValue.push_back(secondDigit);

    return resolvedCalibrationValue;
}

unsigned long Day01::Day::SumCalibrationValues(const std::vector<unsigned long>& calibrationValues) {
    auto sum = std::reduce(calibrationValues.begin(), calibrationValues.end());
    return sum;
}

std::vector<std::string> Day01::Day::RemoveCharactersFromPuzzleInput(const std::vector<std::string>& puzzleData) {
    std::vector<std::string> processedData;
    for(auto& line : puzzleData) {
        auto onlyNumbers = Part1::RemoveCharactersFromLine(line);
        processedData.push_back(onlyNumbers);
    }
    return processedData;
}