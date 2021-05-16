#pragma once
#include "Player.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher &fly_direct(City cityTo);
        Dispatcher (Board &board, City city) : Player(board, city)
        {
        }
        std::string role()
        {
            return "Dispatcher";
        }
    };
}