/*
* Dice Poker main (game) method
* TODO:
* - Game Class
* -- constructor
* -- play round
* -- choose die
* - Rules
*/

#include "dice.h"

#include <iostream>

int main(void) {
    Dice die;
    int value = die.roll();
    std::cout << value << std::endl;
    return 0;
}