#include "Simulation.h"


Simulation::Simulation(): temps(0)
{
}

Simulation::~Simulation()
{
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    if((*it) != NULL)
    {
      std::cout << "Destruction dans simulation:" << std::endl;
      delete (*it);
      (*it) = NULL;
    }
  }
  corps.clear();
}


/*Constructeur par copie*/

Simulation::Simulation(const Simulation & _simulation)
{
  std::list<Mobile *> corps = _simulation.corps;
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    std::cout << "Simulation  par copie dans simulation:" << std::endl;
    this->corps.push_back((*it)->copie());
  }
}

void Simulation::ajoutCorps(Mobile * _m)
{
  corps.push_back(_m);
}

void Simulation::oteCorps(Mobile * _m)
{
  if(!corps.empty())
    corps.remove(_m);
}


void Simulation::afficherCorps()
{
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    (*it)->afficher();
  }
}

std::list<Mobile*> Simulation::getCorps()const
{
  return corps;
}

double Simulation::getTemps()const
{
  return temps;
}

void Simulation::simuler(double dt)
{
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    (*it)->avance(dt);
  }
  temps += dt;
}
