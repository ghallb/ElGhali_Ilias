#ifndef USER_H
#define USER_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
#include "mydevices.h"





 class user  {
 private :
   // Le user va interagir avec les boutons (et sa guitare)
   Button & b1, & b2, & b3, & b4,& b5, & b6 ;
   // On veut écrire sur le screen une fois que le user choisit sa corde
   I2CActuatorScreen & S;

 public :

// constructeur de user met tous les boutons à OFF, et nettoie l'écran
   user(Button & b11, Button & b22,Button & b33,Button & b44,Button &     b55,Button & b66, I2CActuatorScreen & screen) ;
//Fonction qui demande à l'utilisateur de choisir une corde 
   void choisir_corde();
//Fonction qui demande à l'utilisateur de jouer une note sur le terminal (car simulation)
   string jouer_note();
//assesseur de l'attribut S
   I2CActuatorScreen & getS();

   
};





 

















#endif


