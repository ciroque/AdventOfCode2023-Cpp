//
// Created by ciroque on 04/12/23.
//

#include <iostream>
#include <numeric>
#include "Part2.h"

namespace Day03 {
    std::string Part2::Solve(const std::string &puzzleInputFilename) {
        auto puzzleData = Solution::LoadPuzzleData(puzzleInputFilename);
        auto numberIndices = FindNumberIndices(puzzleData);
        auto asteriskIndices = FindAsteriskIndices(puzzleData);
        auto gearRatios = FindGearRatios(numberIndices, asteriskIndices);
        auto answer = SumGearRatios(gearRatios);

        return std::to_string(answer);
    }

    int Part2::SumGearRatios(std::vector<int> &gearRatios) { return std::accumulate(gearRatios.begin(), gearRatios.end(), 0); }

    std::vector<int>
    Part2::FindGearRatios(const std::vector<NumberLocation> &numberIndices,
                          std::vector<Location> &asteriskIndices) {
        std::vector<int> gearRatios;
        for(auto& asteriskIndex : asteriskIndices) {
            std::vector<NumberLocation> adjacentNumbers;
            auto adjacentNumberIndices = FindAdjacentNumberIndices(asteriskIndex.GetLine(), numberIndices);
            for(auto& adjacentNumberIndex : adjacentNumberIndices) {
                auto asteriskColumnIndex = asteriskIndex.GetColumn();
                auto numberColumnIndex = adjacentNumberIndex.GetColumn();
                auto lowerBound = numberColumnIndex - 1;
                auto upperBound = numberColumnIndex + adjacentNumberIndex.GetLength();
                if(asteriskColumnIndex >= lowerBound
                    && asteriskColumnIndex <= upperBound) {
                    adjacentNumbers.push_back(adjacentNumberIndex);
                }
            }
            if(adjacentNumbers.size() == 2) {
                gearRatios.push_back(adjacentNumbers[0].GetNumber() * adjacentNumbers[1].GetNumber());
            }
        }
        return gearRatios;
    }

    std::vector<Location> Part2::FindAsteriskIndices(const std::vector<std::string>& puzzleData) {
        std::vector<Location> indices;
        const char symbol = '*';
        int lineIndex = 0;
        for(auto& line : puzzleData) {
            auto index = line.find(symbol);
            while(index != std::string::npos) {
                indices.emplace_back(lineIndex, index);
                index = line.find(symbol, index + 1);
            }

            lineIndex++;
        }
        return indices;
    }

    std::vector<NumberLocation>
    Part2::FindAdjacentNumberIndices(int lineNumber, const std::vector<NumberLocation>& numberIndices) {
        std::vector<NumberLocation> adjacentNumberIndices;

        std::copy_if(numberIndices.begin(), numberIndices.end(), std::back_inserter(adjacentNumberIndices), [lineNumber](const NumberLocation& numberIndex) {
            return numberIndex.GetLine() == lineNumber || numberIndex.GetLine() == lineNumber - 1 || numberIndex.GetLine() == lineNumber + 1;
        });

        return adjacentNumberIndices;
    }
} // Day03
