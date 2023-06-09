#include <iostream>
#include "ColaNodos.h"

void MergeColas(colaNodo<int>& p, colaNodo<int>& q) {
    nodo<int>* a = p.HEAD;
    nodo<int>* b = q.HEAD;
    nodo<int>* tmp = nullptr;
    while (a && b) {
        if (a->valor > b->valor) {
            if (tmp) {
                tmp->next = b;
            }
            else {
                p.HEAD = b;
            }
            tmp = b;
            b = b->next;
            tmp->next = a;
        }
        else {
            tmp = a;
            a = a->next;
        }
    }
    if (b) {
        if (tmp) {
            tmp->next = b;
        }
        else {
            p.HEAD = b;
        }
    }
    q.HEAD = p.HEAD;
}

int main()
{
	colaNodo<int> p;
	for (int i{ 1 }; i <= 10; i += 2) {
		p.Push(i);
	}
    p.print();

	colaNodo<int> q;
	for (int j{ 2 }; j <= 10; j += 2) {
		q.Push(j);
	}
    q.print();

	MergeColas(p, q);
	p.print();
    q.print();
}