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
                Inicio--;
                *Inicio = num;
                tope = Inicio;
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
                cout << "La cola está llena" << endl;
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
                Inicio--;
                *Inicio = num;
                tope = Inicio;
                cout << "El dígito " << num << " ya está en la cola" << endl;
            }
            else {
                cout << "Cola llena :(" << endl;
            }
        }
    }
}

int Cola::pop()
{
    if (tope == nullptr) {
        cout << "Cola vacía :(" << endl;
        return 0;
    }
    int tmp = *Inicio;
    *Inicio = 0;
    if (Inicio == Fin) {
        Inicio = Head;
        tope = nullptr;
    }
    else {
        Inicio++;
    }
    return tmp;
}

void Cola::print() {
    if (tope == nullptr) {
        cout << "Cola vacía :(" << endl;
        return;
    }
    else {
        for (int* i = Head; i <= Fin; i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
    cout << endl;
}