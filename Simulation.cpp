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
