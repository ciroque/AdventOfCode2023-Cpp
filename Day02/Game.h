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
        unsigned long m_Id{};
        std::vector<std::map<std::string, int>> m_RevealColorCounts;

    public:
        Game(unsigned long id, std::vector<std::map<std::string, int>>& revealColorCounts);
        static Game Create(std::string const& input);

        [[nodiscard]] inline unsigned long GetId() const { return this->m_Id; }
        [[nodiscard]] inline std::vector<std::map<std::string, int>> GetRevealColorCounts() const { return this->m_RevealColorCounts; };
    };

} // Day

#endif //ADVENT_OF_CODE_2023_C___GAME_H
