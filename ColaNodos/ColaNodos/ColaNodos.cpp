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
struct colaNodo {
	nodo<T>* HEAD = NULL;
	nodo<T>* TAIL = NULL;
	void Push(T v);
	bool Pop();
	void print();
};

template <class T>
void colaNodo<T>::Push(T v) {
	nodo<T>* NewNodo = new nodo<T>(v, NULL);
	if (HEAD==NULL) {
		HEAD = NewNodo;
		TAIL = NewNodo;
	}
	else {
		TAIL->next = NewNodo;
		TAIL = NewNodo;
	}
}

template <class T>
bool colaNodo<T>::Pop() {
	bool res = false;
	if (HEAD) {
		HEAD = HEAD->next;
		res = true;
	}
	return res;
}

template <class T>
void colaNodo<T>::print() {
	cout << "HEAD->";
	for (nodo<T>* p = HEAD; p; p=p->next) {
		cout << p->valor << "->";
	}
	cout << "NULL" << endl;
}

int main()
{
	colaNodo<int> p;
	for (int i{1}; i <= 10; i++) {
		p.Push(i);
	}
	p.print();

	bool cont = true;

	while (cont) {
		cont = p.Pop();
		p.print();
	}
}