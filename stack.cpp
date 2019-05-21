#include "pch.h"
#include <string>
#include <iostream>
#include <set>
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
	set<int>::iterator lul;
	set <int> mn;
	date ke[5];
	set <date> vremia;
	cout << "введите 5 элементов из множества целых чисел" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		mn.insert(a);
	}
	cout << "удалили 3-й элемент" << endl;
	mn.erase(3);
	cout << "теперь множество выглядит так:" << endl;
	for (auto i: mn) {
		cout << i<<" ";
	}
	cout << "какой элемент вы хотите проверить?" << endl;
	cin >> a;
	/*lul= mn.find(a);
	if (lul==NULL)cout << " он есть" << endl;
	else cout << " его нету" << endl;*/
	cout << "размер множества- " << mn.size() << endl;
	cout << "теперь введите 5 дат,которые хотите внести в множество"<<endl;
	for (int i = 0; i < 5; i++) {
		cin >> ke[i].day;
		cin >> ke[i].name_month;
		cin >> ke[i].year;
		vremia.insert(ke[i]);
	}
	/*vremia.erase(ke[2]);
	cout << "проверка на то,осталась ли вторая дата после удаления ее из множества" << endl;
	if (vremia.erase(ke[2])cout << "дата  есть" << endl;
	else cout << " даты нету" << endl;*/
	cout << "оставшиеся даты множества:" << endl;
	for (auto i:vremia) {
		cout << i.day << " " << i.name_month << " " << i.year << endl;
	}
	
}
