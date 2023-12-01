//
// Created by ciroque on 01/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C___PART01_H
#define ADVENT_OF_CODE_2023_C___PART01_H

#include <vector>

namespace Day01 {
    class Part01 {
    private:
        std::string puzzleInputFilename;
        std::vector<std::string> puzzleData;

        void LoadPuzzleData();
        void ProcessInput();
        void RemoveCharacters();

    public:
        std::string Solve();

        Part01(std::string puzzleInputFilename);
    };
}



#endif //ADVENT_OF_CODE_2023_C___PART01_H
