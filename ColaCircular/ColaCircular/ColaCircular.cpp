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
	nodo<T>* NewNodo = new nodo<T>(v, nullptr);
	if (!HEAD) {
		HEAD = NewNodo;
		HEAD->next = HEAD;
	}
	else {
		TAIL->next = NewNodo;
		NewNodo->next = HEAD;
	}
	TAIL = NewNodo;
}

template <class T>
bool colaNodo<T>::Pop() {
	bool res = false;
	if (HEAD) {
		nodo<T>* tmp = HEAD;
		HEAD = HEAD->next;
		if (HEAD == TAIL) {
			HEAD = nullptr;
			TAIL = nullptr;
		}
		else {
			TAIL->next = HEAD;
		}
		delete tmp;
		res = true;
	}
	return res;
}

template <class T>
void colaNodo<T>::print() {
	cout << "HEAD->";
	if (HEAD != nullptr) {
		nodo<T>* p = HEAD;
		do {
			cout << p->valor << "->";
			p = p->next;
		} while (p != HEAD);
	}
	cout << "HEAD" << endl;
}

int main()
{
	colaNodo<int> p;
	for (int i{ 1 }; i <= 10; i++) {
		p.Push(i);
		p.print();
	}

	bool cont = true;

	while (cont) {
		cont = p.Pop();
		p.print();
	}
	p.Push(19);
	p.print();
}