#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <iostream>
#include <cmath>
class Vecteur3D {
    private:
        double x, y, z;

    public:
        Vecteur3D(): x(0), y(0), z(0)
        {}
        Vecteur3D(double _x, double _y, double _z): x(_x), y(_y), z(_z)
        {}
        double& operator[](int pos);
        Vecteur3D operator *(double d);
        friend Vecteur3D operator *(double d, Vecteur3D &v);
        Vecteur3D operator+(Vecteur3D & v2);
        Vecteur3D operator-(Vecteur3D & v2);
        bool operator==(Vecteur3D v2);
        Vecteur3D& operator+=(Vecteur3D v2);
        Vecteur3D& operator-=(Vecteur3D v2);
        friend std::ostream& operator<<( std::ostream &flux, Vecteur3D v);
        double RoundTo(double nombre);
        double distance(Vecteur3D & v);
};

#endif
