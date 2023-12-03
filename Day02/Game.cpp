//
// Created by ciroque on 02/12/23.
//

#include <iostream>
#include <sstream>
#include <utility>

#include "Game.h"

namespace Day02 {
    Game::Game(unsigned long id, std::vector<std::map<std::string, int>> &revealColorCounts) {
        this->m_Id = id;
        this->m_RevealColorCounts = std::move(revealColorCounts);
    }

    Game Game::Create(const std::string &input) {
        std::vector<std::map<std::string, int>> revealColorCounts;

        std::stringstream ss(input);
        std::string segment;

        unsigned long id;

        bool header = true;
        while (std::getline(ss, segment, ':')) {
            std::stringstream segmentStream(segment);
            std::string reveals;

            if(header) {
                header = false;
                std::string label;

                segmentStream >> label >> id;
            } else {
                header = true;

                while(std::getline(segmentStream, reveals, ';')) {
                    std::map<std::string, int> colorCounts;
                    std::stringstream revealsStream(reveals);
                    std::string pair;

                    while(std::getline(revealsStream, pair, ',')) {
                        std::stringstream pairStream(pair);
                        std::string color;
                        int count;

                        pairStream >> count >> color;
                        colorCounts[color] += count;
                    }
                    revealColorCounts.push_back(colorCounts);
                }
            }
        }

        return {id, revealColorCounts};
    }
} // Day