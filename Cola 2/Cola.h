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
    int* Head = A;
    int* Inicio = A;
    int* Fin = A + 9;
    int* tope = nullptr;
};

void Cola::push(int num)
{
    if (!tope) {
        tope = Inicio;
        *Inicio = num;
        cout << "El dígito " << num << " ya está en la cola" << endl;
    }
    else if (Head < Inicio) {
        if (tope == Fin) {
            if (Inicio > Head) {
                tope = Head;
                *tope = num;
                cout << "El dígito " << num << " ya está en la cola" << endl;
            }
            else {
                cout << "La cola está llena" << endl;
            }
        }
        else {
            if (tope < Inicio) {
                tope++;
                *tope = num;
                cout << "El dígito " << num << " ya está en la cola" << endl;
            }
            else {
                cout << "La cola está llena " << endl;
            }
        }
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
            if (Inicio > Head) {
                tope = Head;
                *tope = num;
                cout << "El dígito " << num << " ya está en la cola" << endl;
            }
            else {
                cout << "Cola llena :( 5" << endl;
            }
        }
    }
}

int Cola::pop()
{
    if (tope == nullptr) {
        cout << "Cola vacía :( no se puede hacer pop" << endl;
        return 0;
    }
    int tmp = *Inicio;
    *Inicio = 0;
    if (Inicio == Fin && tope==Fin) {
        Inicio = Head;
        tope = nullptr;
        return tmp;
    }
    if (Inicio == Fin && tope < Inicio) {
        Inicio = Head;
        return tmp;
    }
    else {
        Inicio++;
    }
    return tmp;
}

void Cola::print() {
    int count{ 0 };
    for (int* i = Inicio; i <= Fin; i++) {
        count += *i;
    }
    if (tope == nullptr || count==0) {
        cout << "Cola vacía :(" << endl;
    }
    else {
        /*if (Inicio == Head) {
            for (int* i = Head; i <= Fin; i++) {
                cout << *i << " ";
            }
            cout << endl;
        }if (Inicio > Head) {
            for (int* i = Inicio; i <= Fin; i++) {
                cout << *i << " ";
            }
            for (int* i = Head; i < Inicio; i++) {
                cout << *i << " ";
            }
        }
        */
        for (int* i = Head; i <= Fin; i++) {
            cout << *i << " ";
        }
    }
    cout << endl;
}