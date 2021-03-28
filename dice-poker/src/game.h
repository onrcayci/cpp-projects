#ifndef GAME_H
#define GAME_H

#include "dice.h"

#include <vector>

class Game 
{
    private:
        std::vector<Dice> dice;
        std::vector<int> rollResult;
    public:
        Game();
        Game(std::vector<Dice>);
        std::vector<int> getRollResult();
        void rollDice();
        void rollDice(int index...);
};

#endif