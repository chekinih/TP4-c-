#include "Vecteur3D.h"


/*Operateur [] : permet de récuperer les coordonnée d'un vecteur */
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

/*Operateur +:  Permet de faire une addition entre deux vecteurs 3 dimensions */
Vecteur3D Vecteur3D::operator + (Vecteur3D& v2){
  return Vecteur3D(v2[0] + (*this)[0], v2[0] + (*this)[1], v2[0] + (*this)[2]);
}

/*Operateur *:  Permet de faire une multiplication entre un vecteurs 3 dimensions et un double */
Vecteur3D Vecteur3D::operator *(double d){
  return Vecteur3D(d * (*this)[0], d * (*this)[1], d * (*this)[2]);
}

/*Operateur *:  Permet de faire une addition entre un double et un vecteurs 3 dimensions */
 Vecteur3D operator *(double d, Vecteur3D &v){
    return Vecteur3D(d*v[0],d*v[1],d*v[2]);
}

/* Operateur -:  Permet de faire unesoustraction entre deux vecteurs 3 dimensions*/
Vecteur3D Vecteur3D::operator-(Vecteur3D& v2) {
    return Vecteur3D((*this)[0] - v2[0], (*this)[1] - v2[1], (*this)[2] - v2[2]);
}

/*Operateur +=:  Permet de faire une addition et une affectation entre deux vecteurs 3 dimensions*/
Vecteur3D& Vecteur3D::operator+= (Vecteur3D v2) {
    x += v2[0];
    y += v2[1];
    z += v2[2];

    return *this;
}

/*Operateur +:  Permet de faire une soustraction et une affectation entre deux vecteurs 3 dimensions*/
Vecteur3D& Vecteur3D::operator-=(Vecteur3D v2) {
    x -= v2[0];
    y -= v2[1];
    z += v2[2];

    return *this;
}

/*Operateur ==:  Permet de ftester l'égalité entre deux vecteurs 3 dimensions*/
bool Vecteur3D::operator==(Vecteur3D v2) {
    return (RoundTo((*this)[0]) == RoundTo(v2[0])) && (RoundTo((*this)[1]) == RoundTo(v2[1])) && (RoundTo((*this)[2]) == RoundTo(v2[2]));
}

/*Operateur <<:  Permet d 'afficher les coordonnées d 'un vecteurs 3 dimensions*/
std::ostream& operator<<( std::ostream &flux, Vecteur3D v )
{
    flux << "x: " << v[0] << " y: " << v[1] << " z: " << v[2];
    return flux;
}

/*Une méthode qui permet d'arrondir un double à cinq choffre après la virgule*/
double Vecteur3D::RoundTo(double nombre) {
  return (1./100000.) * floor(nombre * 100000.);
}

/*Une méthode qui permet de calculer la distance entre deux points*/
double Vecteur3D::distance(Vecteur3D & v)
{
  return (sqrt(pow(x - v[0], 2) + pow(y - v[1], 2) + pow(z - v[2], 2)));
}
