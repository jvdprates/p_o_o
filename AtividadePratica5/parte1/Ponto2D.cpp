#include "Ponto2D.h"
#include <iostream>

using std::cout;
using std::endl;

Ponto2D::Ponto2D(const Ponto2D &that){
    cout << "Construtor de copia (" << that.x << "," << that.y << ")" <<endl;
    this->x = that.x;
    this->y = that.y;
}

void Ponto2D::operator=(const Ponto2D &that){
    cout << "Operador de atribuicao (" << that.x << "," << that.y << ")" <<endl;
    this->x = that.x;
    this->y = that.y;
}

Ponto2D &Ponto2D::operator--()
{
    this->x -= 1;
    this->y -= 1;
    return *this;
};

Ponto2D Ponto2D::operator+(const Ponto2D &that) const
{
    Ponto2D result;
    result.x = this->x + that.x;
    result.y = this->y + that.y;
    return result;
};

void Ponto2D::print(){
    cout << "(" << this->x << "," << this->y << ")" << endl;
}

Ponto2D::~Ponto2D()
{
    delete this;
};
