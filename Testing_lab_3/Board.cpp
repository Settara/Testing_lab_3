#include "Board.h"

Board::Board(int size) : size_(size), net(size, vector<char>(size, '0')) {}

bool Board::placeShip(int row, int column, int length, bool horizontally) 
{
    //Проверка, помещается ли корабль в пределах поля
    if (horizontally && column + length > size_) return false;
    if (!horizontally && row + length > size_) return false;

    //Проверка, свободно ли место для корабля
    for (int i = 0; i < length; ++i) 
    {
        int r = row + (horizontally ? 0 : i);
        int c = column + (horizontally ? i : 0);
        if (net[r][c] != '0') return false;
    }

    //Размещение корабля
    for (int i = 0; i < length; ++i) 
    {
        int r = row + (horizontally ? 0 : i);
        int c = column + (horizontally ? i : 0);
        net[r][c] = '1';
    }
    return true;
}

bool Board::isThereShip(int row, int column) const 
{
    return net[row][column] == '1';
}

bool Board::shoot(int row, int col) 
{
    if (net[row][col] == '1') {
        net[row][col] = 'X';
        return true;
    }
    else {
        net[row][col] = '.';
        return false;
    }
}

bool Board::allShipsSunk() const 
{
    for (const auto& row : net) 
    {
        for (auto& cell : row) 
        {
            if (cell == '1') return false;
        }
    }
    return true;
}

