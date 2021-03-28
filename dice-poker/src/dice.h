#ifndef DICE_H
#define DICE_H

class Dice
{
private:
    int maxValue;

public:
    Dice();
    Dice(int);
    int roll();
};

#endif