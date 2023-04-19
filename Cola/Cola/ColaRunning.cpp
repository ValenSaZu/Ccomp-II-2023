#include <iostream>
#include "Cola.h"

using namespace std;

int main()
{
    Cola A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    A.push(6);
    A.push(7);
    A.push(8);
    A.push(9);
    A.push(10);
    cout << A.pop() << endl;
    A.print();
    A.push(1);
    A.print();
}