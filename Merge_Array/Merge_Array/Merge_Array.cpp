#include <iostream>

using namespace std;

void merge(int A[]) {
    int* p = A;
    //Colocamos q en la mitad del array (los impares)
    int* q = A;
    while (*q % 2 == 0) {
        q++;
    }
    int* c = A;
    int size = (q - p) * 2;
    int* s = A + (size - 1);
    //comenzamos el intercambio
    for (; q <= s; q++) {
        c = p;
        for (; c < q; c++) {
            if (*q<*c) {
                int temp = *c;
                *c = *q;
                *q = temp;;
            }
        }
    }
    //imprimimos
    for (; p <= s; p++) {
        cout << *p << " ";
    }
}
int main()
{
    int A[10] = { 4,6,10,22,34,1,3,11,21,23 };
    merge(A);
}
