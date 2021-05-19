#pragma once
#include "Player.hpp"

using namespace std;
namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic &treat(City cityTo);
        Medic (Board &board, City city) : Player(board, city)
        {
        }
        Medic &fly_shuttle(City cityTo);
        Medic &fly_direct(City cityTo);
        Medic &fly_charter(City cityTo);
        Medic &drive(City cityTo);
        
        std::string role()
        {
            return "Medic";
        }
    };
}