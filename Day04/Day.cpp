//
// Created by ciroque on 05/12/23.
//

#include "ScratchCard.h"
#include "Part1.h"
#include "Day.h"

std::vector<Day04::ScratchCard> Day04::Day::BuildScratchCards(const std::vector<std::string>& puzzleData) {
    std::vector<ScratchCard> scratchCards;

    for(auto& line : puzzleData) {
        auto scratchCard = ScratchCard::Create(line);
        scratchCards.push_back(scratchCard);
    }

    return scratchCards;
}

namespace Day04 {
} // Day04