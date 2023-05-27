//https://visualgo.net/en

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
	nodo<T>* HEAD = NULL;
	nodo<T>* TAIL = NULL;
	void Push(T v);
	bool Pop(T& v);
	void print();
};

template <class T>
void pila<T>::Push(T v) {
	if (!HEAD) {
		nodo<T>* NewNodo = new nodo<T>(v, TAIL);
		HEAD = HEAD->NewNodo;
	}
}

template <class T>
bool pila<T>::Pop(T& v) {
	bool res = false;
	if (HEAD) {
		v = HEAD->valor;
		nodo<T>* tmp = HEAD;
		HEAD = HEAD->next;
		delete tmp;
		res = true;
	}
	return res;
}
	
template <class T>
void pila<T>::print() {
	cout << "HEAD->";
	for (nodo<T>* p = HEAD; p; p->next) {
		cout << p->valor << "->";
	}
	cout << "NULL" << endl;
}

int main()
{
	pila<int> p;
	p.Push(1);
	p.Push(2);
	p.Push(3);

	p.print();

	/*
	bool cont = true;
	int x;

	while (cont) {
		cont = p.Pop(x);
		cout << x << endl;
	}
	*/
}