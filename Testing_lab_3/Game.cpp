#include "Game.h"

Game::Game() : playerBoard(10), enemyBoard(10) {}

void Game::setup() 
{
    playerBoard.placeShip(1, 1, 3, true);
    enemyBoard.placeShip(2, 2, 3, false);
}

void Game::playOneTurn() 
{
    int row, col;
    cout << "Введите координаты (Ряд Столбец): ";
    cin >> row >> col;
    bool hit = enemyBoard.shoot(row, col);
    cout << (hit ? "Попадание!" : "Мимо!") << endl;
}