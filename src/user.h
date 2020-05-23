#ifndef USER_H
#define USER_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
//#include "mydevices.h"
#include "core_simulation.h"




 class user  {
 private :
   // Le user va interagir avec les boutons uniquement (et sa guitare)
   Button b1,b2,b3,b4,b5,b6 ;

 public :

   user(Button b11, Button b22,Button b33,Button b44,Button b55,Button b66) ;
   void choisir_corde();
   string jouer_note();

   
};























#endif


