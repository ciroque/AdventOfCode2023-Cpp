//
// Created by ciroque on 04/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY03_LOCATION_H
#define ADVENT_OF_CODE_2023_C__DAY03_LOCATION_H

namespace Day03 {

    class Location {
    private:
        int m_Line;
        int m_Column;

    public:
        Location(int line, int column);
        [[nodiscard]] inline int GetLine() const { return this->m_Line; };
        [[nodiscard]] inline int GetColumn() const { return this->m_Column; };
    };

} // Day03

#endif //ADVENT_OF_CODE_2023_C__DAY03_LOCATION_H
