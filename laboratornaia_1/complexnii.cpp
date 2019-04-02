#include "pch.h"
#include "complexnii.h"
complex c;
complex syma(complex a,complex b) {
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
complex razn(complex a, complex b) {
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}
complex um(complex a, complex b) {
	c.real = a.real*b.real-a.imag*b.imag;
	c.imag = a.real*b.imag + b.real*a.imag;
	return c;
}
complex delit(complex a, complex b) {
	c.real = (a.real*b.real + a.imag*b.imag)/(pow(b.real,2)+ pow(b.imag, 2) );
	c.imag = (a.real*b.imag - a.imag*b.real) / (pow(b.real, 2) + pow(b.imag, 2));
	return c;
}
double abs(complex a) {
	return sqrt(pow(a.real, 2) + pow(a.imag, 2));
}
