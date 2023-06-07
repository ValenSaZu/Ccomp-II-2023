#include <iostream>
#include "ColaNodos.h"

void MergeColas(colaNodo<int>& p, colaNodo<int>& q) {
    nodo<int>* a = p.HEAD;
    nodo<int>* b = q.HEAD;
    nodo<int>* tmpA = nullptr;
    nodo<int>* tmpB = nullptr;
    while (a && b) {
        if (b == q.HEAD) {
            q.HEAD = p.HEAD;
        }
        tmpA = a->next;
        tmpB = b->next;
        a->next = b;
        b->next = tmpA;
        a = tmpA;
        b = tmpB;
    }
    delete a;
    delete b;
    delete tmpA;
    delete tmpB;
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