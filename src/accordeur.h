#ifndef ACCORDEUR_H
#define ACCORDEUR_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "mydevices.h"
//#include "core_simulation.h"



class accordeur {
 private :
   // L'accordeur doit interagir avec tous les devices 
   Button & bmi, & bsi,& bsol,& bre,& bla,& bMI ; //topologie : bnomdelacorde
   Moteur & mmi,& msi,& msol,& mre,& mla,& mMI ;  //topologie : mnomdelacorde
   Capteur & capt ;
   ILED & LB; //Led bleu
   ILED & LV; //Led verte
   ILED & LR; //Led rouge

 public :
   
   //Constructeur de accordeur permettant de l'initialiser avec des références de tous les devices dont il a besoin dans le board.cpp
   accordeur(Button & b1 ,Button & b2,Button & b3,Button & b4,Button & b5,Button & b6,Moteur & m1,Moteur & m2,Moteur & m3,Moteur & m4,Moteur & m5,Moteur & m6,Capteur & c, ILED & L1, ILED & L2, ILED & L3) ;

   //Méthode accorder qui gère tout l'accordage : relevé du capteur, interprétation, allumage des bonnes leds, allumages du bon moteur associé à la bonne corde. Nb : prend en argument la note à traduire par le capteur, et un unsigned short qui correspondra au io de board lors de l'appel de la fonction
   void accorder(string note,unsigned short port[MAX_IO_PIN]) ;
   
   Button & getB(Button & B);
   
};



















#endif



