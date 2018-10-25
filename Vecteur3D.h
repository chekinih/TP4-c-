#ifndef VECTEUR3D_H
#define VECTEUR3D_H

class Vecteur3D {
    private:
        double x, y, z;

    public:
        Vecteur3D(): x(0), y(0), z(0)
        {}
        Vecteur3D(double _x, double _y, double _z): x(_x), y(_y), z(_z)
        {}
        double& operator[](int pos);

};

#endif
