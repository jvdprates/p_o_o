#ifndef PONTO_3D
#define PONTO_3D

#include "Ponto2D.h"

class Ponto3D : public Ponto2D
{
public:
    Ponto3D(double xx = 0.0, double yy = 0.0, double zz = 0.0);
    friend ostream &operator<<(ostream &op, const Ponto3D &p);
    Ponto3D &operator=(const Ponto2D &p);
    void set3D(double nx = 0, double ny = 0, double nz = 0);
    double get_z(void) const {return this->z;};

private:
    double z;
};

#endif

Ponto3D::Ponto3D(double xx, double yy, double zz)
{
    this->set2D(xx, yy);
    this->z = zz;
};

void Ponto3D::set3D(double nx, double ny, double nz)
{
    this->z = nz;
    this->set2D(nx, ny);
};

Ponto3D &Ponto3D::operator=(const Ponto2D &p)
{
    this->set3D(p.get_x(), p.get_y(), 0.0);
    return *this;
};

ostream &operator<<(ostream &op, const Ponto3D &p)
{
    op << endl;
    op << "x = " << p.get_x() << endl;
    op << "y = " << p.get_y() << endl;
    op << "z = " << p.get_z() << endl;
    return op;
};



