#include "Terre.h"

/*Methode permettant de calculer la gravité d'une position donnée*/
Vecteur3D Terre::gravite(Vecteur3D point) {

    double P = sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));
    return point * (- GM / pow(P, 3));
}

Terre::Terre() {

}


Terre::Terre(const Terre &) {
}

Terre::~Terre() {
}

/*guetteur: permettant de récuperer le rayon de la terre */
const double & Terre::getRT() const
{
  return RT;
}

/*Guetteur: permettant de récurerer la constante GM de la terre*/
const double & Terre::getGM() const
{
  return GM;
}
