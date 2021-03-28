#include "game.h"

#include <cstdarg>

Game::Game(void)
{
    for (int i = 0; i < 5; i++)
    {
        this->dice.push_back(Dice());
    }
}

Game::Game(std::vector<Dice> dice)
{
    this->dice = dice;
}

std::vector<int> Game::getRollResult(void)
{
    return this->rollResult;
}

void Game::rollDice(void)
{
    for (int i = 0; i < this->dice.size(); i++)
    {
        this->rollResult.push_back(this->dice[i].roll());
    }
}

void Game::chooseAndRollDice(int index...)
{
    va_list indeces;
    va_start(indeces, index);
    while (index < this->dice.size())
    {
        this->rollResult[index] = this->dice[index].roll();
        index = va_arg(indeces, int);
    }
    va_end(indeces);
}