//
// Created by ciroque on 01/12/23.
//
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>

#include "Part02.h"

std::vector<std::pair<std::string, std::string>> Day01::Part02::SpelledNumbers = {
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
};

std::string Day01::Part02::Solve(const std::string &puzzleInputFilename) {
    auto puzzleData = Day01::LoadPuzzleData(puzzleInputFilename);
    auto resolvedSpelledNumbers = Part02::ResolveSpelledNumbers(puzzleData);
    auto puzzleDataOnlyNumbers = RemoveCharactersFromPuzzleInput(resolvedSpelledNumbers);
    auto calibrationValues = ResolveCalibrationValues(puzzleDataOnlyNumbers);
    auto calibrationNumericValues = ResolveCalibrationNumericValues(puzzleDataOnlyNumbers);
    auto calibrationValuesSum = SumCalibrationValues(calibrationNumericValues);

//    printChangesTable(puzzleData, resolvedSpelledNumbers, puzzleDataOnlyNumbers, calibrationValues);

    return std::to_string(calibrationValuesSum);
}

void
Day01::Part02::printChangesTable(std::vector<std::string> &puzzleData, std::vector<std::string> &resolvedSpelledNumbers,
                                 std::vector<std::string> &puzzleDataOnlyNumbers,
                                 std::vector<std::string> &calibrationValues) const {
    int maxOriginalLineLength = std::max_element(puzzleData.begin(), puzzleData.end(), comparator)->length();
    int maxResolvedSpelledNumbersLength = std::max_element(resolvedSpelledNumbers.begin(), resolvedSpelledNumbers.end(), comparator)->length();
    int maxPuzzleDataOnlyNumbersLength = std::max_element(puzzleDataOnlyNumbers.begin(), puzzleDataOnlyNumbers.end(), comparator)->length();
    int maxCalibrationValuesLength = std::max_element(calibrationValues.begin(), calibrationValues.end(), comparator)->length();

    for(int i = 0; i < calibrationValues.size(); i++) {
        std::string originalLine = puzzleData[i];
        std::string resolvedSpelledNumberLine = resolvedSpelledNumbers[i];
        std::string puzzleDataOnlyNumbersLine = puzzleDataOnlyNumbers[i];
        std::basic_string<char> calibrationValue = calibrationValues[i];

        std::cout << std::setw(maxOriginalLineLength) << originalLine << " : "
        << std::setw(maxResolvedSpelledNumbersLength) << resolvedSpelledNumberLine << " : "
        << std::setw(maxPuzzleDataOnlyNumbersLength) << puzzleDataOnlyNumbersLine << " : "
        << std::setw(maxCalibrationValuesLength) << calibrationValue << std::endl;
    }
}

std::vector<std::string> Day01::Part02::ResolveSpelledNumbers(const std::vector<std::string>& puzzleData) {
    std::vector<std::string> numericValues;

    for(auto line : puzzleData) {
        auto numericValue = ResolveSpelledNumber(line);
        numericValues.push_back(numericValue);
    }

    return numericValues;
}

// no sort: 54495
// sort: 54980
std::string Day01::Part02::ResolveSpelledNumber(std::string &line) {
    std::vector<std::pair<unsigned long, std::pair<std::string, std::string>>> indices;
    for(auto& spelled : SpelledNumbers) {
        std::string from = spelled.first;
        std::string to = spelled.second;

        auto index = line.find(from);
        if(index != std::string::npos) {
            indices.emplace_back(index, std::make_pair(from, to));
        }
    }

    std::sort(indices.begin(), indices.end());

//    CheckForOverlappingIndices(line, indices);

    for(const auto& index : indices) {
        std::string from = index.second.first;
        std::string to = index.second.second;

        // There may be letters used in more than one spelled value: `twone` is both 2 and 1. Quite sneaky.
        auto idx = line.find(from);
        while(idx != std::string::npos) {
            auto lastIdx = ++idx;
            line.insert(idx, to);
            idx = line.find(from, ++lastIdx);
        }
    }

    return line;
}

void Day01::Part02::CheckForOverlappingIndices(std::string &line,
                                               std::vector<std::pair<unsigned long, std::pair<std::string, std::string>>> indices) {
    for(size_t index = 1; index < indices.size(); index++) {
        auto previousIndex = indices[index - 1];
        auto currentIndex = indices[index];

        if(previousIndex.first + previousIndex.second.first.length() > currentIndex.first) {
            std::cout << line << " "
            << "previousNumber(" << previousIndex.second.first << ")[" << previousIndex.first << "] "
            << "currentNumber(" << currentIndex.second.first << ")[" << currentIndex.first << "] "
            << std::endl;
        }
    }
}
