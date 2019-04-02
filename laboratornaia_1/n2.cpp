#include "pch.h"
#include "complexnii.h"
using namespace std;
int main()
{
	setlocale(0, "rus");
	int kolvo;
	double max = 0;
	int maxi = 0;
	complex a, b, rezult;
	ifstream fail;
	fail.open("keklolorbidol.txt");
	fail >> kolvo;
	complex *mass = new complex[kolvo];
	double *massabs = new double[kolvo];
	for (int i = 0; i < kolvo; i++) {
		fail >> mass[i].real;
		fail >> mass[i].imag;
		massabs[i] = abs(mass[i]);
	}
	fail.close();
	for (int i = 0; i < kolvo ; i++) {
		if (massabs[i] > max) {
			max = massabs[i];
			maxi = i;
		}
	}
	cout << "самое большое число:" << mass[maxi].real << "+i*" << mass[maxi].imag;
	cout << "его модуль:" << max;
}
