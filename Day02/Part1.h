//
// Created by ciroque on 02/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY02_PART1_H
#define ADVENT_OF_CODE_2023_C__DAY02_PART1_H

#include "Day.h"
#include "Game.h"

namespace Day02 {
class Part1 : public Day02::Day {
public:
    std::string Solve(const std::string& puzzleInputFilename, std::map<std::string, unsigned long> targets);

private:
    static bool targetsPredicate(const Game& game, const std::map<std::string, unsigned long>& targets);
    static std::vector<Game> FindPossibleGames(const std::vector<Game>& allGames, const std::map<std::string, unsigned long>& targets);
    static unsigned long SumGameIds(const std::vector<Game>& possibleGames);
};
} // Day

#endif //ADVENT_OF_CODE_2023_C___PART1_H
