#include "Tests.h"
#include <string>
#include <cmath>
#include <iostream>
#include "Simulation.h"

/*Cette éthode teste la classe mobile et renvoie true si les tests passent.*/

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

  bool success = m1.getPosition() == expected;
  if(success)
  {
     std::cout << "Le test testMobile1 a reussie" << std::endl;
  }else{
     std::cout << "Le test testMobile1 n'a pas reussie" << std::endl;
  }
}

/*Cette éthode teste la classe simulation et renvoie true si les tests passent.*/

bool Tests::testSimulation1()
{

  // creation d une simulation
  Simulation s;

  /* Creation de deux mobiles */

  Mobile* m1 = new Mobile("M1");
  Vecteur3D v1(3,3,3);
  m1->setVitesse(v1);

  Vecteur3D p2(2,2,2);
  Vecteur3D v2(1,1,1);
  Mobile* m2 = new Mobile("M2", p2, v2);

// ajout des mobiles dans la liste de mobiles de la classe Simulation

  s.ajoutCorps(m1);
  s.ajoutCorps(m2);

  // s->afficherCorps();
  s.simuler(2);
  // s->afficherCorps();

  /*creation de deux vecteurs3D qu'on comprare avec les positions des deux mobiles*/

  Vecteur3D positionEspereM1(6,6,6);
  Vecteur3D positionEspereM2(4,4,4);

  bool success = m1->getPosition() == positionEspereM1 && m2->getPosition() == positionEspereM2;
  if(success)
  {
     std::cout << "Le test testSimulation1 a reussie" << std::endl;
  }else{
     std::cout << "Le test testSimulation1 n'a pas reussie" << std::endl;
  }

}

  /*Le testSimulation2 teste le destructeur de la classe Simulation*/

bool Tests::testSimulation2()
{

  /*on commence par déclarer une simulation, puis ajouter des mobiles après
   leur création à la liste corps, on fait appel à la méthode simuler qui
    fait avancer tous les mobiles et qui modifie le temps.et on a initialisé
    deux objets de type vecteur3D « positionEspereM1» et « positionEspereM2»
    qui contiennent la position attendue après l’appel à la méthode simuler().
    */

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

 /*Cette méthode teste la classe MobilePesant.*/
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

  /*Le mobile pesant avance tant qu'il n 'est pas arrivé a la terre'*/
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



 /*Cette méthode teste le constructeur par copie codé dans la classe
  simulation qui copie tous les mobiles de la simulation en paramètre en
  suivant le type dynamique des mobiles(ordinaire ou pesant).*/
bool Tests::testSimulation4()
{
  /*Création d'une simulation*/
    Simulation sAcien;

    /*Création de deux mobiles (ordinaire et pesant)*/
    Mobile* m1 = new Mobile("M1");
    Vecteur3D v1(3,3,3);
    m1->setVitesse(v1);

    Vecteur3D p2(2,2,2);
    Vecteur3D v2(1,1,1);
    MobilePesant * m2 = new MobilePesant("M2", p2, v2, 2);

    // ajout d'un mobile ordinaire et d'un mobile pesant dans la liste de mobile

    sAcien.ajoutCorps(m1);
    sAcien.ajoutCorps(m2);

    // création d'une nouvelle simulation en utilisant le constructeur par copie
    Simulation sNouveau(sAcien);

    //sNouveau.simuler(2);

    /*on voit bien que la méthode copie est appellée en fonction du type dynamique de l'objet
    car dans les méthode copies des deux classes Mobile et Mobile pesant, on a fait un affichage
    spécifique à la classe*/

    sNouveau.afficherCorps();

    return true;
}


/*Cette méthode teste les opérateurs de la classe vecteur3D comme
l'opérateur d'addition, d'affectation, de multiplication et l prérateur <<*/

 bool Tests::testVecteur3D(){

   /*création de deux vecteurs*/

  Vecteur3D v1(3,2,1);
  Vecteur3D v2(2,2,2);

  v1+=2*v2 ;

  /*Estimation des coordonnées duvecteur v1 eb faisant la multiplication
   et l'affectation en meme temps*/

  Vecteur3D expected(7,6,5);

  /*tester si le vecteur résultant et le vecteur estimé sont
   les memes en utilisant l'opérateur ==*/

  if(v1 == expected)
  {
    std::cout << " le test testVecteur3D réussit"<< std::endl;
    /*Affichage des coordonnée d'un vecteur donnée en utilisant l'opérateur <<*/
    std::cout << "v1: "<< v1 << std::endl <<  "v2: "<< v2 << std::endl ;
    return true;
  }else{
    std::cout << " le test testVecteur3D ne réussit pas"<< std::endl;
    return false;
  }

}

/*Cette méthode teste la classe Terre et renvoie true se les tests passent */
bool Tests::testTerre()
{

  Vecteur3D v;
  Vecteur3D v1(6378000,0,0);

  /* Appel à ala fonction gravité de la classe terre*/

  v = Terre::getInstance().gravite(v1);
  std::cout << "v1: "<< v1 << std::endl;
  std::cout << "v: "<< v << std::endl;

  /*Estimation des coordonnées du vecteur resultat après l'appel a la méthode gravité*/
  Vecteur3D expected(-9.7987 ,0,0);
  std::cout << "expected "<< expected<< std::endl;

  /*Tester l'egalité du vecteur résultat et celui estimé*/

  if(v == expected)
  {
    std::cout << "Le test testTerre réussit"<< std::endl;
  }else{
    std::cout << "Le test testTerre ne réussit pas "<< std::endl;

  }
}

bool Tests::testSatellite1(){
  Terre *t;
  t->getInstance();
  Simulation s;
  double h = 200000;
  double dt = 0;
  double x = sqrt((t->getGM() / t->getRT() + h)-pow(h,2));
  double duree = 2*3.14*sqrt(pow(t->getRT()+h, 3)/t->getGM());
  Vecteur3D pos(x, 0, h);
  //Vecteur3D pos(t->getRT()+h, 0, h);
  Vecteur3D vitesse(0, sqrt(t->getGM()/(t->getRT()+h)), 0);
  MobilePesant *satellite = new MobilePesant("satellite", pos, vitesse, 40000);
  s.ajoutCorps(satellite);

  // 5340 == 1h29min

  while(dt <= 5340)
  {
    s.simuler(0.1);
    dt += 0.1;

  }
    std::cout <<"duree "<< duree <<std::endl;
    std::cout <<"x "<< x <<std::endl;
  std::cout << "position du satellite: " << satellite->getPosition()<< std::endl;
  double distance = satellite->getPosition().distance(pos);
  std::cout << "distance: " << distance << std::endl;


}
