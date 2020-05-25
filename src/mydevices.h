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
   //constructeur 
  Capteur(int t,int  s);
  //Surcharge
  Capteur( const Capteur & C);

  // méthode qui va traduire le string reçu "++" ou "-" en chiffre interprétable
  void traduire(std::string note);
  
  //assesseur pour l'attribut val
  int getval() ;

  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();

};



class Actionneur : public Device {
 protected :

  // temps entre deux prises de valeur
  float temps ;
  
 public :

  //constructeur
  Actionneur (float t) ;
  virtual void run();
};

  
class Moteur : public Actionneur {
private : 
// chaque moteur est associé à une corde
char corde ;
//état actuel du moteur : allumé ou éteint
bool state ;
//sens de rotation : positif(1) ou négatif (-1)
int sens ;

public :
//Constructeur
Moteur(char c) ;
//Surcharge
Moteur( const Moteur & M);
//méthode permettant de fixer le sens de rotation du moteur
void setsens(int i) ;
virtual void run() ;
};

class Button : public Actionneur{
 private :
  //état actuel du bouton
  bool state ;
  //Chaque bouton est associé à une corde
  char corde;

 public:
  //Constructeur
  Button(bool b,char c);
  //Surcharge
  Button( const Button & B);
  //assesseur de l'attribut state
  bool getstate();
  //méthode pour changer l'état du bouton
  void switchB();
  
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
   }; 


class ILED : public Actionneur {
private:
  // etat actuel de la LED
  int state;
  string couleur ;

  
public:
   //Constructeur 
  ILED(string c);
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
  //Méthode permettant de remplir le buffer(attribut) de l'I2CActuatorScreen
  void setbuf(char c);
  //assesseur de l'attribut buf
  char * getbuf();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

#endif
