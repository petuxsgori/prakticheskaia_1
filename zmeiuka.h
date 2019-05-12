#include "obiekt.h"
class zmeiuka:public obiekt {//класс который содержит 2 переменные,описывающие змейку и 2 метода
public:
	void sozdanie(int i,vector<char> &knopka,int razmer){
		pos.X = 30 + i;
		pos.Y = 10;
		ris = 'x';
		if (i == razmer - 1)ris = ' ';
		knopka[i] = 75;
	}
	//метод перемещения змейки,который переставляет переданный элемент в зависимости от ножатой в последний раз кнопки
	zmeiuka peremesh(zmeiuka a, char knop) {
		COORD Q;//переменная координат,которой будем присваивать новые координаты в зависимости от нажатой кнопки
		switch (knop) {
		case 75://влево
			Q.X = a.pos.X--;
			Q.Y = a.pos.Y;
			break;
		case 77://вправо
			Q.X = a.pos.X++;
			Q.Y = a.pos.Y;
			break;
		case 80://вниз
			Q.X = a.pos.X;
			Q.Y = a.pos.Y++;
			break;
		case 72://наверх
			Q.X = a.pos.X;
			Q.Y = a.pos.Y--;
			break;
		}
		SetConsoleCursorPosition(hConsole, Q);//установка курсора на нужную позицию
		cout << a.ris;//вывод символа на этой позиции
		return a;
	}
	//ф-ия,которая определяет координаты последнего элемента,который появился после поедания "еды"
	zmeiuka poyavlenie(zmeiuka a, char knop, COORD cord) {
		switch (knop) {
		case 75:
			a.pos.X = cord.X--;
			a.pos.Y = cord.Y;
			break;
		case 77:
			a.pos.X = cord.X++;
			a.pos.Y = cord.Y;
			break;
		case 80:
			a.pos.X = cord.X;
			a.pos.Y = cord.Y++;
			break;
		case 72:
			a.pos.X = cord.X;
			a.pos.Y = cord.Y--;
			break;
		}
		return a;
	}
	bool prov(vector <zmeiuka> zmeka,int razmer) {
		int a, b, x, y;
		for (int i = 0; i < razmer; i++) {
			for (int q = i + 1; q < razmer; q++) {
				a = zmeka[i].pos.X;
				b = zmeka[i].pos.Y;
				x = zmeka[q].pos.X;
				y = zmeka[q].pos.Y;
				if (a == x && b == y)return true;
			}
		}
		return false;
	}
};