#ifndef PONTO_3D
#define PONTO_3D

#include "Ponto2D.h"

class Ponto3D : public Ponto2D
{
public:
    Ponto3D(double xx = 0, double yy = 0, double zz = 0);
    friend ostream &operator<<(ostream &op, const Ponto3D &p);
    Ponto3D &operator=(const Ponto2D &p);
    void set(double nx = 0, double ny = 0, double nz = 0);
    double get_z();

private:
    double z;
};

#endif

Ponto3D::Ponto3D(double xx, double yy, double zz) : z(zz){
    this->set(xx,yy);
};

Ponto3D &Ponto3D::operator=(const Ponto2D &p)
{
    this->set(p.get_x(), p.get_y(), 0.0);
    return *this;
};

ostream &operator<<(ostream &op, const Ponto3D &p){
    op << "[" << p.get_x() << "," << p.get_y() << "," << p.get_y() << "]" << endl;
    return op;
};

void Ponto3D::set(double nx, double ny, double nz)
{
    this->z = nz;
    this->set(nx, ny);
};

double Ponto3D::get_z(){return this->z;};
