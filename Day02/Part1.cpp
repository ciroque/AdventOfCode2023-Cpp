//
// Created by ciroque on 02/12/23.
//

#include <algorithm>
#include "Part1.h"

namespace Day02 {
    std::string Part1::Solve(const std::string &puzzleInputFilename, const std::map<std::string, unsigned long> targets) {
        auto puzzleData = LoadPuzzleData(puzzleInputFilename);
        auto games = LoadGames(puzzleData);
        auto possibleGames = FindPossibleGames(games, targets);
        auto answer = SumGameIds(possibleGames);

        return std::to_string(answer);
    }

    std::vector<Game>
    Part1::FindPossibleGames(const std::vector<Game>& allGames, const std::map<std::string, unsigned long>& targets) {
        std::vector<Game> possibleGames;
        std::copy_if(
                allGames.begin(),
                allGames.end(),
                std::back_inserter(possibleGames),
                [&](auto& game) {
            return predicate(game, targets);
        });
        return possibleGames;
    }

    bool Part1::predicate(const Game& game, const std::map<std::string, unsigned long>& targets) {
        for(auto& target : targets) {
            auto color = target.first;
            auto count = target.second;
            for(auto& revealColorCount : game.GetRevealColorCounts()) {
                auto gameColorCount = revealColorCount.find(color);
                if(gameColorCount != revealColorCount.end() && gameColorCount->second > count) {
                    return false;
                }
            }
        }

        return true;
    }

    unsigned long Part1::SumGameIds(const std::vector<Game>& possibleGames) {
        unsigned long sum = 0;
        for(auto& game : possibleGames) {
            sum += game.GetId();
        }
        return sum;
    }
} // Day