#include <iostream>
#include "Ponto2D.h"

using std::cout;
using std::endl;

int main()
{

    Ponto2D a(1, 4), b(3, 2), c;

    cout << "Imprimindo a(1,4)" << endl;
    a.print();

    cout << "Imprimindo b(3,2)" << endl;
    b.print();

    cout << "Imprimindo c()" << endl;
    c.print();

    cout << "Imprimindo c = a + b" << endl;
    c = a + b; // soma as coordenadas dos pontos a e b
    c.print();

    cout << "Imprimindo d = --c" << endl;
    Ponto2D d = --c;
    d.print();
    
    cout << "Imprimindo c depois do decremento" << endl;
    c.print();
}