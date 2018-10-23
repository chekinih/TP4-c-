#ifndef VECTEUR3D_H
#define VECTEUR3D_H

class Vecteur3D {
    public:
        double x, y, z;

    Vecteur3D(): x(0), y(0), z(0)
    {}
    Vecteur3D(double _x, double _y, double _z): x(_x), y(_y), z(_z)
    {}

};

#endif
