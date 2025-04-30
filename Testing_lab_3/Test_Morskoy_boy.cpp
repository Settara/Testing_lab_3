#include "Test_Morskoy_boy.h"
#include "Game.h"

//Первый тест который проверяет установку корабля
void Test_Morskoy_boy::test_place_ship() 
{
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

//Второй тест, который проверяет выстрел
void Test_Morskoy_boy::test_shot() {
    Board board(10);
    board.placeShip(0, 0, 2, true);
    assert(board.shoot(0, 0) == true);  //попал
    assert(board.shoot(0, 1) == true);  //попал
    assert(board.shoot(0, 2) == false); //мимо
}

//Третий тест, который проверяет все ли корабли потоплены
void Test_Morskoy_boy::test_all_ships_sunk() {
    Board board(10);
    board.placeShip(1, 1, 2, true);
    board.shoot(1, 1);
    board.shoot(1, 2);
    assert(board.allShipsSunk());
}

//Четвертый тест, который проверяет симуляцию игры
void test_game() {
    Game game;
    game.setup();
    game.playOneTurn();  //сделает 1 ход, не проверяем на результат
}




