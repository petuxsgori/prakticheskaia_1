// курсовая zmeika.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <conio.h>//отвечает за реагирования на кнопки на клавиатуре и запоминания кнопки,которую нажали(_kbhit() & _getch())
#include "zmeiuka.h"
#include "zastavka.h"
#include "eda.h"
#include "pole.h"
#include "knopka.h"
#include "gamezzz.h"
using namespace std;//пространство имен

int main()
{
	srand(time(0));
	bool reshim=false;//переменная для выбора режима
	bool lose = false;//переменная,которая фиксирует "проигрыш"
	double speed, n = 1;//переменные,отвечающие за скорость перемещения змейки(speed) и условный таймер(n)
	int granix=60, graniy=28;//грани поля
	bool pas;
	int ochki = 0;//kekus-переменная для выбора уровня,ochki-кол-во набранных очков
	int razmer = 10;//размер змейки-1(последний символ это символ "стирания"-пробел
	setlocale(0, "rus");//подключение русского языка
	zastavka();//ф-ия,рисующая заставка
	menuska(speed, reshim);
	GAME(granix,graniy,ochki,razmer,reshim,speed,n,lose,pas);
	if(lose)lose=end_game(ochki);
	if (!lose)main();
	return 0;
}

