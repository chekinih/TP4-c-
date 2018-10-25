#include "Vecteur3D.h"
#include <iostream>


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

Vecteur3D Vecteur3D::operator + (Vecteur3D& v2){
  return Vecteur3D(v2[0]+(*this)[0],v2[0]+(*this)[1],v2[0]+(*this)[2]);
}
Vecteur3D Vecteur3D::operator *(double d){
  return Vecteur3D(d*(*this)[0],d*(*this)[1],d*(*this)[2]);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D& v2) {
    return Vecteur3D((*this)[0] - v2[0], (*this)[1] - v2[1], (*this)[2] - v2[2]);
}

Vecteur3D& Vecteur3D::operator+=(Vecteur3D v2) {
    x += v2[0];
    y += v2[1];
    z += v2[2];

    return *this;
}

Vecteur3D& Vecteur3D::operator-=(Vecteur3D v2) {
    x -= v2[0];
    y -= v2[1];
    z += v2[2];

    return *this;
}

bool Vecteur3D::operator==(Vecteur3D v2) {
    return ((*this)[0] == v2[0]) && ((*this)[1] == v2[1]) && ((*this)[2] == v2[2]);
}

std::ostream& operator<<( std::ostream &flux, Vecteur3D v )
{
    flux << "x: " << v[0] << " y: " << v[1] << " z: " << v[2];
    return flux;
}
