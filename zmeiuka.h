#include "obiekt.h"
class zmeiuka:public obiekt {//����� ������� �������� 2 ����������,����������� ������ � 2 ������
public:
	void sozdanie(int i,vector<char> &knopka,int razmer){
		pos.X = 30 + i;
		pos.Y = 10;
		ris = 'x';
		if (i == razmer - 1)ris = ' ';
		knopka[i] = 75;
	}
	//����� ����������� ������,������� ������������ ���������� ������� � ����������� �� ������� � ��������� ��� ������
	zmeiuka peremesh(zmeiuka a, char knop) {
		COORD Q;//���������� ���������,������� ����� ����������� ����� ���������� � ����������� �� ������� ������
		switch (knop) {
		case 75://�����
			Q.X = a.pos.X--;
			Q.Y = a.pos.Y;
			break;
		case 77://������
			Q.X = a.pos.X++;
			Q.Y = a.pos.Y;
			break;
		case 80://����
			Q.X = a.pos.X;
			Q.Y = a.pos.Y++;
			break;
		case 72://������
			Q.X = a.pos.X;
			Q.Y = a.pos.Y--;
			break;
		}
		SetConsoleCursorPosition(hConsole, Q);//��������� ������� �� ������ �������
		cout << a.ris;//����� ������� �� ���� �������
		return a;
	}
	//�-��,������� ���������� ���������� ���������� ��������,������� �������� ����� �������� "���"
	zmeiuka poyavlenie(zmeiuka a, char knop, COORD cord) {
		switch (knop) {
		case 75:
			a.pos.X = cord.X--;
			a.pos.Y = cord.Y;
			break;
		case 77:
			a.pos.X = cord.X++;
			a.pos.Y = cord.Y;
			break;
		case 80:
			a.pos.X = cord.X;
			a.pos.Y = cord.Y++;
			break;
		case 72:
			a.pos.X = cord.X;
			a.pos.Y = cord.Y--;
			break;
		}
		return a;
	}
	bool prov(vector <zmeiuka> zmeka,int razmer) {
		int a, b, x, y;
		for (int i = 0; i < razmer; i++) {
			for (int q = i + 1; q < razmer; q++) {
				a = zmeka[i].pos.X;
				b = zmeka[i].pos.Y;
				x = zmeka[q].pos.X;
				y = zmeka[q].pos.Y;
				if (a == x && b == y)return true;
			}
		}
		return false;
	}
};