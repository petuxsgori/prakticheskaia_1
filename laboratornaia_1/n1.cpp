#include "pch.h"
#include "complexnii.h"
using namespace std;
void vvod(complex &a,complex& b) {
	cout << "вводите первое число(действительную часть,потом мнимую)" << endl;
	cin >> a.real >> a.imag;
	cout << "вводите второе число(так же)" << endl;
	cin >> b.real >> b.imag;
}
int main()
{
	setlocale(0, "rus");
	complex a,b,rezult;
	bool endprog=false;
	int kek;
	while (!endprog) {
		cout << "какую операцию вы хотите совершить с комплексными числами?(1:+,2:-,3:*,4:/,5:выйти из программы)" << endl;
		cin >> kek;
		system("cls");
		switch (kek) {
		case 1:
			vvod(a, b);
			rezult = syma(a, b);
			break;
		case 2:
			vvod(a, b);
			rezult = razn(a, b);
			break;
		case 3:
			vvod(a, b);
			rezult = um(a, b);
			break;
		case 4:
			vvod(a, b);
			rezult = delit(a, b);
			break;
		case 5:
			endprog = true;
			break;
		}
		if (kek != 5)
			cout << "результат:" << rezult.real << "+i*" << rezult.imag << endl;
	}
}
