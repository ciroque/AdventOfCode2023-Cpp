//
// Created by ciroque on 04/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY03_NUMBERLOCATION_H
#define ADVENT_OF_CODE_2023_C__DAY03_NUMBERLOCATION_H

#include <string>

#include "Location.h"

namespace Day03 {

    class NumberLocation : public Location {
    private:
        std::string m_Number;
        int m_Length;
    public:
        NumberLocation(int line, int column, std::string number, int length);
        [[nodiscard]] inline int GetNumber() const { return std::stoi(this->m_Number); }
        [[nodiscard]] inline std::string GetNumberString() const { return this->m_Number; }
        [[nodiscard]] inline int GetLength() const { return this->m_Length; };
    };

} // Day03

#endif //ADVENT_OF_CODE_2023_C__DAY03_NUMBERLOCATION_H
