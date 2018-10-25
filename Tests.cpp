#include "Tests.h"
#include <string>
#include <cmath>
#include <iostream>
#include "Simulation.h"

bool Tests::testMobile1()
{
  //Initialisation
  // Mobile 1 à la position 0 et avec une vitesse v1(2, 2, 2)
  Vecteur3D v1(2, 2, 2);
  Mobile m1("M1");
  m1.setVitesse(v1);

  Vecteur3D expected(4, 4, 4);
  //Fonction
   m1.avance(2);
  //Assertion
  return m1.getPosition() == expected;

}

bool Tests::testSimulation1()
{

  // Initialisation
  Simulation s;

  Mobile* m1 = new Mobile("M1");
  Vecteur3D v1(3,3,3);
  m1->setVitesse(v1);

  Vecteur3D p2(2,2,2);
  Vecteur3D v2(1,1,1);
  Mobile* m2 = new Mobile("M2", p2, v2);

  s.ajoutCorps(m1);
  s.ajoutCorps(m2);

  // s->afficherCorps();
  s.simuler(2);
  // s->afficherCorps();
  Vecteur3D positionEspereM1(6,6,6);
  Vecteur3D positionEspereM2(4,4,4);

  return (m1->getPosition() == positionEspereM1 && m2->getPosition() == positionEspereM2);

}

bool Tests::testSimulation2()
{

  // Initialisation
  Simulation* s = new Simulation();

  Mobile* m1 = new Mobile("M1");
  Vecteur3D v1(3,3,3);
  m1->setVitesse(v1);

  Vecteur3D p2(2,2,2);
  Vecteur3D v2(1,1,1);
  Mobile* m2 = new Mobile("M2", p2, v2);

  s->ajoutCorps(m1);
  s->ajoutCorps(m2);

  delete s;


  std::cout << "X de m2: " << m2->getPosition()[0] << std::endl << std::endl;
  return true;
}

bool Tests::testMobile2() {
  //ecteur3D h; //z represente l'altitude

  double h = 10.0;
  double temps = 0;
  double dt = 0.01;
  double expectedTime;
  expectedTime = sqrt((2 * h)/9.81);

  Vecteur3D vitesse(0, 0, 0);
  Vecteur3D position(0,0, h);
  std::string nom  = "mobilePesant";
  Mobile * mobilePesant = new MobilePesant(nom, position, 200.0);

  mobilePesant->setVitesse(vitesse);

  while (h > 0) {
    //std::cout << "Z: " << mobilePesant->getPosition()[2]<< std::endl;
    mobilePesant->avance(dt);
    h = mobilePesant->getPosition()[2];
    temps += dt;
  }
  std::cout << "temps: " << temps << std::endl;
  std::cout << "Time expected: "<< expectedTime << std::endl;

  delete mobilePesant;

  if((temps <= expectedTime + 0.1) && (temps >= expectedTime - 0.1))
  {
    /*Si l'erreur est de 1O puissance -1*/
    std::cout << "Le mobile pesant a mis environ " << expectedTime <<"pour atteindre le sol"<< std::endl;
    return true;
  }else{
    return false;
  }
}

bool Tests::testSimulation3()
{
  Simulation s;
  std::string ordinaire =" MobileOrdianre";
  std::string pesant =" MobilePesant";

  Vecteur3D vitesseO(1, 1, 1);
  Vecteur3D positionO(4,4, 0);
  Vecteur3D vitesseP(1, 1, 1);
  Vecteur3D positionP(3,3, 0);

  Mobile *mobileOrdinaire = new Mobile(ordinaire, positionO, vitesseO);
  Mobile *mobilePesant = new MobilePesant(pesant, positionP,vitesseP,200.0);
  s.ajoutCorps(mobileOrdinaire);
  s.ajoutCorps(mobilePesant);
  //s.afficherCorps();

  Vecteur3D expected_Pos_Ordinaire(12,12,8);
  Vecteur3D expected_Vit_Ordinaire(1, 1, 1); // la vitesse d'mobile ordinaire reste inchangée

  Vecteur3D expected_Pos_Pesant(11,11, -227.44);
  Vecteur3D expected_Vit_Pesant(1, 1, -77.48);

  while(s.getTemps() < 8)
  {
    s.simuler(2);
  }
  s.afficherCorps();


return (mobileOrdinaire->getPosition() == expected_Pos_Ordinaire && mobileOrdinaire->getVitesse() == expected_Vit_Ordinaire
        &&
        mobilePesant->getPosition() == expected_Pos_Pesant && mobilePesant->getVitesse() == expected_Vit_Pesant);
}



