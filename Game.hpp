
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Player;
    class Game
    {
    private:
        vector<Player> _players;
        

    public:
        string turn(){return "";}
        vector<string> players()
        {
            vector<string> names;
            return names;
        }
        int num_of_players(){
            return _players.size();
        }

    };
};