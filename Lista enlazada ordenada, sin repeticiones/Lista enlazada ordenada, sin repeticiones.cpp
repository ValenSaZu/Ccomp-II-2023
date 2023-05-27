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
struct LE {
	nodo<T>* HEAD = NULL;
	void add(T x);
	bool del(T x);
	void find(T x, nodo <T> &*pos);
	void print();
	~LE();
};
template <class T>
void LE<T>::print() {
	cout << "HEAD->";
	for (nodo<T>* p = HEAD; operator!=, p->next) {
		cout << p->valor << "->";
	}
	cout << "NULL" << endl;
}

int main() {

}