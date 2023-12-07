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
        ScratchCard(unsigned long index, ScratchCard& other) {
            this->m_Index = index;
            this->m_Numbers = other.m_Numbers;
            this->m_WinningNumbers = other.m_WinningNumbers;
        };
        static ScratchCard Create(const std::string& input);
        std::vector<unsigned long> FindWinningNumbers();

         [[nodiscard]] inline unsigned long GetIndex() const { return m_Index; };

        void SetIndex(unsigned long index) { m_Index = index; };
    };

} // Day04

#endif //ADVENT_OF_CODE_2023_C__DAY04_SCRATCHCARD_H
