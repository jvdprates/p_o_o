#include "tempo.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Tempo t, t1(72), t2(90, 3), t3(4, 7, 55), t4(45, 30, 56, 65);

    cout << "t: " << endl;
    t.print();

    cout << endl
         << "t1: " << endl;
    t1.print();

    cout << endl
         << "t2: " << endl;
    t2.print();

    cout << endl
         << "t3: " << endl;
    t3.print();

    cout << endl
         << "t4: " << endl;
    t4.print();

    cout << endl
         << "t3 + t4 " << endl;
    Tempo r = t3.sum(t4);
    r.print();

    cout << endl
         << "Incrementando t1 em 10 segundos: " << endl;
    t1.increment(10, false);
    t1.print();

    cout << endl
         << "removendo 20 segundos de t1: " << endl;
    t1.increment(20, true);
    t1.print();

    return 0;
}