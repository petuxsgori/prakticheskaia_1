// stack2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include <string>
#include <iostream>
#include "set.h"
using namespace std;
class date {
public:
	int day;
	string name_month;
	int year;
	bool operator ==(date data) {
		if (this->day == data.day) {
			if (this->name_month == data.name_month) {
				if (this->year == data.year) {
					return true;
				}
			}
		}
		return false;
	}
	void operator=(date data) {
		this->day = data.day;
		this->name_month = name_month;
		this->year = year;
	}
};

int main()
{
	setlocale(0, "rus");
	int a;
	set <int> mn;
	set <date> vremia;
	date ke;
	cout << "введите 5 элементов из множества целых чисел" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		mn.push(a);
	}
	cout << "удалили 3-й элемент" << endl;
	mn.erase(3);
	cout << "теперь множество выглядит так:" << endl;
	for (int i = 0; i < mn.sizemn(); i++) {
		mn.vivod(i);
	}
	cout << "какой элемент вы хотите проверить?" << endl;
	cin >> a;
	if (mn.prov(a))cout << " он есть" << endl;
	else cout << " его нету" << endl;
	cout << "размер множества- " << mn.sizemn() << endl;
	cout << "теперь введите 5 дат,которые хотите внести в множество"<<endl;
	for (int i = 0; i < 5; i++) {
		cin >> ke.day>>ke.name_month>>ke.year;
		vremia.push(ke);
	}
	vremia.erase(2);
	cout << vremia.prov(ke);
	
	
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
