#include <iostream>
#include "Box.h"

int main(){
    Ponto3D a, b(1, 0.0, 0.0), c(0.0, 2.0, 0.0), d(0.0, 0.0, 1.0);
    Box X, Y(b, a, c, d), Z(1.0, 2.0, 1.0);

    cout << "Caixa X de volume " << X.get_volume() << endl;
    X.printBox();
    

    cout << "Caixa Y de volume " << Y.get_volume() << endl;
    Y.printBox();
    Y.get_volume();

    cout << "Caixa Z de volume " << Z.get_volume() << endl;
    Z.printBox();
    Z.get_volume();
};