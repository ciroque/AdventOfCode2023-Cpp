//
// Created by ciroque on 02/12/23.
//

#include <iostream>
#include <sstream>
#include <utility>

#include "Game.h"

namespace Day02 {
    Game::Game(unsigned long id, std::vector<std::map<std::string, std::string>> reveals) {
        this->m_Id = id;
        this->m_Reveals = std::move(reveals);
    }

    Game Game::Create(const std::string &input) {
        std::string buffer;
        std::istringstream inputStream(input);

        std::getline(inputStream, buffer, ':');

        return {0, std::vector<std::map<std::string, std::string>>()};
    }
} // Day