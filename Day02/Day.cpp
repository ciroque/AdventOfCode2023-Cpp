//
// Created by ciroque on 02/12/23.
//

#include <iostream>
#include <fstream>
#include "Day.h"

namespace Day02 {
    std::vector<Game> Day::LoadGames(const std::vector<std::string> &puzzleData) {
        std::vector<Game> games;

        for (const auto &line: puzzleData) {
            games.emplace_back(Game::Create(line));
        }

        return games;
    }

    std::vector<std::string> Day::LoadPuzzleData(const std::string &puzzleInputFilename) {
        std::cout << "Loading puzzle data from: " << puzzleInputFilename << "." << std::endl;

        std::string line;
        std::vector<std::string> puzzleData;

        std::ifstream puzzleDataFile(puzzleInputFilename);
        if (puzzleDataFile.fail()) {
            std::cout << "Failed to open file: " << puzzleInputFilename << std::endl;
        }

        if (puzzleDataFile.is_open()) {
            while (getline(puzzleDataFile, line)) {
                puzzleData.push_back(line);
            }
        }

        return puzzleData;
    }

} // Day

