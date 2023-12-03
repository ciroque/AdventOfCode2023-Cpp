//
// Created by ciroque on 02/12/23.
//

#ifndef ADVENT_OF_CODE_2023_C__DAY02_GAME_H
#define ADVENT_OF_CODE_2023_C__DAY02_GAME_H

#include <string>
#include <vector>
#include <map>

namespace Day02 {
    class Game {
    private:
        unsigned long m_Id;
        std::vector<std::map<std::string, std::string>> m_Reveals;

    public:
        Game(unsigned long id, std::vector<std::map<std::string, std::string>> reveals);
        static Game Create(std::string const& input);
    };

} // Day

#endif //ADVENT_OF_CODE_2023_C___GAME_H
