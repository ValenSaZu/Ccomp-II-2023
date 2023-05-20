
#include <iostream>

using namespace std;

template <class T>
struct nodo {
	T valor;
	nodo<T>* next;
	nodo(T v, nodo<T>* n = nullptr)
	{
		valor = v;
		next = n;
	}
};

template <class T>
struct pila {
	nodo<T>* top = NULL;
	void Push(T v);
	bool Pop(T& v);
};

template <class T>
void pila<T>::Push(T v) {
	top = new nodo <T>(v, top);
}

template <class T>
bool pila<T>::Pop(T& v) {
	bool res = false;
	if (top) {
		v = top->valor;
		nodo<T>* tmp = top;
		top = top->next;
		delete tmp;
		res = true;
	}
	return res;
}

int main()
{
	pila<int> p;
	p.Push(1);
	p.Push(2);
	p.Push(3);

	bool cont = true;
	int x;

	while (cont) {
		cont = p.Pop(x);
		cout << x << endl;
	}
}