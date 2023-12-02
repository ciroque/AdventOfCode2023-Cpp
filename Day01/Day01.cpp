//
// Created by ciroque on 01/12/23.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Day01.h"

std::vector<std::string> Day01::Day01::LoadPuzzleData(const std::string &puzzleInputFilename) {
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
