#ifndef SIMULATION_H
#define SIMULATION_H

#include "Mobile.h"
#include <list>

class Simulation {
private:
    double temps;
    std::list<Mobile*> corps;

public:
  Simulation();
  ~Simulation();
  void oteCorps(Mobile * _m);
  void ajoutCorps(Mobile * _m);
  void afficherCorps();

  std::list<Mobile*> getCorps();
  double getTemps();

  void simuler(double dt);
};

#endif
