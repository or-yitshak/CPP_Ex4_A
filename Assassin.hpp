#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Assassin: public Player
    {
    private:
        

    public:
        Assassin(Game game, string name): Player(game, name){
            this->_role = "Assassin";
        }













        
    };
};