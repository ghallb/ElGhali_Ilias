#include "mydevices.h"
#include "core_simulation.h"
#include "user.h"
#include <fstream>
#include <iostream>


// constructeur de user met tous les boutons à OFF, il faudra peut être créer un asseceur pour accèder à l'attribut state du bouton
user :: user(Button b11, Button b22,Button b33,Button b44,Button b55,Button b66):b1(b11),b2(b22),b3(b33),b4(b44),b5(b55),b6(b66)  {

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


