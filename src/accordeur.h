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
   Button & bmi, & bsi,& bsol,& bre,& bla,& bMI ;
   Moteur & mmi,& msi,& msol,& mre,& mla,& mMI ;
   Capteur & capt ;
   ILED & LB;
   ILED & LV;
   ILED & LR;

 public :

   accordeur(Button & b1 ,Button & b2,Button & b3,Button & b4,Button & b5,Button & b6,Moteur & m1,Moteur & m2,Moteur & m3,Moteur & m4,Moteur & m5,Moteur & m6,Capteur & c, ILED & L1, ILED & L2, ILED & L3) ;
   void accorder(string note,unsigned short port[MAX_IO_PIN]) ;
   Button & getbsol();

   
};



















#endif



