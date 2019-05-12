#include <iostream>
#include <Windows.h>
using namespace std;//пространство имен
class pole {
private:
	int granix, graniy;
public:
	pole(int a, int b) {//рисует поле игры
		granix = a;
		graniy = b;
		for (int i = 0; i <= graniy; i++) {
			for (int q = 0; q <= granix; q++) {
				if ((i == 0 || i == graniy) || (q == 0 || q == granix)) {
					cout << "#";
				}
				else cout << " ";
			}
			cout << endl;
		}
	}
	bool prov(COORD lil) {
		if (lil.X == 0 || lil.Y == 0 || lil.X == granix || lil.Y == graniy)return true;
		else return false;
	}
};