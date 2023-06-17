#include <iostream>

using namespace std;

template <class T>
class nodo
{
public:
    T valor;
    nodo* next;
    nodo(T v, nodo* n = nullptr)
    {
        valor = v;
        next = n;
    }
};

template <class T>
class LE
{
    nodo<T>* head = nullptr;

public:
    void print();
    bool find(T v, nodo<T>*& pos);
    void add(T v);
    void del(T v);
    ~LE();
};

template <class T>
void LE<T>::print()
{
    if (!head) {
        cout << "HEAD->HEAD" << endl;
        return;
    }

    cout << "HEAD->";
    nodo<T>* p = head;
    while (p->next != head) {
        cout << p->valor << "->";
        p = p->next;
    }
    cout << p->valor << "->HEAD" << endl;
}

template <class T>
bool LE<T>::find(T v, nodo<T>*& pos)
{
    bool encontrado = false;
    pos = nullptr;

    if (head) {
        nodo<T>* p = head;
        do {
            if (p->valor == v) {
                encontrado = true;
                break;
            }
            pos = p;
            p = p->next;
        } while (p != head);
    }

    return encontrado;
}

template <class T>
void LE<T>::add(T v)
{
    nodo<T>* nuevo_nodo = new nodo<T>(v);
    nodo<T>* pos_ant;
    if (!find(v, pos_ant)) {
        if (!head)
        {
            head = nuevo_nodo;
            head->next = head;
        }
        else if (v < head->valor)
        {
            nodo<T>* ultimo = head;
            while (ultimo->next != head) {
                ultimo = ultimo->next;
            }
            nuevo_nodo->next = head;
            head = nuevo_nodo;
            ultimo->next = head;
        }
        else
        {
            nodo<T>* p = head;
            while (p->next != head && v > p->next->valor)
            {
                p = p->next;
            }
            nuevo_nodo->next = p->next;
            p->next = nuevo_nodo;
        }
    }
}

template <class T>
void LE<T>::del(T v)
{
    nodo<T>* pos_ant, * pos_del;
    if (find(v, pos_ant))
    {
        if (pos_ant)
        {
            pos_del = pos_ant->next;
            pos_ant->next = pos_del->next;
            if (pos_del == head) {
                head = pos_ant->next;
            }
            delete pos_del;
        }
        else
        {
            if (head->next == head) {
                pos_del = head;
                head = nullptr;
                delete pos_del;
            }
            else
            {
                nodo<T>* ultimo = head;
                while (ultimo->next != head) {
                    ultimo = ultimo->next;
                }
                pos_del = head;
                head = head->next;
                ultimo->next = head;
                delete pos_del;
            }
        }
    }
}

template <class T>
LE<T>::~LE()
{
    while (head)
        del(head->valor);
}

int main() {
    LE<int> lista;

    lista.print();
    lista.add(5);
    lista.print();
    lista.add(1);
    lista.print();
    lista.add(3);
    lista.print();
    lista.add(7);
    lista.print();
    lista.add(3);
    lista.print();

    lista.del(3);
    lista.print();
    lista.del(3);
    lista.print();
    lista.del(7);
    lista.print();
    lista.del(1);
    lista.print();
    lista.del(5);
    lista.print();

    cout << "------------------------" << endl;

    LE<char> listaChar;

    listaChar.print();
    listaChar.add('g');
    listaChar.print();
    listaChar.add('a');
    listaChar.print();
    listaChar.add('d');
    listaChar.print();
    listaChar.add('z');
    listaChar.print();
    listaChar.add('d');
    listaChar.print();

    listaChar.del('d');
    listaChar.print();
    listaChar.del('d');
    listaChar.print();
    listaChar.del('z');
    listaChar.print();
    listaChar.del('a');
    listaChar.print();
    listaChar.del('g');
    listaChar.print();

}