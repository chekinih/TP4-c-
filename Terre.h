#ifndef TERRE_H
#define TERRE_H

#include "Vecteur3D.h"

#include <cmath>
class Terre {
    private:
        const double GM = 3.986 * pow(10, 14);
        const double RT = 6378000;

    public:
        Vecteur3D gravite(Vecteur3D);
        static Terre& getInstance() {
            static Terre obj;
            return obj;
        }

    private:
        Terre();
        Terre(const Terre&);
        Terre& operator=( const Terre&);
        ~Terre();
};
#endif
