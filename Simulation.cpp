#include "Simulation.h"

/*constructeur qui initialise le temps a 0*/
Simulation::Simulation(): temps(0)
{
}

/*Un destructeur qui détruit tous les mobiles contenus dans la liste de mobile,
 détruit la liste par la suite*/
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

    /*copie et ajout des mobiles*/
    this->corps.push_back((*it)->copie());
  }
}

/*un méthode qui permet d'ajouter un mobile dans une liste de mobiles  */
void Simulation::ajoutCorps(Mobile * _m)
{
  if(_m != NULL)
  corps.push_back(_m);
}

/*une méthode qui permet de supprimer un mobile dans une liste de mobile d'une simulation*/
void Simulation::oteCorps(Mobile * _m)
{
  if(!corps.empty())
    corps.remove(_m);
}

/*Cette méthode affiche tous les mobiles d'une simulation*/
void Simulation::afficherCorps()
{
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    (*it)->afficher();
  }
}

/*cette méthode renvoie la liste des mobiles d une simulation*/
std::list<Mobile*> Simulation::getCorps()const
{
  return corps;
}

/*getteur: méthode permettant de renvoyer le temps d'une simulation*/
double Simulation::getTemps()const
{
  return temps;
}


void Simulation::setTemps(double dt)
{
  temps = dt;
}
/* Cette méthode parcourt tous les mobiles d'une simultaion et les fait avancer
par un temps passé en paramère en faisant appel a la méthode avance, incrémente le temps */
void Simulation::simuler(double dt)
{
  for(std::list<Mobile *>::iterator it = corps.begin(); it != corps.end(); it++)
  {
    (*it)->avance(dt);
  }
  temps += dt;
}
