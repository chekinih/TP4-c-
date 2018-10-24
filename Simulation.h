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
  std::list<Mobile*> getCorps() const;
  double getTemps()const;
  void oteCorps(Mobile * _m);
  void ajoutCorps(Mobile * _m);
  void afficherCorps();



  void simuler(double dt);
};

#endif
