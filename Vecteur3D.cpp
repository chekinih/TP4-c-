#include "Vecteur3D.h"

double& Vecteur3D::operator[](int pos) {
    switch(pos){
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
    }
}

Vecteur3D Vecteur3D::operator+(Vecteur3D& v2) {
    return Vecteur3D((*this)[0] + v2[0], (*this)[1] + v2[1], (*this)[2] + v2[2]);
}
