#include <iostream>
#include "./Point.hpp"

using std::cout;
using std::endl;
using std::cin;

const void printDistToOrig(Point A) {
    double dist = A.distToOrig();
    cout << "A distancia do ponto [" << A.getIndex() << "] para a Origem e: " << dist << endl;
}

const void printDist(Point A, Point B) {
    double dist = A.distTo(B);
    cout << "A distancia do ponto [" << A.getIndex() << "] para o ponto [" << B.getIndex() << "]  e: " << dist << endl;
}

int main(){
    cout << "Inicializando Programa Teste" << endl;

    double inX, inY;
    cout << "Digite dois valores que representarao um ponto em um plano 2D:" << endl;
    cout << "X = ";
    cin >> inX;
    cout << "Y = ";
    cin >> inY;

    Point p1(inX, inY);

    p1.print();

    cout << "Digite dois valores que representarao um segundo ponto em um plano 2D:" << endl;
    cout << "X = ";
    cin >> inX;
    cout << "Y = ";
    cin >> inY;

    Point p2(inX, inY);
    const Point p3(0,1);
    const Point p4(1);

    cout << "Considerando os seguintes pontos: " << endl;
    p2.print();
    p3.print();
    p4.print();

    printDistToOrig(p1);
    printDistToOrig(p2);
    printDist(p1,p2);
    
    const Point p5 = p1.sumOf(p2);
    cout << "A soma dos valores de X e Y dos pontos [" << p1.getIndex() << "] e [" << p2.getIndex() << "] e: " << endl;
    p5.print();

    cout << "Finalizando Programa Teste" << endl;
    return 0;
}