#pragma once
#include <iostream>
#include <Windows.h>//для использования функционала ОС
#include <ctime>//отвечает за рандом и время
#include <vector>//библиотека для нашей змейки,т.к. она будет вектором структур zmeiyka
using namespace std;//пространство имен
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class obiekt {
public:
	COORD pos;//координаты каждого "куска" змейки или самого куска
	char ris;//то,что рисуется(либо *,либо головка,либо символ "стирания",т.е. пробел

};