//
// Created by ciroque on 02/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY02_DAY_H
#define ADVENT_OF_CODE_2023_C__DAY02_DAY_H

#include <vector>
#include "../Solution.h"
#include "Game.h"

namespace Day02 {
    class Day {
    public:
        virtual std::string Solve(const std::string& puzzleInputFilename, const std::map<std::string, unsigned long> targets) = 0;

    protected:
        static std::vector<std::string> LoadPuzzleData(const std::string &puzzleInputFilename);
        static std::vector<Game> LoadGames(const std::vector<std::string> &puzzleData);
    };
}

#endif //ADVENT_OF_CODE_2023_C___DAY_H
