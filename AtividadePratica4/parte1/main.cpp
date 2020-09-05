#include <iostream>
#include "Point.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(){
    Point p1(5,3), p2(4,3), p3(6,4);
    Point p4 = p1;
    Point p5(p2);
    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    return 0;
}