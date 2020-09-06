#include <iostream>
#include "Matrix.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    Matrix a(2,3,4.5), b(1,2,2.67), c(10,10,3), d(3,3);
    Matrix e = a;
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    return 0;
}