#ifndef MOBILE_PESANT_H
#define MOBILE_PESANT_H

#include <iostream>
#include "Mobile.h"

class MobilePesant: public Mobile {
  private:
    double masse;

  public:
    MobilePesant(std::string & _nom);
    MobilePesant(std::string & _nom, double _masse);
    MobilePesant(std::string & _nom, Vecteur3D _position, double _masse);
    MobilePesant(std::string _nom, const Vecteur3D & _position, const Vecteur3D & _vitesse, double _masse);
    ~MobilePesant();
    double getMasse()const;
    void setMasse(double _masse);
    void avance(double dt);
    void afficher() const;
    Mobile* copie();
};

#endif
