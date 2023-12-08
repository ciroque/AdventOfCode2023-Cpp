//
// Created by ciroque on 06/12/23.
//

#include "Part1.h"

namespace Day05 {
    std::string Part1::Solve(const std::string &puzzleInputFilename) {
        std::string answer = "Not Implemented";

        auto puzzleInput = Solution::LoadPuzzleData(puzzleInputFilename);
        auto partitionedInput = PartitionPuzzleData(puzzleInput);

        return answer;
    }


    std::map<std::string, std::vector<std::string>> Part1::PartitionPuzzleData(const std::vector<std::string>& puzzleInput) {
        auto partitionedInput = std::map<std::string, std::vector<std::string>>();
        for(const auto& line : puzzleInput) {

            if(line.empty()) {
                continue;
            }

            // yoink the seeds
            const std::string seedKey = "seeds: ";
            auto const seedStartPos = line.find(seedKey);
            if(seedStartPos != std::string::npos) {
                auto ss = std::stringstream(line.substr(seedStartPos + seedKey.length()));
                std::string seed;
                while(ss >> seed) {
                    partitionedInput["seeds"].push_back(seed);
                }

                continue;
            }

            std::string currentKey;
            const std::string mapKey = "map:";
            auto const mapStartPos = line.find(mapKey);
            if(mapStartPos != std::string::npos) {
                currentKey = line.substr(0, mapStartPos);
                m_OrderedKeys.push_back(currentKey);
                partitionedInput[currentKey] = std::vector<std::string>({"placeholder"});

                continue;
            }


        }

        return partitionedInput;
    }
} // Day05