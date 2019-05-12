#ifndef MENU
#define MENU
double level(char level) {//������ ���������,�.�. ��� �������,��� ����� ������������ ������ �� ���� ������� ������
	if (level == 49) return 0.12;
	if (level == 50)return 0.09;
	if (level == 51)return 0.05;
	if (level == 52)return 0.025;
}
bool end_game(int ochki) {
	char restart = 0;//����������,�������� ������,������� ����� �������,������� �������� � ���������� �� ���������� � ����������� �� �������
	SetConsoleCursorPosition(hConsole, { 40,40 });
	cout << "� ���������,�� ���������(((";
	SetConsoleCursorPosition(hConsole, { 40,41 });
	cout << "���� ���������� ����� : " << ochki;
	SetConsoleCursorPosition(hConsole, { 40,42 });
	cout << "���� ������ ������ ������ ������� ������,�����-esc";
	restart = _getch();
	while(restart != 32 && restart != 27) {
		restart = _getch();
	}
	if (restart == 32)return 0;
	else return 1;
}
bool pause(double &start,double &end,double &n,char knop) {
	SetConsoleCursorPosition(hConsole, { 80,10 });
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//��������� ����������� ����,����� ���� ����� ��� � �������
	cout << "�����.������� ������ ����� ����������";
	SetConsoleCursorPosition(hConsole, { 80,11 });
	cout << "���� ������ ����� � ����,������� 1";
	SetConsoleCursorPosition(hConsole, { 80,12 });
	cout << "���� ������ ����� �� ����,������� 2";
	while (!(knop == 32||knop==49||knop==50)) {//���� ��� ������� ����� �� ����
		end = 0;
		n = 1;
		start = 0;
		knop = _getch();
	}
	if (knop == 32) {
		start = clock();
		end = clock();
	}
	if (knop == 49) {
		return 1;
	}
	if (knop == 50) {
		SetConsoleCursorPosition(hConsole, { 30,35 });
		exit(0);
	}
	SetConsoleCursorPosition(hConsole, { 80,10 });
	cout << "                                        ";
	SetConsoleCursorPosition(hConsole, { 80,11 });
	cout << "                                        ";
	SetConsoleCursorPosition(hConsole, { 80,12 });
	cout << "                                        ";
	return 0;
}
void menuska(double &speed,bool &reshim) {
	char kekus = 1;
	system("cls");//������ ������� �� �����
	cout << "����:"<<endl;
	cout << "�������� �� ������-1 ��� ����������-2 ������� � ����-(����� ������ ������)" << endl;
	kekus = _getch();
	if (kekus == 49)system("avtor.txt");
	if (kekus == 50)system("instruct.txt");
	cout << "�������� ������� ��������� 1-�����,2-������,3-������,4-���������� " << endl;
	kekus = 0;
	while (kekus < 49 || kekus>53) {
		kekus = _getch();
	}
	speed = level(kekus);//�-�� ������ ������ ���������
	kekus = 0;
	cout << "������ �����(0) ��� ������ ����(1)?" << endl;
	while (kekus != 48 && kekus != 49) {
		kekus = _getch();
	}
	if (kekus == 48)reshim = false;
	else reshim = true;
	kekus = 0;
	cout << "�����-esc,���� ������ ������ ������� �� ����� ������" << endl;
	cout << "����� ������� ������ �������� ����� 1 ������� � ����� ������ ���������!������ � ����� ������!������� ������ ����� ������";
	while (kekus != 32) {
		kekus = _getch();
	}//���� �� ����� ����� ������,��������� �� �������� ������ 
	system("cls");
}

void GAME(int granix,int graniy,int &ochki,int razmer,bool reshim,double speed,double n,bool &lose,bool &pas) {
	pole pole(granix, graniy);//�����������,������ ���� ����
	vector <char> knopka(razmer);//������ �������� �� ������ ������� ������,������� ������� �� �������
	vector <zmeiuka> zmeka(razmer);//������ ������ ������� �������� ������
	COORD cord;//���������� ����������(����������)�������� ������
	int cvet;//���� ������
	char prov1 = 72, prov2;//2 ���������� ��� �������� �� ������� ������������� ������
	eda metka;//"���" ������
	//������� �����(��������� ���������,�� ����������� � ����
	metka = metka.generation_metka(granix, graniy);
	for (int i = 0; i < razmer; i++) {
		zmeka[i].sozdanie(i, knopka, razmer);
	}
	double start = clock(), end = clock();//���������� ���������� �����
	double	t = (end - start) / CLOCKS_PER_SEC;//t,����������� ����� � �������
	while (!lose) {//���� �� ��������
		t = (end - start) / CLOCKS_PER_SEC;//����������,���������� ������ ��� ��������� ����� ����� ���������� ������ ������� �����
		cord = zmeka[razmer - 1].pos;
		end = clock();
		SetConsoleCursorPosition(hConsole, { 0,0 });
		if (_kbhit()) {//���� ��������� �������
			knopka[0] = _getch();
		}
		if ((knopka[0] == 27) && prov1 != knopka[0]) {//���� ������� ������� ������ �� �����
			pas=pause(start, end, n, knopka[0]);
			if (pas)break;
		}
		if (knopka[0] != 75 && knopka[0] != 77 && knopka[0] != 80 && knopka[0] != 72) {//������ �������������� �� ������ ������(������ ��� esc))
			knopka[0] = prov1;
		}
		prov1 = knopka[0];//��������� ��� ��������
		prov2 = knopka[razmer - 1];//��������� ��� ����,��� ���� �� ������ "���",�� ����������� �� ������ ��������� 
		if ((t > n)) {//���� ������ ������ ���������� �������
			if (reshim == 1) {//������ ����
				cvet = rand() % 15 + 1;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | cvet));
			}
			vse_deistv(razmer, knopka, zmeka);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			if (knopka[0] == 75 || knopka[0] == 77) {
				n = n + speed;
			}
			else n = n + speed * 2;
			metka.ciela(zmeka, knopka, razmer, prov2, granix, graniy, ochki, cord);
			zmeka[razmer - 1].ris = ' ';
			for (int i = razmer - 1; i > 0; i--) {//����������� �������� �� ���� ������� �����
				knopka[i] = knopka[i - 1];
			}
		}
		//������ ��������� ��������� �� ������ ����-����
		lose = pole.prov(zmeka[0].pos);
		if (lose == false) {
			lose = zmeka[0].prov(zmeka, razmer);
		}
	}
}
#endif 