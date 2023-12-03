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
} // Day

