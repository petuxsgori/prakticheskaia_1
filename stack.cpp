
#include "pch.h"
#include <string>
#include <iostream>
#include <stack>
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
	friend ostream& operator<< (ostream &out,const date &data) {
		out << data.day << " " << data.name_month << " " << data.year << endl;
		return out;
	}
};

int main()
{
	setlocale(0, "rus");
	bool ka=0;
	int a;
	stack <int> mn;
	date ke[5];
	stack <date> vremia;
	cout << "введите 5 элементов в стэка целых чисел" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		mn.push(a);
	}
	cout << "удалили верхний элемент"<<endl;
	mn.pop();
	cout << "размер стека стал- " << mn.size() << endl;
	cout << "теперь стэк выглядит так:" << endl;
	while (!mn.empty()) {
		cout << mn.top()<<" ";
		mn.pop();
	}
	cout << "теперь стек пустойv" << endl;
	cout << "размер стека- " << mn.size() << endl;
	cout << "теперь введите 5 дат,которые хотите внести в множествоv"<<endl;
	for (int i = 0; i < 5; i++) {
		cin >> ke[i].day;
		cin >> ke[i].name_month;
		cin >> ke[i].year;
		vremia.push(ke[i]);
	}
	vremia.pop();
	cout << "вытолкнули верхний элемент стэкаv" << endl;
	cout << " теперь размер стэка стал-"<<vremia.size();
	cout << "оставшиеся даты стэка и их удаление:" << endl;
	while (!vremia.empty()) {
		cout<<vremia.top()<<endl;
		vremia.pop();
	}
}
