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
  /*Le testSimulation2 teste le destructeur de la classe Simulation*/

  Simulation* s = new Simulation();

  /*création de deux mobiles et ajout dans la liste coprs de la classe simulation*/

  Mobile* m1 = new Mobile("M1");
  Vecteur3D v1(3,3,3);
  m1->setVitesse(v1);

  Vecteur3D p2(2,2,2);
  Vecteur3D v2(1,1,1);
  Mobile* m2 = new Mobile("M2", p2, v2);

/*Ajout des mobiles dans la liste de mobiles corps de la classe simulation*/

  s->ajoutCorps(m1);
  s->ajoutCorps(m2);

/*déstruction les mobiles contenus dans la liste de mobiles de la classe simulation*/

  delete s;

  /*delete(m1);  on ne peut pas faire un delete sur le mobile m1 car il a été détruit avec l'appel de delete s;*/

  return true;
}

bool Tests::testMobile2() {
   //h represente l'altitude
 /*Cette méthode teste la classe MobilePesant.
 On a choisi une hauteur h = 10, un intervalle de temps de 0.01,
 et on aimerait tester si un mobile pesant lâché d’une hauteur h,
 mettra un certain temps (Calculé au préalable)pour atteindre le sol.*/

  double h = 10.0;
  double temps = 0;
  double dt = 0.01;
  double expectedTime;

  /*calculer le temps estimé*/

  expectedTime = sqrt((2 * h)/9.81);

  /*Création d'un mobile pesant avec une vitesse nulle
  et qui se trouve à une altitude h*/

  Vecteur3D vitesse(0, 0, 0);
  Vecteur3D position(0,0, h);
  std::string nom  = "mobilePesant";
  Mobile * mobilePesant = new MobilePesant(nom, position, 200.0);

  mobilePesant->setVitesse(vitesse);

  while (h > 0) {

    mobilePesant->avance(dt);

    /*mettre à jour h par sa position */
    h = mobilePesant->getPosition()[2];

    /*mettre à jour le temps*/
    temps += dt;

  }
  std::cout << "temps: " << temps << std::endl;
  std::cout << "Time expected: "<< expectedTime << std::endl;

  delete mobilePesant;

   /*tester si le mobile a fait le temps estimé pour atteindre
    le sol à une erreur de 10 puissance -1*/

  if((temps <= expectedTime + 0.1) && (temps >= expectedTime - 0.1))
  {
    /*Si l'erreur est de 1O puissance -1*/
    std::cout << "Le mobile pesant a mis environ " << expectedTime <<"pour atteindre le sol"<< std::endl;
    return true;
  }else{
    return false;
  }
}

/*Cette méthode gère les les mobiles ordinaires et les mobiles pesants
 (la méthode avance() est appelée en fonction du type dynamique de l’objet
 (Elle est déclaré virtuelle dans la classe mère).*/

bool Tests::testSimulation3()
{

  Simulation s;

  /*Création de deux mobiles (ordinaire et pesant)*/

  std::string ordinaire =" MobileOrdianre";
  std::string pesant =" MobilePesant";

  Vecteur3D vitesseO(1, 1, 1);
  Vecteur3D positionO(4,4, 0);
  Vecteur3D vitesseP(1, 1, 1);
  Vecteur3D positionP(3,3, 0);

  Mobile *mobileOrdinaire = new Mobile(ordinaire, positionO, vitesseO);
  Mobile *mobilePesant = new MobilePesant(pesant, positionP,vitesseP,200.0);

  /*Ajout des mobile à la liste des mobiles corps de la simulation*/

  s.ajoutCorps(mobileOrdinaire);
  s.ajoutCorps(mobilePesant);

  //s.afficherCorps();

  /*estimation des coordonnées des vecteurs positions et vitesses des deux mobiles
  ( En calculant suivant le type dynamique ) */

  Vecteur3D expected_Pos_Ordinaire(12,12,8);
  Vecteur3D expected_Vit_Ordinaire(1, 1, 1); // la vitesse d'mobile ordinaire reste inchangée

  Vecteur3D expected_Pos_Pesant(11,11, -227.44);
  Vecteur3D expected_Vit_Pesant(1, 1, -77.48);

  while(s.getTemps() < 8)
  {
    s.simuler(2);
  }
  //s.afficherCorps();

  /*tester si leur positions et vitesses sont bien celles estimées*/

  bool success= (mobileOrdinaire->getPosition() == expected_Pos_Ordinaire && mobileOrdinaire->getVitesse() == expected_Vit_Ordinaire
        &&
        mobilePesant->getPosition() == expected_Pos_Pesant && mobilePesant->getVitesse() == expected_Vit_Pesant);

        if (success)
        {
          std::cout << "Le test testSimulation3 réussit" << std::endl;
          return true;
        }else{
          std::cout << "Le test testSimulation3 ne réussit pas" << std::endl;
          return false;
        }

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

    // ajout d'un mobile ordinaire et d'un mobile pesant dans la liste de mobile

    sAcien.ajoutCorps(m1);
    sAcien.ajoutCorps(m2);
    //sAcien.oteCorps(m2);
    // sNouveau.oteCorps(m2);

    sAcien.simuler(2);

    // création d'une nouvelle simulation 

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

bool Tests::testTerre()
{
  // a revoir
  Vecteur3D v;
  Vecteur3D v1(6378000,0,0);

  v = Terre::getInstance().gravite(v1);
  std::cout << "v1: "<< v1 << std::endl;
  std::cout << "v: "<< v << std::endl;

  Vecteur3D expected(-9.7987 ,0,0);
  std::cout << "expected "<< expected<< std::endl;

  if(v == expected)
  {
    std::cout << "Le test testTerre réussit"<< std::endl;
  }else{
    std::cout << "Le test testTerre ne réussit pas "<< std::endl;

  }
}

bool Tests::testSatellite1(){
  double x = sqrt((3.986 * pow(10, 14) / 6378000 + 200)-pow(200,2));
  Vecteur3D m(x, 0, 200);

}
