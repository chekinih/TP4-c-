#include "Mobile.h"

Mobile::Mobile(const std::string & _nom): nom(_nom)
{}

Mobile::Mobile(const std::string _nom, const Vecteur3D & _position):nom(_nom), position(_position) {

}
Mobile::Mobile(const std::string _nom, const Vecteur3D & _position, const Vecteur3D & _vitesse)
: nom(_nom), position(_position), vitesse(_vitesse)
{}

const std::string & Mobile::getNom() const {
  return nom;
}
void Mobile::setNom(const std::string & _nom) {
  nom = _nom;
}
Vecteur3D & Mobile::getPosition() {
  return position;
}
void Mobile::setPosition(const Vecteur3D & _position) {
  position = _position;
}
Vecteur3D & Mobile::getVitesse() {
  return vitesse;
}
void Mobile::setVitesse(const Vecteur3D & _vitesse) {
  vitesse = _vitesse;
}
void Mobile::afficher() {
  std::cout << "Mobile" << std::endl;
  std::cout << "Nom: " << nom << std::endl;
  std::cout << "Position x = " << position[0] << " y = " << position[1] << " z = " << position[2] << std::endl;
  std::cout << "Vitesse x = " << vitesse[0] << " y = " << vitesse[1] << " z = " << vitesse[2] << std::endl << std::endl;
}


 void Mobile::avance(double dt) {
  std::cout << "méthode avance de Mobile" <<std::endl;
  position[0] = position[0] + dt * vitesse[0];
  position[1] = position[1] + dt * vitesse[1];
  position[2] = position[2] + dt * vitesse[2];

  //return position;
}

Mobile::~Mobile() {
  // if(position != NULL) {
  //   delete position;
  //   // position = NULL;
  // }
  // if(vitesse !=  NULL){
  //   delete vitesse;
  //   // vitesse = NULL;
  // }
  std::cout << "Destuction du mobile " << nom << std::endl << std::endl;
}


Mobile* Mobile::copie() {
    return new Mobile(nom, position, vitesse);
}
