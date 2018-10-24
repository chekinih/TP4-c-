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
const Vecteur3D & Mobile::getPosition() const {
  return position;
}
void Mobile::setPosition(const Vecteur3D & _position) {
  position = _position;
}
const Vecteur3D & Mobile::getVitesse() const {
  return vitesse;
}
void Mobile::setVitesse(const Vecteur3D & _vitesse) {
  vitesse = _vitesse;
}
void Mobile::afficher() const {
  std::cout << "Mobile" << std::endl;
  std::cout << "Nom: " << nom << std::endl;
  std::cout << "Posiition x = " << position.x << " y = " << position.y << " z = " << position.z << std::endl;
  std::cout << "Vitesse x = " << vitesse.x << " y = " << vitesse.y << " z = " << vitesse.z << std::endl << std::endl;
}


 void Mobile::avance(double dt) {
  std::cout << "méthode avance de Mobile" <<std::endl;
  position.x = position.x + dt * vitesse.x;
  position.y = position.y + dt * vitesse.y;
  position.z = position.z + dt * vitesse.z;

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
