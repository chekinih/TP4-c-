#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
#include <string>
#include "Vecteur3D.h"

class Mobile {

  protected:
    std::string nom;
    Vecteur3D position;
    Vecteur3D vitesse;

  public:
    // Mobile();
    Mobile(const std::string & _nom);
    Mobile(const std::string _nom, const Vecteur3D & _position);
    Mobile(const std::string _nom, const Vecteur3D & _position, const Vecteur3D & _vitesse);
    const std::string & getNom() const;
    void setNom(const std::string &);
    const Vecteur3D & getPosition() const;
    void setPosition(const Vecteur3D &);
    const Vecteur3D & getVitesse() const;
    void setVitesse(const Vecteur3D &);
    virtual void afficher();
    virtual void avance(double dt);
    virtual Mobile* copie();

  public:
    virtual ~Mobile();
};

#endif
