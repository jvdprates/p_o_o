#include "Ponto2D.h"
#include <iostream>

using std::cout;
using std::endl;

Ponto2D::Ponto2D(const Ponto2D &that)
{
    cout << "Construtor de copia (" << that.x << "," << that.y << ")" << endl;
    this->x = that.x;
    this->y = that.y;
}

void Ponto2D::operator=(const Ponto2D &that)
{
    cout << "Operador de atribuicao (" << that.x << "," << that.y << ")" << endl;
    this->x = that.x;
    this->y = that.y;
}

Ponto2D Ponto2D::operator--()
{
    Ponto2D aux(this->x, this->y);
    this->x -= 1;
    this->y -= 1;
    return aux;
};

Ponto2D &Ponto2D::operator+(const Ponto2D &that)
{
    cout << "Operador de soma" << endl;
    this->x += that.x;
    this->y += that.y;
    return *this;
};

void Ponto2D::print()
{
    cout << "(" << this->x << "," << this->y << ")" << endl;
}

Ponto2D::~Ponto2D()
{
    delete this;
};
