// консольный дурак.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <ctime>
using namespace std;
int koloda[36];
int x;
int NUM=0;
int XOD = 0;
set <int> razdacha(set <int> karti) {
	srand(time(0));
	for (int i = size(karti); i < 6; i++) {
		x = rand() % 36;
		while (koloda[x] == -1) {
			x = rand() % 36;
		}
		karti.insert(koloda[x]);
		koloda[x] = -1;
	}
	return karti;
}
set <int> pokaz(set <int> karti) {
	for (auto now : karti) {
		cout << now << " ";
	}
	return karti;
}
set <int> igra(set <int> karti) {
	cin >> x;
	while (karti.find(x) == karti.end()) {
		cout << "обманывать не хорошо,играйте честно" << endl;
		cin >> x;
	}
	karti.erase(x);
	return karti;
}
set <int> komp(set <int> karti) {
	int i;
	for (i = 0; i <= 36; i++) {
		if (x < i&&karti.find(i) != karti.end()) {
			karti.erase(i); 
			cout << i << endl;
			break;
		}
	}
	if (i == 37) {
		karti.insert(x);
		XOD = XOD - 1;
	}
	return karti;
}
set <int> komphod(set <int> karti) {
	srand(time(0));
	x = (rand()+x) % 36;
	while (karti.find(x) == karti.end()) {
		x = (rand() + x) % 36;
	}
	cout << x <<"  -карта соперника  "<<endl;
	karti.erase(x);
	return karti;
}
set <int> chelik(set <int> karti) {
	int q,i;
	for (i = 0; i <= 36; i++) {
		if (x < i && karti.find(i) != karti.end())break;
	}
	if (i == 37) {
		karti.insert(x);
		XOD = XOD - 1;
		return karti;
	}
	cin >> q;
	while (q < x || karti.find(q) == karti.end()) {
		cout << "обманывать не хорошо,играйте честно" << endl;
		cin >> q;
	}
	karti.erase(q);
	return karti;
}
bool proverka() {
	int max = -1;
	NUM = 0;
	for (int i = 0; i < 36; i++) {
		if (koloda[i] >=1) {
			NUM++;
		}
		if (koloda[i] > max) {
			max = koloda[i];
		}
	}
	if (max != -1)return true;
	return false;
}

int main() {
	setlocale(0, "rus");
	set <int> karti;
	set <int> pshlnh;
	for (int i = 0; i < 36; i++) {
		koloda[i] = i+1;
	}
	while (proverka() == true) {
		karti = razdacha(karti);
		pshlnh = razdacha(pshlnh);
		proverka();
		cout << "в колоде осталось " << NUM << " карт" << endl;
		XOD = XOD + 1;
		pokaz(karti);
		cout << endl;
		//pokaz(pshlnh);
		//cout << endl;
		if (XOD % 2 == 1) {
			cout << "ваш ход"<<endl;
			karti = igra(karti);
			pshlnh = komp(pshlnh);
		}
		else {
			cout << "ход соперника"<<endl;
			pshlnh = komphod(pshlnh);
			karti = chelik(karti);
		}
	}
	while (true) {
		XOD = XOD + 1;
		pokaz(karti);
		cout << endl;
		//pokaz(pshlnh);
		//cout << endl;
		if (XOD % 2 == 1) {
			cout << "ваш ход"<<endl;
			karti = igra(karti);
			pshlnh = komp(pshlnh);
		}
		else {
			cout << "ход соперника"<<endl;
			pshlnh = komphod(pshlnh);
			karti = chelik(karti);
		}
		if (size(karti) == 0||size(pshlnh)==0) {
			if (size(karti) == 0) {
				cout << "вы победили" << endl;
				return 0;
			}
			else {
				cout << "вы проиграли" << endl;
				return 0;
			}
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
