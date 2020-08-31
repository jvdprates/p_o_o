#include <iostream>
#include "./Point.hpp"

using std::cout;
using std::endl;

int main(){
    Point a(2,3), b(0,1), c, d(3);

    cout << "Inicializando Programa Teste" << endl;

    a.print();
    b.print();
    c.print();
    d.print();

    Point e = b.distTo(c);
    e.print();

    cout << "Finalizando Programa Teste" << endl;
    return 0;
}