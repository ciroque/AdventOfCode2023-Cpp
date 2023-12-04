//
// Created by ciroque on 03/12/23.
//

#include <algorithm>
#include <numeric>
#include "Part2.h"
#include "Day.h"

namespace Day02 {
    std::string Part2::Solve(const std::string &puzzleInputFilename) {
        auto puzzleData = Solution::LoadPuzzleData(puzzleInputFilename);
        auto games = Day::LoadGames(puzzleData);
        auto optimizedGames = OptimizeGames(games);
        auto powerLevels = CalculatePowerLevels(optimizedGames);
        auto answer = SumPowerLevels(powerLevels);

        return std::to_string(answer);
    }

    std::vector<Game> Part2::OptimizeGames(std::vector<Game>& games) {
        std::vector<Game> optimizedGames;
        std::transform(games.begin(), games.end(), std::back_inserter(optimizedGames), [](const Game& game) {
            auto optimizedGame = OptimizeGame(game);
            return optimizedGame;
        });

        return optimizedGames;    }

    Game Part2::OptimizeGame(const Game& game) {
        std::map<std::string, unsigned long> colorCounts;
        for(auto& revealColorCounts : game.GetRevealColorCounts()) {
            for(auto& [color, count] : revealColorCounts) {
                if(colorCounts.find(color) == colorCounts.end()) {
                    colorCounts[color] = count;
                } else {
                    if(colorCounts[color] < count) {
                        colorCounts[color] = count;
                    }
                }
            }
        }


        auto revealColorCounts = std::vector<std::map<std::string, unsigned long>>{{colorCounts}};

        auto optimizedGame = Game{game.GetId(), revealColorCounts};
        return optimizedGame;
    }

    std::vector<unsigned long> Part2::CalculatePowerLevels(const std::vector<Game>& optimizedGames) {
        std::vector<unsigned long> powerLevels;
        std::transform(optimizedGames.begin(), optimizedGames.end(), std::back_inserter(powerLevels), [](const Game& game) {
            auto powerLevel = CalculatePowerLevel(game);
            return powerLevel;
        });
        return powerLevels;
    }

    unsigned long Part2::CalculatePowerLevel(const Game &game) {
        auto revealColorCounts = game.GetRevealColorCounts();
        unsigned long product = 1;
        for(const auto& revealColorCount : revealColorCounts) {
            for(const auto& [color, count] : revealColorCount) {
                product *= count;
            }
        }

        return product;
    }

    unsigned long Part2::SumPowerLevels(std::vector<unsigned long> powerLevels) {
        return std::accumulate(powerLevels.begin(), powerLevels.end(), 0UL);
    }
} // Day02