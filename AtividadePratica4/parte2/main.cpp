#include <iostream>
#include "Matrix.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    Matrix a, b(1,1,1), c(2,2,2), d(3,3,3);
    Matrix e = a;
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();
    return 0;
}