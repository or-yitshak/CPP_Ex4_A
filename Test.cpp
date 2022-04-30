#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
Duke duke{game_1, "Moshe"};
Assassin assassin{game_1, "Yossi"};
Ambassador ambassador{game_1, "Meirav"};
Captain captain{game_1, "Reut"};
Contessa contessa{game_1, "Gilad"};

TEST_CASE("Good input")
{
    // first round
    duke.income();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();

    CHECK(duke.coins()==1);
    CHECK(assassin.coins()==1);
    CHECK(ambassador.coins()==1);
    CHECK(captain.coins()==1);
    CHECK(contessa.coins()==1);

    // this players cannot play because its the turn of the duke.
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());

    // second round
    duke.tax();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    CHECK(duke.coins()==4);
    CHECK(assassin.coins()==3);
    CHECK(ambassador.coins()==3);
    CHECK(captain.coins()==3);
    CHECK(contessa.coins()==3);

    // 3rd round

    duke.block(ambassador);
    assassin.coup(contessa);
    ambassador.foreign_aid();
    captain.steal(duke);
    contessa.block(assassin);

    CHECK(duke.coins()==4);
    CHECK(ambassador.coins() == 3);
    CHECK(game_1.num_of_players() == 5);
    CHECK(assassin.coins() == 0);

    // 4rd round
    duke.tax();
    assassin.income();
    ambassador.block(captain);
    captain.income();
    contessa.income();
    CHECK(duke.coins() == 7);
    

}

TEST_CASE("bad input")
{
    CHECK_THROWS(contessa.block(captain));
    CHECK_THROWS(contessa.block(duke));
    CHECK_THROWS(contessa.block(ambassador));
    CHECK_THROWS(contessa.block(contessa));

    CHECK_THROWS(captain.block(duke));
    CHECK_THROWS(captain.block(assassin));
    CHECK_THROWS(captain.block(ambassador));
    CHECK_THROWS(captain.block(contessa));

    CHECK_THROWS(ambassador.block(duke));
    CHECK_THROWS(ambassador.block(assassin));
    CHECK_THROWS(ambassador.block(ambassador));
    CHECK_THROWS(ambassador.block(contessa));
}