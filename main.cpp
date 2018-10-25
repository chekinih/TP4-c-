#include <iostream>
#include "Mobile.h"
#include "Tests.h"
#include "Simulation.h"
#include "Vecteur3D.h"

int main()
{
    if(Tests::testMobile1()) {
      std::cout << "Le test testMobile1 a reussie" << std::endl;
    }
    else {
      std::cout << "Le test testMobile1 n'a pas reussie" << std::endl;
    }

    //Tests::testSimulation2();
    //Tests::testSimulation4();

    return 0;
}
