#ifndef GAME_H
#define GAME_H

#include "dice.h"

class Game 
{
    private:
        Dice * dice;
    public:
        Game();
        Game(Dice *);
};

#endif