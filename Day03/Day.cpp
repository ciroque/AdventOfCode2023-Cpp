//
// Created by ciroque on 04/12/23.
//

#include "Day.h"

namespace Day03 {
    std::vector<NumberLocation> Day::FindNumberIndices(const std::vector<std::string>& puzzleData) {
        std::vector<NumberLocation> indices;
        int lineNumber = 0;
        int length = 0;
        bool inNumber = false;

        for(auto& line : puzzleData) {
            int currentColumnIndex = 0;
            int startColumnIndex = 0;
            for(auto& character : line) {
                currentColumnIndex++;
                if(isdigit(character)) {
                    if(!inNumber) {
                        startColumnIndex = currentColumnIndex - 1;
                        inNumber = true;
                    }
                    length++;
                } else {
                    if(inNumber) {
                        auto number = line.substr(startColumnIndex, length);
                        indices.emplace_back(lineNumber, startColumnIndex, number, length);
                        inNumber = false;
                        length = 0;
                    }
                }
            }
            if(inNumber) {
                auto number = line.substr(startColumnIndex, length);
                indices.emplace_back(lineNumber, startColumnIndex, number, length);
                length = 0;
            }
            lineNumber++;
            inNumber = false;
        }

        return indices;
    }

} // Day03