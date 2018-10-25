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

Vecteur3D Vecteur3D::operator + (Vecteur3D& v2){
  return Vecteur3D(v2[0]+(*this)[0],v2[0]+(*this)[1],v2[0]+(*this)[2]);
}
Vecteur3D Vecteur3D::operator *(double d){
  return Vecteur3D(d*(*this)[0],d*(*this)[1],d*(*this)[2]);
}

bool Vecteur3D::operator == (Vecteur3D& v)
{
return ((*this)[0] == v[0] )&& ((*this)[1] == v[1]) && ((*this)[2] == v[2]);
}
//Vecteur3D Vecteur3D::operator<<(Vecteur3D& v2) {

//}
