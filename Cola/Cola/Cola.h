#include <iostream>

using namespace std;

class Cola
{
public:
	void push(int num);
	int pop();
	void print();
private:
	int A[10];
	int* Inicio = A;
	int* Fin = A + 9;
	int* tope = nullptr;
};
#pragma once

void Cola::push(int num)
{
	if (!tope) {
		tope = Inicio;
		*Inicio = num;
		cout << "El dígito " << num << " ya está en la cola" << endl;
	}
	else {
		if (tope < Fin)
		{
			tope++;
			*tope = num;
			cout << "El dígito " << num << " ya está en la cola" << endl;
		}
		else
		{
			cout << "Cola llena :("<< endl;
		}
	}
}

int Cola::pop()
{
	if (!tope) {
		cout << "Cola vacía :(" << endl;
	}
	else {
		if (tope >= Inicio)
		{
			int tmp = *Inicio;
			for (int* i = Inicio + 1; i <= tope; i++) {
				int* tmp2 = i - 1;
				*tmp2 = *i;
			}
			tope--;
			return tmp;
		}
	}
}
void Cola::print() {
	for (int* i = Inicio; i <= tope; i++) {
		cout << *i << " ";
	}
	cout << endl;
}
#pragma once
