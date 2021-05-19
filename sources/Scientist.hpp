#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        private:
        int CardsToCure=0;
    public:
        Scientist &discover_cure(Color color);
        Scientist (Board &board, City city, int numCardsToCure) : Player(board, city)
        {
            Player::gameBoard.scientist_num_cards_discover_cure= numCardsToCure;
        }
        std::string role()
        {
            return "Scientist";
        }
    };
}