#pragma once
#include <iostream>
#include <Windows.h>//��� ������������� ����������� ��
#include <ctime>//�������� �� ������ � �����
#include <vector>//���������� ��� ����� ������,�.�. ��� ����� �������� �������� zmeiyka
using namespace std;//������������ ����
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class obiekt {
public:
	COORD pos;//���������� ������� "�����" ������ ��� ������ �����
	char ris;//��,��� ��������(���� *,���� �������,���� ������ "��������",�.�. ������

};