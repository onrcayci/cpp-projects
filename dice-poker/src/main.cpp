/*
* Dice Poker main (game) method
* TODO:
* - Game Class
* -- choose die
* - Rules
*/

#include "game.h"

#include <iostream>

int main(void)
{
    Game game;
    game.rollDice();
    std::vector<int> firstRound = game.getRollResult();
    for (int result : firstRound)
    {
        std::cout << result << std::endl;
    }
    std::cout << std::endl;
    game.chooseAndRollDice(0, 1, 2, 3, 4);
    std::vector<int> secondRound = game.getRollResult();
    for (int result : secondRound)
    {
        std::cout << result << std::endl;
    }
    return 0;
}