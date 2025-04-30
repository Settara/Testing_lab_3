#include "Test_Morskoy_boy.h"
#include "Board.h"
#include <cassert>

//Первый тест который проверяет установку корабля
void Test_Morskoy_boy::test_place_ship() {
    //Создаем поле размера 10 на 10
    Board board(10);
    //Проверяем работу метода установки корабля
    bool success = board.placeShip(2, 3, 4, true); //корабль стоит горизонтально на клетке 2 3, длина корабля 4
    assert(success);
    assert(board.isThereShip(2, 3));
    assert(board.isThereShip(2, 4));
    assert(board.isThereShip(2, 5));
    assert(board.isThereShip(2, 6));
}



