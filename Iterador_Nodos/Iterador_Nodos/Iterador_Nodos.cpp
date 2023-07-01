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
class Iterator
{
public:
    nodo<T>* it;

    Iterator(nodo<T>* node = nullptr) : it(node) {}

    void operator=(nodo<T>* valor)
    {
        it = valor;
    }

    void operator=(T valor)
    {
        it->valor = valor;
    }

    Iterator<T>& operator++()
    {
        it = it->next;
        return *this;
    }

    Iterator<T> operator++(int)
    {
        Iterator<T> old = *this;
        it = it->next;
        return old;
    }

    T& operator*()
    {
        return it->valor;
    }

    bool operator!=(const Iterator<T>& otro) const
    {
        return it != otro.it;
    }

    friend istream& operator>>(istream& input, Iterator<T>& D)
    {
        input >> *(D.it);
        return input;
    }
};

template <class T, class I>
class LE
{
public:
    nodo<T>* head = nullptr;
    nodo<T>* tail = nullptr;
    typedef I it_vector;
    bool find(T v, nodo<T>*& pos);
    void add(T v);
    void del(T v);
    Iterator<T> begin();
    Iterator<T> end();
    void print();
    ~LE();
};

template <class T, class I>
bool LE<T, I>::find(T v, nodo<T>*& pos)
{
    bool encontrado = false;
    pos = nullptr;

    Iterator<T> It = begin();
    for (; It != end(); It++)
    {
        if (*It == v)
        {
            encontrado = true;
            break;
        }
        pos = It.it;
    }
    return encontrado;
}

template <class T, class I>
void LE<T, I>::add(T v)
{
    if (!head)
    {
        head = new nodo<T>(v, nullptr);
        tail = head;
    }
    else
    {
        tail->next = new nodo<T>(v, nullptr);
        tail = tail->next;
    }
}

template <class T, class I>
void LE<T, I>::del(T v)
{
    nodo<T>* pos_ant, * pos_del;
    if (find(v, pos_ant))
    {
        if (pos_ant)
        {
            pos_del = pos_ant->next;
            pos_ant->next = pos_del->next;
            if (pos_del == tail)
                tail = pos_ant;
            delete pos_del;
        }
        else
        {
            pos_del = head;
            head = pos_del->next;
            if (pos_del == tail)
                tail = nullptr;
            delete pos_del;
        }
    }
}

template <class T, class I>
Iterator<T> LE<T, I>::begin()
{
    return Iterator<T>(head);
}

template <class T, class I>
Iterator<T> LE<T, I>::end()
{
    return Iterator<T>(nullptr);
}

template <class T, class I>
void LE<T, I>::print()
{
    cout << "Head->";
    for (Iterator<T> It = begin(); It != end(); It++)
    {
        cout << *It << "->";
    }
    cout << "NULL" << endl;
}

template <class T, class I>
LE<T, I>::~LE()
{
    while (head)
        del(head->valor);
}

int main()
{
    LE<int, Iterator<int>> Ent;

    for (int x = 100; x <= 1000; x += 100)
    {
        Ent.add(x);
    }
    Ent.print();

    cout << "-----------------" << endl;

    cout << "Ingrese números para agregar a la lista (ingrese 0 para finalizar):" << endl;
    int num;
    while (cin >> num && num != 0)
    {
        Ent.add(num);
    }
    Ent.print();

    return 0;
}
