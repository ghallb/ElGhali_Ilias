#ifndef ACCORDEUR_H
#define ACCORDEUR_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"
#include "mydevices.h"
#include "user.h"

class accordeur {
 private :
   // L'accordeur doit interagir avec tous les devices 
   Button bmi,bsi,bsol,bre,bla,bMI ;
   moteur mmi,msi,msol,mre,mla,mMI ;
   capteur capt ;

 public :

   accordeur(button b1 ,button b2,button b3,button b4,button b5,button b6,moteur m1,moteur m2,moteur m3,moteur m4,moteur m5,moteur m6,capteur c) ;
   void accorder(string note) ;
   

   
};



















#endif



