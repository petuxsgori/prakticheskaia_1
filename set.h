#pragma once
#include "pch.h"
#include <string>
#include <iostream>
using namespace std;
template <class t>
class set {
private:
	t *x;
	int n;
public:
	set() {
		n = 0; x = 0;
	}
	void push(t a);
	bool prov(t a) {
		for (int i = 0; i < n; i++) {
			if (a == x[i])return true;
		}
		return false;
	}
	int sizemn() {
		return n;
	}
	void vivod(int i) {
		cout << x[i];
	}
	void erase(int a);
};
template <class t>
void set<t>::push(t a) {
	if (n == 0) {
		t *x = new t[1];
	}
	if (!(this->prov(a))) {
		x = (t*)realloc(x, sizeof(t)*(n + 1));
		x[n] = a;
		n++;
	}
}
template <class t>
void set<t>::erase(int numb) {

	for (numb; numb < n-1; numb++) {
		swap(x[numb], x[numb + 1]);
	}
	x = (t*)realloc(x, sizeof(t)*(n - 1));
	n--;
}
