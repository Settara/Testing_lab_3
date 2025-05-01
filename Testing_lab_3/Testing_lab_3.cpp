// Testing_lab_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "Test_Morskoy_boy.h"
#include "Game.h"


int main()
{
    setlocale(LC_ALL, "RUS");
    
    //Секция тестов
   
    //Создаем объект класса с тестами
    Test_Morskoy_boy test_first;

    //Проверяем работу первого теста
    test_first.test_place_ship();

    //Проверяем работу второго теста
    test_first.test_shot();

    //Проверяем работу третьего теста
    test_first.test_all_ships_sunk();

    //Проверяем работу четвертого теста
    test_first.test_game();

    //Проверяем работу пятого теста
    test_first.test_game_cycle();

    cout << endl << "Тесты прошли успешно!" << endl;
    
    //Секция Игры

    Game game;
    game.setup();

    while (!game.isGameOver()) {
        game.playOneTurn(); // пользовательский ввод
        if (!game.isGameOver()) {
            game.playTurnAuto(); // ход ИИ
        }
    }

    std::cout << "Игра окончена!\n";

    return 0;
}


