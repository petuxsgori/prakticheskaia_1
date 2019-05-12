#ifndef LOLKEK
#define LOLKEK
void vse_deistv(int razmer,vector <char>& knopka,vector <zmeiuka>& zmeka) {
	for (int i = 0; i < razmer - 1; i++) {//прогоняет для каждого 
		switch (knopka[i]) {
		case 75:
			if (knopka[i + 1] != 77) {//если предыдущая нажатая клавиша не была противоположной
				zmeka[0].ris = '<';
				zmeka[i] = zmeka[i].peremesh(zmeka[i], knopka[i]);//обращается к ф-ии перемещения для i-го элемента
			}
			else {
				knopka[0] = knopka[1];
				i--;
			}
			break;
		case 77:
			if (knopka[i + 1] != 75) {
				zmeka[0].ris = '>';
				zmeka[i] = zmeka[i].peremesh(zmeka[i], knopka[i]);
			}
			else {
				knopka[0] = knopka[1];
				i--;
			}
			break;
		case 80:
			if (knopka[i + 1] != 72) {
				zmeka[0].ris = 'v';
				zmeka[i] = zmeka[i].peremesh(zmeka[i], knopka[i]);
			}
			else {
				knopka[0] = knopka[1];
				i--;
			}
			break;
		case 72:
			if (knopka[i + 1] != 80) {
				zmeka[0].ris = '^';
				zmeka[i] = zmeka[i].peremesh(zmeka[i], knopka[i]);
			}
			else {
				knopka[0] = knopka[1];
				i--;
			}
			break;
		}
	}
	zmeka[razmer - 1] = zmeka[razmer - 1].peremesh(zmeka[razmer - 1], knopka[razmer - 1]);
}
#endif