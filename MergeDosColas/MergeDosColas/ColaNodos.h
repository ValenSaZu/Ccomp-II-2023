#pragma once
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
	if (!HEAD) {
		HEAD = NewNodo;
	}
	else {
		TAIL->next = NewNodo;
	}
	TAIL = NewNodo;
}

template <class T>
bool colaNodo<T>::Pop() {
	bool res = false;
	if (HEAD) {
		nodo<T>* tmp = HEAD;
		HEAD = HEAD->next;
		res = true;
		delete tmp;
	}
	return res;
}

template <class T>
void colaNodo<T>::print() {
	cout << "HEAD->";
	for (nodo<T>* p = HEAD; p; p = p->next) {
		cout << p->valor << "->";
	}
	cout << "NULL" << endl;
}