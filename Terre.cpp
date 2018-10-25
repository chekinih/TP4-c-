#include "Terre.h"

Vecteur3D Terre::gravite(Vecteur3D point) {
    double P = sqrt(pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2));
    return (- GM / pow(P, 3)) * point;
}
