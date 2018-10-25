#include "MobilePesant.h"


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
double MobilePesant::getMasse()const{
  return masse;
}
void MobilePesant::setMasse(double _masse){
  masse = _masse;
}

 void MobilePesant::avance(double dt){
  Mobile::avance(dt);
  std::cout << "méthode avance de MobilePesant"<<std::endl;
  double vx, vy, vz;
  vx = getVitesse()[0] + dt * 0;
  vy = getVitesse()[1] + dt * 0;
  vz = getVitesse()[2] + dt * -9.81;

  Vecteur3D V3D(vx, vy, vz);
  setVitesse(V3D);
}

Mobile * MobilePesant::copie() {
    return new MobilePesant(nom, position, vitesse, masse);
}

void MobilePesant::afficher(){
  Mobile::afficher();
  std::cout << "Masse x = " << masse << std::endl << std::endl;

}
