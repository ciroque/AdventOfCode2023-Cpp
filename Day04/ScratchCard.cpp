//
// Created by ciroque on 05/12/23.
//
#include <sstream>

#include "ScratchCard.h"

namespace Day04 {
    ScratchCard::ScratchCard(unsigned long index, const std::vector<unsigned long>& numbers, const std::vector<unsigned long>& winningNumbers) {
        this->m_Index = index;
        this->m_Numbers = numbers;
        this->m_WinningNumbers = winningNumbers;

    }

    ScratchCard ScratchCard::Create(const std::string &input) {
        std::vector<unsigned long> myNumbers;
        std::vector<unsigned long> winningNumbers;
        std::string segment;
        std::stringstream ss(input);
        bool inPreamble = true;
        unsigned long id;

        while(std::getline(ss, segment, ':')) {
            std::stringstream segmentStream(segment);
            std::string numberses;

            if(inPreamble) {
                inPreamble = false;
                std::string label;
                segmentStream >> label >> id;
            } else {
                inPreamble = true;
                bool inWinningNumbers = true;

                while(std::getline(segmentStream, numberses, '|')) {
                    std::stringstream numbersesStream(numberses);

                    if(inWinningNumbers) {
                        inWinningNumbers = false;
                        std::string winningNumber;
                        while(std::getline(numbersesStream, winningNumber, ' ')) {
                            if(winningNumber.empty()) {
                                continue;
                            }
                            std::stringstream winningNumberStream(winningNumber);
                            unsigned long number;
                            winningNumberStream >> number;
                            winningNumbers.push_back(number);
                        }
                    } else {
                        inWinningNumbers = true;
                        std::string myNumber;
                        while(std::getline(numbersesStream, myNumber, ' ')) {
                            if(myNumber.empty()) {
                                continue;
                            }
                            std::stringstream numberStream(myNumber);
                            unsigned long number;
                            numberStream >> number;
                            myNumbers.push_back(number);
                        }
                    }
                }
            }
        }

        return {id, myNumbers, winningNumbers};
    }

    std::vector<unsigned long> ScratchCard::FindWinningNumbers() {
        std::vector<unsigned long> winningNumbers;

        for(const auto& number : m_Numbers) {
            for(const auto& winningNumber : m_WinningNumbers) {
                if(number == winningNumber) {
                    winningNumbers.push_back(number);
                }
            }
        }

        return winningNumbers;
    }

} // Day04