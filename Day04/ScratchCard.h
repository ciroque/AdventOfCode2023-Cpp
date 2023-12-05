//
// Created by ciroque on 05/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY04_SCRATCHCARD_H
#define ADVENT_OF_CODE_2023_C__DAY04_SCRATCHCARD_H

#include <string>
#include <vector>

namespace Day04 {

    class ScratchCard {
    private:
        ScratchCard(unsigned long index, const std::vector<unsigned long>& numbers, const std::vector<unsigned long>& winningNumbers);

        unsigned long m_Index;
        std::vector<unsigned long> m_Numbers;
        std::vector<unsigned long> m_WinningNumbers;

    public:
        static ScratchCard Create(const std::string& input);
        std::vector<unsigned long> FindWinningNumbers();
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_SCRATCHCARD_H
