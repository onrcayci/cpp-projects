#include "dice.h"

#include <random>

Dice::Dice(void) {
    this->maxValue = 6;
}

Dice::Dice(int value) {
    this->maxValue = value;
}

int Dice::roll(void) {

    // obtain a seed
    std::random_device rd;

    // set seed
    std::mt19937 gen(rd());

    // instantiate uniform distribution random number generator for a dice
    std::uniform_int_distribution<> dice(1, this->maxValue);

    return dice(gen);
}