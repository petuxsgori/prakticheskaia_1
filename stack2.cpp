#include "pch.h"
#include <string>
#include <iostream>
#include "set.h"
using namespace std;
class date {
public:
	int day;
	char *name_month=new char[20];
	int year;
	bool operator ==(date data) {
		bool alp;
		((this->day == data.day) && (this->name_month == data.name_month) && (this->year == data.year)) ? (alp = true) : (alp = false);
		return alp;
	}
	void operator=(date data) {
		this->day = data.day;
		this->name_month = data.name_month;
		this->year = data.year;
	}
};

int main()
{
	setlocale(0, "rus");
	int a;
	set <int> mn;
	date ke[5];
	set <date> vremia;
	cout << "введите 5 элементов из множества целых чисел" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		mn.push(a);
	}
	cout << "удалили 3-й элемент" << endl;
	mn.erase(3);
	cout << "теперь множество выглядит так:" << endl;
	for (int i = 0; i < mn.sizemn(); i++) {
		a=mn.vivod(i);
		cout << a;
	}
	cout << "какой элемент вы хотите проверить?" << endl;
	cin >> a;
	if (mn.prov(a))cout << " он есть" << endl;
	else cout << " его нету" << endl;
	cout << "размер множества- " << mn.sizemn() << endl;
	cout << "теперь введите 5 дат,которые хотите внести в множество"<<endl;
	for (int i = 0; i < 5; i++) {
		cin >> ke[i].day;
		cin >> ke[i].name_month;
		cin >> ke[i].year;
		vremia.push(ke[i]);
	}
	vremia.erase(2);
	cout << "проверка на то,осталась ли вторая дата после удаления ее из множества" << endl;
	if (vremia.prov(ke[2]))cout << "дата  есть" << endl;
	else cout << " даты нету" << endl;
	cout << "оставшиеся даты множества:" << endl;
	for (int i = 0; i < vremia.sizemn(); i++) {
		ke[i]=vremia.vivod(i);
		cout << ke[i].day << " " << ke[i].name_month << " " << ke[i].year << endl;
	}
	
}
