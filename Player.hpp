#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Game.hpp"

using namespace std;


namespace coup{
    class Game;
    class Player
    {
    public:
        int _coins=0;
        string _role;
        string _name;
        Game _game;
        bool blocked;


    public:
        Player(Game game, string name){
            // _game = game;
            _name = name;
        }

        int coins(){
            return _coins;
        }
        string role(){
            return _name;
        }
        void income(){
            _coins++;
        }
        void foreign_aid(){
            _coins+=2;
        }

        void coup(Player other){
            // if (_coins<7){
            //     throw invalid_argument("not enough coins!");
            // }
            // else{
            //     _coins-=7;
            // }
        }




    
    };
};