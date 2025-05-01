#include "Game.h"

Game::Game() : playerBoard(10), enemyBoard(10), playerTurn(true) 
{
    std::srand(std::time(nullptr));
}

void Game::setup() {
    playerBoard.placeShip(0, 0, 3, true);
    playerBoard.placeShip(2, 2, 2, false);

    enemyBoard.placeShip(5, 5, 3, true);
    enemyBoard.placeShip(7, 7, 2, false);
}

void Game::playOneTurn() {
    displayBoards();
    int row, col;
    std::cout << "Ваш ход (row col): ";
    std::cin >> row >> col;
    bool hit = enemyBoard.shoot(row, col);
    std::cout << (hit ? "Попадание!" : "Мимо!") << std::endl;
    playerTurn = false;
}

void Game::playTurnAuto() {
    if (isGameOver()) return;

    if (playerTurn) {
        int row = rand() % 10;
        int col = rand() % 10;
        enemyBoard.shoot(row, col);
        playerTurn = false;
    }
    else {
        int row = rand() % 10;
        int col = rand() % 10;
        playerBoard.shoot(row, col);
        playerTurn = true;
    }
}

bool Game::isGameOver() const {
    return playerBoard.allShipsSunk() || enemyBoard.allShipsSunk();
}

void Game::displayBoards() const {
    std::cout << "\nВаше поле:\n";
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            std::cout << playerBoard.net[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nПоле противника:\n";
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            std::cout << enemyBoard.net[i][j] << " ";
        }
        std::cout << "\n";
    }
}