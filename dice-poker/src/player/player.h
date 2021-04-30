#ifndef PLAYER_H
#define PLAYER_H

#include "../dice/dice.h"
#include <vector>

namespace Player
{
    class Player
    {
        private:
            std::vector<Dice> dice;
            std::vector<int> round;
            int score;
            int balance;
            int bet;
        public:
            Player();
            Player(std::vector<Dice>);
            void play();
            void play(int index...);
            std::vector<int> getRound();
            void setScore(int score);
            int getScore();
            void setBalance(int balance);
            int getBalance();
            void setBet(int amount);
            int getBet();        
    };
}

#endif