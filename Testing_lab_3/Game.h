#pragma once
#include <iostream>

#include "Board.h"
#include <cstdlib>
#include <ctime>

class Game 
{
public:
    Game();
    void setup();
    void playOneTurn();
    void playTurnAuto();  //автоматический ход(ИИ)
    bool isGameOver() const;

private:
    void displayBoards() const;
    Board playerBoard;
    Board enemyBoard;
    bool playerTurn;
};

