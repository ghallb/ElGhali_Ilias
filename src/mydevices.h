#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include "core_simulation.h"






 
// Toutes les devices et leurs classes filles


 class Capteur : public Device {
private:
     // fait osciller la valeur du capteur de 1
  int alea;
  // valeur mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
public :
   //constructeur ne pas oublier d'initialiser la classe mere
  Capteur(int t,int  s);

  // méthode qui va traduire le string reçu "++" en chiffres
  void traduire(std::string note);

  int getval() ;
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();

};









/* // exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device */
/* class LED: public Actionneur { */
/* private: */
/*   // etat de la LED */
/*   bool state; */
 
  
/* public: */
/*     // initialisation du temps de rafraichiisement */
/*   LED(bool b); */
/*   void switchLED(); */
/*   // thread representant l'actionneur et permettant de fonctionner independamment de la board */
/*   virtual void run(); */
/* }; */

class Actionneur : public Device {
 protected :
  int temps ;
  // temps entre deux prises de valeur
 public :
  //constructeur
 
  Actionneur (int t) ;
  virtual void run();
};
  
class Moteur : public Actionneur {
private :
char corde ;
bool state ;
int sens ;

public :
Moteur(char c) ;
void switchM() ;
void setsens(int i) ;
virtual void run() ;
};

class Button : public Actionneur{
 private :
  bool state ;
  char corde;
  //  I2CActuatorScreen S;

 public:
  Button(bool b,char c);
  bool getstate();
  void switchB();
  
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
   }; 
// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];
  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

#endif
