#include "MobilePesant.h"

/* Constructeurs:
Permettant d initialiser un mobile pesant*/
MobilePesant::MobilePesant(const std::string & _nom): Mobile(_nom), masse(0)
{}

MobilePesant::MobilePesant(const std::string & _nom, double _masse): Mobile(_nom), masse(_masse)
{}

MobilePesant::MobilePesant(const std::string & _nom, Vecteur3D _position, double _masse)
:Mobile(_nom, _position), masse(_masse)
{}

MobilePesant::MobilePesant(const std::string & _nom, Vecteur3D _position,Vecteur3D _vitesse ,double _masse)
:Mobile(_nom, _position, _vitesse), masse(_masse)
{

}

MobilePesant::~MobilePesant()
{
  std::cout << "Destruction du mobile pesant" << std::endl;
}

/*Guetteur: une méthode qui renvoie la masse d'un mobile pesant*/
double MobilePesant::getMasse()const{
  return masse;
}

/*Setteur: une méthode qui modifie la masse d'un mobile pesant*/
void MobilePesant::setMasse(double _masse){
  masse = _masse;
}

/*Cette méthode fait avancer un mobile pesant.*/

 void MobilePesant::avance(double dt){

   /*faire appel à la méthode avance() de la super classe pour
   pouvoir mettre à jour sa position*/

  Mobile::avance(dt);
  std::cout << "méthode avance de MobilePesant"<<std::endl;
  //Vecteur3D v (0,0,-9.81);
  Vecteur3D v ;
  v = Terre::getInstance().gravite(getPosition());
  /*Mettre à jour la vitesse du mobile*/

  for(int i = 0; i<3; i++)
  {
    v[i] =  getVitesse()[i] + v[i]* dt;
  }

  setVitesse(v);
}

/*Cette methode permet de faire une copie du mobile appelant en renvoyant
un nouveau mobile avec les memes attributs que le mobile appelant*/

Mobile * MobilePesant::copie() {
  std::cout << "méthode copie de MobilePesant" << std::endl;
    return new MobilePesant(nom, position, vitesse, masse);
}

/* Cette methode permet d afficher les caracteristique d'un obile pesant*/
void MobilePesant::afficher(){
  Mobile::afficher();
  std::cout << "Masse x = " << masse << std::endl << std::endl;

}
