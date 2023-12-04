//
// Created by ciroque on 04/12/23.
//

#include "NumberLocation.h"

namespace Day03 {
    NumberLocation::NumberLocation(int line, int column, std::string number, int length) : Location(line, column) {
        this->m_Number = number;
        this->m_Length = length;
    }
} // Day03