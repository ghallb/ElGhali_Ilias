#include "mydevices.h"
#include "core_simulation.h"
#include "user.h"
#include <fstream>
#include <iostream>


// constructeur de user met tous les boutons à OFF, il faudra peut être créer un asseceur pour accèder à l'attribut state du bouton
user :: user()  {

  b1.state=false;
   b2.state=false;
    b3.state=false;
     b4.state=false;
      b5.state=false;
       b6.state=false;
  }

void user :: choisir_corde() {

  if (ifstream("mi")) {
    b1.switchB();
 }
   if (ifstream("si")) {
    b2.switchB();
 }
    if (ifstream("sol")) {
    b3.switchB();
 }
     if (ifstream("ré")) {
    b4.switchB();
 }
      if (ifstream("la")) {
    b5.switchB();
 }
       if (ifstream("MI")) {
    b6.switchB();
 }
  
}


string user:: jouer_note()  {

  string note;
  cout << "Jouer votre note" ;
  cin >> note ;
  return note;
}


