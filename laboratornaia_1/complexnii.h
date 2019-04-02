#ifndef COMPLEXNII_H
#define COMPLEXNII_H
#include <iostream>
#include <cmath>
#include <fstream>
class complex {
public:
	double real;
	double imag;
};
complex syma(complex a, complex b);
complex razn(complex a, complex b);
complex um(complex a, complex b);
complex delit(complex a, complex b);
double abs(complex a);
#endif
