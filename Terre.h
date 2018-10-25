#ifndef TERRE_H
#define TERRE_H

#include "Vecteur3D.h"

class Terre {
    private:
        double GM;
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
