//
// Created by ciroque on 01/12/23.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <utility>

#include "../common.h"
#include "Part01.h"


std::string Day01::Part01::Solve() {
    this->LoadPuzzleData();
    this->ProcessInput();


    return {};
}

void Day01::Part01::LoadPuzzleData() {
    std::cout << "Loading puzzle data from: " << this->puzzleInputFilename << "." << std::endl;

    std::string line;

    std::ifstream puzzleDataFile(this->puzzleInputFilename);

    std::filesystem::path cwd = std::filesystem::current_path();

    if(puzzleDataFile.fail()) {
        std::cout << "Failed to open file: " << this->puzzleInputFilename << std::endl;
    }

    if(puzzleDataFile.is_open()) {
        while(getline(puzzleDataFile, line)) {
            this->puzzleData.push_back(line);
        }
    }
}

Day01::Part01::Part01(std::string puzzleInputFilename) {
    this->puzzleInputFilename = std::move(puzzleInputFilename);
}

void Day01::Part01::ProcessInput() {

}

void Day01::Part01::RemoveCharacters() {

}
