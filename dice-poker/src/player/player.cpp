#include "player.h"
#include <cstdarg>

Player::Player::Player()
{
    for (int i = 0; i < 5; i++)
    {
        this->dice.push_back(Dice());
    }
    this->score = 0;
    this->balance = 100;
    this->bet = 0;
}

Player::Player::Player(std::vector<Dice> dice)
{
    this->dice = dice;
    this->score = 0;
    this->balance = 100;
    this->bet = 0;
}

void Player::Player::play(void)
{
    for (int i = 0; i < this->dice.size(); i++)
    {
        this->round[i] = this->dice[i].roll();
    }
}

void Player::Player::play(int index...)
{
    va_list indeces;
    va_start(indeces, index);
    while (index < this->dice.size())
    {
        this->round[index] = this->dice[index].roll();
        index = va_arg(indeces, int);
    }
    va_end(indeces);
}