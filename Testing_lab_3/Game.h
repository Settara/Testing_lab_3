#pragma once
#include <iostream>

#include "Board.h"


class Game 
{
public:
    Game();
    void setup();
    void playOneTurn();

private:
    Board playerBoard;
    Board enemyBoard;
};

