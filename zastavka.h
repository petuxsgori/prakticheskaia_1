#include <iostream>
using namespace std;
class zastavka {
public:
	zastavka() {//эта функция рисует заставку
		char ster;
		for (int i = 0; i < 30; i++) {
			cout << "                                     ";
			if (i >= 10 && i <= 14) {
				for (int q = 0; q < 50; q++) {
					switch (i) {
					case 10:
						if ((q >= 0 && q <= 4) || (q == 7) || (q == 11) || (q >= 14 && q <= 18) || (q >= 21 && q <= 25) || (q == 28) || (q == 31) || (q == 36)) {
							cout << "*";
						}
						else cout << " ";
						break;
					case 11:
						if (((q == 3) || (q >= 7 && q <= 11 && q != 9) || (q == 14) || (q == 23) || (q == 28) || (q == 30) || (q == 35) || (q == 37))) {
							cout << "*";
						}
						else cout << " ";
						break;
					case 12:
						if (((q == 2) || (q == 7) || (q == 11) || (q == 9) || (q >= 14 && q <= 18) || (q == 23) || (q == 28) || (q == 29) || (q == 34) || (q == 38))) {
							cout << "*";
						}
						else cout << " ";
						break;
					case 13:
						if (((q == 1) || (q == 7) || (q == 11) || (q == 14) || (q == 23) || (q == 28) || (q == 30) || (q >= 34 && q <= 38))) {
							cout << "*";
						}
						else cout << " ";
						break;
					case 14:
						if (((q >= 0 && q <= 4) || (q == 7) || (q == 11) || (q >= 14 && q <= 18) || (q >= 21 && q <= 25) || (q == 28) || (q == 33) || (q == 39))) {
							cout << "*";
						}
						else cout << " ";
						break;
					}
				}
			}
			cout << endl;
		}
		SetConsoleCursorPosition(hConsole, { 38,17 });
		cout << "если хотите узнать об авторе нажмите 1";
		SetConsoleCursorPosition(hConsole, { 38,18 });
		cout << "если хотите узнать инструкцию нажмите 2";
		SetConsoleCursorPosition(hConsole, { 33,19 });
		cout << "если хотите продолжить нажмите любую другую кнопку";
		ster = _getch();//getch() запоминает "номер" нажатой кнопки
		if (ster == 49)system("avtor.txt");
		if (ster == 50)system("instruct.txt");
	}
};
