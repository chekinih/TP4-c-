#ifndef TERRE_H
#define TERRE_H

#include "Vecteur3D.h"

class Terre {
    private:
        const double GM = 3.986* pow(10,14);
        double RT;

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
