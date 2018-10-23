#include "MobilePesant.h"


MobilePesant::MobilePesant(std::string & _nom): Mobile(_nom), masse(0)
{}

MobilePesant::MobilePesant(std::string & _nom, double _masse): Mobile(_nom), masse(_masse)
{}

MobilePesant::MobilePesant(std::string & _nom, Vecteur3D _position, double _masse)
:Mobile(_nom, _position), masse(_masse)
{}

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
  double vx, vy, vz;
  vx = getVitesse().x + dt * 0;
  vy = getVitesse().y + dt * 0;
  vz = getVitesse().z + dt * -9.81;

  Vecteur3D V3D(vx, vy, vz);
  setVitesse(V3D);
}
