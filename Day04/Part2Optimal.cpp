//
// Created by ciroque on 07/12/23.
//

#include "Part2Optimal.h"

namespace Day04 {
    std::string Part2Optimal::Solve(const std::string &puzzleInputFilename) {
        auto start = std::chrono::high_resolution_clock::now();
        unsigned long answer = 0;

        auto puzzleData = LoadPuzzleData(puzzleInputFilename);
        auto scratchCards = BuildScratchCards(puzzleData);
        auto winCountMap = CalculateWinCountMap(scratchCards);
        auto finalCounts = CalculateFinalCounts(winCountMap);
        answer = SumFinalCounts(finalCounts);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        std::cout << "Part2Optimal::Solve completed in " << duration << " milliseconds" << std::endl;

        return std::to_string(answer);
    }

    std::map<unsigned long, unsigned long> Part2Optimal::CalculateWinCountMap(std::vector<ScratchCard> scratchCard) {
        auto winCountMap = std::map<unsigned long, unsigned long>();

        for(auto& card : scratchCard) {
            auto winningNumbers = card.FindWinningNumbers();
            auto winningNumberCount = winningNumbers.size();
            auto scratchCardId = card.GetIndex();
            winCountMap[scratchCardId] = winningNumberCount;
        }

        return winCountMap;
    }

    std::map<unsigned long, unsigned long>
    Part2Optimal::CalculateFinalCounts(const std::map<unsigned long, unsigned long>& winCountMap) {
        std::map<unsigned long, unsigned long> finalCounts;

        // initialize finalCounts with all the scratch card ids
        for(auto& winCount : winCountMap) {
            finalCounts[winCount.first] = 1;
        }

        for(auto& winCount : winCountMap) {
            auto cardIndex = winCount.first;
            auto cardWinCount = winCount.second;
            auto upperBound = cardIndex + cardWinCount;

            for(unsigned long i = 0; i < finalCounts[cardIndex]; i++) {
                for(auto currentCardIndex = cardIndex + 1; currentCardIndex <= upperBound; currentCardIndex++) {
                    finalCounts[currentCardIndex]++;
                }
            }
        }
        return finalCounts;
    }

    unsigned long Part2Optimal::SumFinalCounts(const std::map<unsigned long, unsigned long>& finalCounts) {
        unsigned long sum = 0;
        for (auto finalCount : finalCounts) {
            sum += finalCount.second;
        }
        return sum;
    }
} // Day04