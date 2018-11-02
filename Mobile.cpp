#include "Mobile.h"

/*Constructeurs:
Permettant d'initialiser un mobile*/
Mobile::Mobile(const std::string & _nom): nom(_nom)
{}

Mobile::Mobile(const std::string _nom, const Vecteur3D & _position):nom(_nom), position(_position) {

}
Mobile::Mobile(const std::string _nom, const Vecteur3D & _position, const Vecteur3D & _vitesse)
: nom(_nom), position(_position), vitesse(_vitesse)
{}

/*Guetteur: Cette methode renvoie le nom du mobile appelant*/
const std::string & Mobile::getNom() const {
  return nom;
}

/*Setteur: Cette methode modifie le nom du mobile appelant*/
void Mobile::setNom(const std::string & _nom) {
  nom = _nom;
}
/*Guetteur: cette methode renvoie le vecteur position du mobile*/
Vecteur3D & Mobile::getPosition() {
  return position;
}

/*Setteur: Cette methode modifie la position du mobile appelant*/
void Mobile::setPosition(const Vecteur3D & _position) {
  position = _position;
}

/*Guetteur: cette methode renvoie le vecteur vitesse du mobile*/
Vecteur3D & Mobile::getVitesse() {
  return vitesse;
}

/*Setteur: Cette methode modifie la vitesse du mobile appelant*/
void Mobile::setVitesse(const Vecteur3D & _vitesse) {
  vitesse = _vitesse;
}

/*Cette methode affiche les caracteristiques d'un mobile*/
void Mobile::afficher() {
  std::cout << "Mobile" << std::endl;
  std::cout << "Nom: " << nom << std::endl;
  std::cout << "Position x = " << position[0] << " y = " << position[1] << " z = " << position[2] << std::endl;
  std::cout << "Vitesse x = " << vitesse[0] << " y = " << vitesse[1] << " z = " << vitesse[2] << std::endl << std::endl;
}

/*Cette methode permet de faire avancer le mobile appelant*/
 void Mobile::avance(double dt) {
  std::cout << "méthode avance de Mobile" <<std::endl;
  int i;
  for(i=0; i< 3; i++)
  {
    position[i] = position[i] + vitesse[i]*dt;
  }

}

/*Destructeur*/
Mobile::~Mobile() {

  std::cout << "Destuction du mobile " << nom << std::endl << std::endl;
}

/*Cette methode permet de faire une copie du mobile appelant en renvoyant
un nouveau mobile avec les memes attributs que le mobile appelant*/
Mobile* Mobile::copie() {
  std::cout << "méthode copie de Mobile" << std::endl;
    return new Mobile(nom, position, vitesse);
}
