#include <iostream>
#include "Matrix.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    Matrix a, b(2,3,1), c(2,2,2), d(3,3,3);
    Matrix e = b;
    b.print();
    b.ones();
    b.print();
    b.zeros();
    b.print();
    b.unit();
    b.print();
    return 0;
}