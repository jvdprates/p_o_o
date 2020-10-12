#ifndef PONTO_2D
#define PONTO_2D

#include<iostream> 

using std::ostream;
using std:: endl;

class Ponto2D{
    
     public:
        Ponto2D(int xx = 0.0, int yy = 0.0):x(xx),y(yy){ };
        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};
        double get_x(void) const { return x; } 
        double get_y(void) const { return y; }
        void set(double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

#endif

ostream& operator<< (ostream &op, const Ponto2D &p){
            op << endl;
            op << "x = " << p.x << endl;
            op << "y = " << p.y << endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}