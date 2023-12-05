//
// Created by ciroque on 05/12/23.
//

#include "Part1.h"
#include "ScratchCard.h"

namespace Day04 {
    std::string Part1::Solve(const std::string &puzzleInputFilename) {
        auto puzzleData = Solution::LoadPuzzleData(puzzleInputFilename);
        auto scratchCards = BuildScratchCards(puzzleData);
        auto gameScores = CalculateGameScores(scratchCards);
        auto answer = CalculateAnswer(gameScores);

        return std::to_string(answer);
    }

    std::vector<ScratchCard> Part1::BuildScratchCards(const std::vector<std::string>& puzzleData) {
        std::vector<ScratchCard> scratchCards;

        for(auto& line : puzzleData) {
            auto scratchCard = ScratchCard::Create(line);
            scratchCards.push_back(scratchCard);
        }

        return scratchCards;
    }

    std::vector<unsigned long> Part1::CalculateGameScores(std::vector<ScratchCard>& scratchCards) {
        std::vector<unsigned long> gameScores;

        for(auto& scratchCard : scratchCards) {
            auto gameScore = scratchCard.FindWinningNumbers();
            gameScores.push_back(gameScore.size());
        }

        return gameScores;
    }

    unsigned long Part1::CalculateAnswer(const std::vector<unsigned long>& gameScores) {
        unsigned long answer = 0;
        for(auto& score : gameScores) {
            if(score == 0) {
                continue;
            }
            auto points = std::pow(2, score - 1);
            answer += points;
        }
        return answer;
    }
} // Day04
