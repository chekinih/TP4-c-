#ifndef MOBILE_PESANT_H
#define MOBILE_PESANT_H

#include <iostream>
#include "Mobile.h"
#include "Terre.h"

class MobilePesant: public Mobile {
  private:
    double masse;

  public:
    MobilePesant(const std::string & _nom);
    MobilePesant(const std::string & _nom, double _masse);
    MobilePesant(const std::string & _nom, Vecteur3D _position, double _masse);
    MobilePesant(const std::string & _nom, Vecteur3D _position,Vecteur3D _vitesse ,double _masse);
    ~MobilePesant();
    double getMasse()const;
    void setMasse(double _masse);
    void avance(double dt);
    void afficher();
    Mobile* copie();
};

#endif
