//
// Created by ciroque on 04/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY03_PART2_H
#define ADVENT_OF_CODE_2023_C__DAY03_PART2_H

#include <algorithm>

#include "Day.h"
#include "Location.h"

namespace Day03 {

    class Part2 : public Day {
    private:
        static std::vector<Location> FindAsteriskIndices(const std::vector<std::string>& puzzleData);
    public:
        std::string Solve(const std::string& puzzleInputFilename);

        static std::vector<NumberLocation>
        FindAdjacentNumberIndices(int lineNumber, const std::vector<NumberLocation>& numberIndices);

        static std::vector<int>
        FindGearRatios(const std::vector<NumberLocation> &numberIndices, std::vector<Location> &asteriskIndices) ;

        static int SumGearRatios(std::vector<int> &gearRatios) ;
    };

} // Day03

#endif //ADVENT_OF_CODE_2023_C__DAY03_PART2_H
