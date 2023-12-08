//
// Created by ciroque on 05/12/23.
//

#include "Part2.h"

namespace Day04 {
    std::string Part2::Solve(const std::string &puzzleInputFilename) {
        auto start = std::chrono::high_resolution_clock::now();
        std::string answer = "Not Implemented";

        auto puzzleData = LoadPuzzleData(puzzleInputFilename);
        auto scratchCards = BuildScratchCards(puzzleData);
        auto bonusScratchCards = CalculateBonusScratchCards(scratchCards);

        answer = std::to_string(bonusScratchCards.size());

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        std::cout << "Part2Optimal::Solve completed in " << duration << " milliseconds" << std::endl;

        return answer;
    }

    std::vector<ScratchCard> Part2::CalculateBonusScratchCards(std::vector<ScratchCard> scratchCards) {
        std::map<unsigned long, std::vector<ScratchCard>> scratchCardMap;

        auto scratchCardCount = scratchCards.size();
        for(int scratchCardIndex = 0; scratchCardIndex < scratchCardCount; scratchCardIndex++) {
            auto scratchCard = scratchCards.at(scratchCardIndex);
            auto scratchCardId = scratchCard.GetIndex();

            scratchCardMap[scratchCardId] = {scratchCard};
        }

        for(auto& cardsById : scratchCardMap) {
            for(auto currentScratchCard : cardsById.second) {
                auto winningNumbers = currentScratchCard.FindWinningNumbers();
                auto winningNumberCount = winningNumbers.size();
                if(winningNumberCount > 0) {
                    auto bonusCardsStartIndex = currentScratchCard.GetIndex();
                    auto bonusCardsEndIndex = bonusCardsStartIndex + winningNumberCount;
                    for(auto bonusCardIndex = bonusCardsStartIndex; bonusCardIndex < bonusCardsEndIndex; bonusCardIndex++) {
                        auto bonusScratchCard = scratchCards.at(bonusCardIndex);
                        auto bonusScratchCardId = bonusScratchCard.GetIndex();
                        scratchCardMap[bonusScratchCardId].push_back(bonusScratchCard);
                    }
                }
            }
        }

        std::vector<ScratchCard> allScratchCards;

        for(auto& cardsById : scratchCardMap) {
            for(const auto& card : cardsById.second) {
                allScratchCards.push_back(card);
            }
        }

        return allScratchCards;
    }
} // Day04