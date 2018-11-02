#include "Terre.h"

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
