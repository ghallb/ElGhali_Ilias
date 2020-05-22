#ifndef USER_H
#define USER_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"
#include "mydevices.h"


 class user  {
 private :
   // Le user va interagir avec les boutons uniquement (et sa guitare)
   button b1,b2,b3,b4,b5,b6 ;

 public :

   user() ;
   void choisir_corde();
   string jouer_note();

   
};























#endif


