#pragma once
#include <vector>

using namespace std;

//Код для первого теста, создание поля и установка корабля
class Board
{
public:
    Board(int size);
    bool placeShip(int row, int column, int length, bool horizontally);
    bool isThereShip(int row, int column) const;
    bool shoot(int row, int col);
    bool allShipsSunk() const;

private:
    int size_;
    vector<vector<char>> net;
};