/*bool Tests::testMobile2(){

  std::string nom = "mobilePesant";
  Vecteur3D vPos(23,54,87);
  Mobile* mobilePesant = new MobilePesant(nom,vPos, 200);

  for(int i=0; i<4; i++)
  {
    mobilePesant->avance(2);
  }


    std::cout << "Mobile pesant M1 : " << std::endl;
    std::cout << "Position: mobilePesant[0] =  : " << mobilePesant->getPosition()[0] << std::endl;
    std::cout << "Position: mobilePesant[1] =  : " << mobilePesant->getPosition()[1] << std::endl;
    std::cout << "Position:mobilePesant[2] =  : " << mobilePesant->getPosition()[2] << std::endl;


    std::cout << "Vitesse: mobilePesant[0] =  : " << mobilePesant->getVitesse()[0] << std::endl;
    std::cout << "Vitesse: mobilePesant[1] =  : " << mobilePesant->getVitesse()[1] << std::endl;
    std::cout << "Vitesse: mobilePesant[2] =  : " << mobilePesant->getVitesse()[2] << std::endl;
  delete mobilePesant;


  Mobile* m1;
  std::string s ="m1";
  m1= new MobilePesant(s);
  Vecteur3D v1(3,3,3);
  m1->setVitesse(v1);

  Vecteur3D expectedP1(6, 6, 6);

  m1->avance(2);

  std::cout << "Mobile pesant M1 : " << std::endl;
  std::cout << "Position: M1[0] =  : " << m1->getPosition()[0] << std::endl;
  std::cout << "Position: M1[1] =  : " << m1->getPosition()[1] << std::endl;
  std::cout << "Position: M1[2] =  : " << m1->getPosition()[2] << std::endl;

  Vecteur3D expectedV1(3, 3, -16.62);

  std::cout << "Vitesse: M1[0] =  : " << m1->getVitesse()[0] << std::endl;
  std::cout << "Vitesse: M1[1] =  : " << m1->getVitesse()[1] << std::endl;
  std::cout << "Vitesse: M1[2] =  : " << m1->getVitesse()[2] << std::endl;

  if((m1->getPosition()[0] == expectedP1[0]) && (m1->getPosition()[1]== expectedP1[1]) && (m1->getPosition()[2]== expectedP1[2])
      && (m1->getVitesse()[0] == expectedV1[0]) && (m1->getVitesse()[1]== expectedV1[1]) && (m1->getVitesse()[2]== expectedV1[2]) )
  {
    std::cout << "Le test Mobile2 réussit" << std::endl;
    return true;
  }else{
    return false;
  }
   delete m1;


/*
  Vecteur3D p2(2,2,2);
  Vecteur3D v2(1,1,1);
  Mobile* m2 = new MobilePesant("M2", p2, v2);
  Vecteur3D expectedV2(4, 4, 4);

  Vecteur3D avance2 = m2->avance(2);

  std::cout << "Mobile pesant M2 : " << std::endl;
  std::cout << "M2[0] =  : " << m2->getPosition()[0] << std::endl;
  std::cout << "M2[1] =  : " << m2->getPosition()[1] << std::endl;
  std::cout << "M2[2] =  : " << m2->getPosition()[2] << std::endl;

*//*
//  return (avance1[0] == expectedV1[0]) && (avance1[1] == expectedV1[1]) && (avance1[2] == expectedV1[2]);

}*/


bool Tests::testSimulation4()
{
    Simulation sAcien;

    Mobile* m1 = new Mobile("M1");
      Vecteur3D v1(3,3,3);
      m1->setVitesse(v1);

      Vecteur3D p2(2,2,2);
      Vecteur3D v2(1,1,1);
      MobilePesant * m2 = new MobilePesant("M2", p2, v2, 2);

    sAcien.ajoutCorps(m1);
    sAcien.ajoutCorps(m2);


    sAcien.simuler(2);

    Simulation sNouveau(sAcien);

    sNouveau.simuler(2);
    sNouveau.afficherCorps();

    return true;
}

 bool Tests::testVecteur3D(){
  Vecteur3D v1(3,2,1);
  Vecteur3D v2(2,2,2);
  v1+=2*v2 ;
  Vecteur3D expected(7,6,5);
  if(v1 == expected)
  {
    std::cout << " le test testVecteur3D réussit"<< std::endl;
    std::cout << "v1: "<< v1 << std::endl <<  "v2: "<< v2 << std::endl ;
    return true;
  }else{
    std::cout << " le test testVecteur3D ne réussit pas"<< std::endl;
    return false;
  }

}
