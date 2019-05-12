#include "obiekt.h"
class eda :public obiekt {
public:
	void pain() {
		SetConsoleCursorPosition(hConsole, pos);
		cout << ris;
	}
	eda generation_metka(int granix,int graniy) {
		eda metka;
		metka.pos.X = rand() % (granix - 3) + 2;
		metka.pos.Y = rand() % (graniy - 3) + 2;
		metka.ris = '*';
		metka.pain();
		return metka;
	}
	void ciela(vector <zmeiuka>& zmeka,vector <char> &knopka,int &razmer,char prov2,int granix,int graniy,int &ochki,COORD &cord) {
		if (zmeka[0].pos.X == pos.X&&zmeka[0].pos.Y == pos.Y) {//если змейка съела "еду"
			razmer++;
			zmeka.resize(razmer);
			knopka.resize(razmer);
			//speed = speed - 0.001;
			knopka[razmer - 1] = prov2;
			zmeka[razmer - 2].ris = 'x';
			zmeka[razmer - 1] = zmeka[razmer - 1].poyavlenie(zmeka[razmer - 1], prov2, cord);//на пустом месте появляется новый элемент
			pos.X = rand() % (granix - 3) + 2;
			pos.Y = rand() % (graniy - 3) + 2;
			for (int i = 0; i < razmer; i++) {//проверяет не зарандомила ли программа "еду" на саму змейку
				if (zmeka[i].pos.X == pos.X&&zmeka[i].pos.Y == pos.Y) {
					pos.X = rand() % (granix - 3) + 2;
					pos.Y = rand() % (graniy - 3) + 2;
				}
			}
			ochki = ochki + 5;
			ris = '*';
			zmeka[razmer - 1].ris = ' ';
			pain();
		}
	}
};
