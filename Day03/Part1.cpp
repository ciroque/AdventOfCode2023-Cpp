//
// Created by ciroque on 04/12/23.
//

#include "Part1.h"

namespace Day03 {
    std::string Part1::Solve(const std::string &puzzleInputFilename) {
        auto puzzleData = Solution::LoadPuzzleData(puzzleInputFilename);
        auto numberIndices = FindNumberIndices(puzzleData);
        auto uniqueCharacters = FindUniqueCharacters(puzzleData);
        auto adjacentNumberIndices = FindAdjacentNumberIndices(puzzleData, numberIndices);
        auto answer = SumAdjacentNumbers(adjacentNumberIndices);

        return std::to_string(answer);
    }


    std::vector<NumberLocation>
    Part1::FindAdjacentNumberIndices(std::vector<std::string> symbolIndices, const std::vector<NumberLocation>& numberIndices) {
        std::vector<NumberLocation> adjacentNumberIndices;
        std::vector<std::pair<int, int>> adjacentOffsets = {
                {-1, -1}, {-1, 0}, {-1, 1},
                {0, -1}, {0, 1},
                {1, -1}, {1, 0}, {1, 1}
        };
        bool currentAdded = false;
        for(auto& numberIndex : numberIndices) {
            auto lineNumber = numberIndex.GetLine();
            auto columnIndex = numberIndex.GetColumn();
            auto number = numberIndex.GetNumberString();
            for(int digitIndex = 0; digitIndex < number.length(); digitIndex++) {
                for(auto& offset : adjacentOffsets) {
                    auto adjacentLineNumber = lineNumber + offset.first;
                    auto adjacentColumnIndex = columnIndex + offset.second + digitIndex;
                    if(adjacentLineNumber >= 0 && adjacentLineNumber < symbolIndices.size()) {
                        auto adjacentLine = symbolIndices[adjacentLineNumber];
                        if(adjacentColumnIndex >= 0 && adjacentColumnIndex < adjacentLine.size()) {
                            auto adjacentCharacter = adjacentLine[adjacentColumnIndex];
                            if(isSymbol(adjacentCharacter)) {
                                if(!currentAdded) {
                                    adjacentNumberIndices.push_back(numberIndex);
                                    currentAdded = true;
                                }
                            }
                        }
                    }
                }
            }
            currentAdded = false;
        }

        return adjacentNumberIndices;
    }

    bool Part1::isSymbol(char character) {
        return
            character == '#' // 38 occurrences
            || character == '$' // 40 occurrences
            || character == '%' // 43 occurrences
            || character == '&' // 43 occurrences
            || character == '*' // 367 occurrences
            || character == '+' // 46 occurrences
            || character == '-' // 45 occurrences
            || character == '/' // 60 occurrences
            || character == '=' // 44 occurrences
            || character == '@'; // 44 occurrences
    }

    unsigned long Part1::SumAdjacentNumbers(const std::vector<NumberLocation>& adjacentNumberIndices) {
        unsigned long sum = 0;
        for(auto& numberIndex : adjacentNumberIndices) {
            sum += numberIndex.GetNumber();
        }
        return sum;
    }

    std::map<char, unsigned long> Part1::FindUniqueCharacters(const std::vector<std::string>& puzzleData) {
        std::map<char, unsigned long> uniqueCharacters;

        for (auto& line : puzzleData) {
            for (auto& character : line) {
                if(isdigit(character)) continue;
                if(character == '.') continue;
                if (uniqueCharacters.find(character) == uniqueCharacters.end()) {
                    uniqueCharacters[character] = 1;
                } else {
                    uniqueCharacters[character]++;
                }
            }

        }

        return uniqueCharacters;
    }
} // Day03
