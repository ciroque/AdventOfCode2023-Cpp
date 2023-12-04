//
// Created by ciroque on 03/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY02_PART2_H
#define ADVENT_OF_CODE_2023_C__DAY02_PART2_H

#include <string>
#include "Day.h"

namespace Day02 {
    class Part2: public Day {
    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static std::vector<Game> OptimizeGames(std::vector<Game>& games);

        static Game OptimizeGame(const Game& game);

        static std::vector<unsigned long> CalculatePowerLevels(const std::vector<Game>& optimizedGames);

        static unsigned long CalculatePowerLevel(const Game &game);

        unsigned long SumPowerLevels(std::vector<unsigned long> powerLevels);
    };

} // Day02

#endif //ADVENT_OF_CODE_2023_C___PART2_H
