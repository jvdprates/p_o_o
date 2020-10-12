#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "Ponto3D.h"
#include <cmath>

class Box
{
public:
    Box();
    Box(double largura, double altura, double comprimento);
    Box(Ponto3D ponto_1, Ponto3D ponto_2, Ponto3D ponto_3, Ponto3D ponto_4);
    double get_volume() const;
    double get_area() const;
    double get_altura()const {return this->altura;};
    double get_largura()const {return this->largura;};
    double get_comprimento()const {return this->comprimento;};
    void printBox() const;
private:
    double largura, altura, comprimento;
};

Box::Box(): largura(0.0), altura(0.0), comprimento(0.0){}

Box::Box(double largura, double altura, double comprimento){
    this->largura = largura;
    this->altura = altura;
    this->comprimento = comprimento;
};

double distTo(Ponto3D ponto_1, Ponto3D ponto_2){
    return sqrt(
        (pow(ponto_1.get_x(), 2.0) + pow(ponto_2.get_x(), 2.0)) + 
        (pow(ponto_1.get_y(), 2.0) + pow(ponto_2.get_y(), 2.0)) +
        (pow(ponto_1.get_z(), 2.0) + pow(ponto_2.get_z(), 2.0))
    );
};

Box::Box(Ponto3D ponto_1, Ponto3D ponto_2, Ponto3D ponto_3, Ponto3D ponto_4){
    this->largura = distTo(ponto_1, ponto_2);
    this->comprimento = distTo(ponto_2, ponto_3);
    this->altura = distTo(ponto_2, ponto_4);
};

double Box::get_volume() const{
    return this->largura * this->altura * this->comprimento;
};

double Box::get_area() const{
    return (
       2 * (this->largura * this->comprimento)
       + 2 * (this->comprimento * this->altura)
       + 2 * (this->largura * this->altura)
    );
};

void Box::printBox() const{
    cout << "Largura = " << this->largura 
        << ", Comprimento = " << this->comprimento 
        << ", Altura = " << this->altura 
        << endl;
}

#endif
