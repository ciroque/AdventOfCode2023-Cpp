//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___PART2_H
#define ADVENT_OF_CODE_2023_C___PART2_H

#include <map>
#include "Part1.h"

namespace Day01 {
    class Part2 : public Day::Day {
    private:
        static std::vector<std::pair<std::string, std::string>> SpelledNumbers;

        static inline bool comparator(std::string l, std::string r) { return l.length() < r.length(); };

    public:
        std::string Solve(const std::string& puzzleInputFilename) override;

        static std::vector<std::string> ResolveSpelledNumbers(const std::vector<std::string>& puzzleData);

        static std::string ResolveSpelledNumber(std::string &line);

        void printChangesTable(std::vector<std::string> &puzzleData, std::vector<std::string> &resolvedSpelledNumbers,
                               std::vector<std::string> &puzzleDataOnlyNumbers,
                               std::vector<std::string> &calibrationValues) const;

        static void CheckForOverlappingIndices(std::string &line,
                                               std::vector<std::pair<unsigned long, std::pair<std::string, std::string>>> indices);
    };
}

#endif //ADVENT_OF_CODE_2023_C___PART2_H
