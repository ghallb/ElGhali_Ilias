
#include "user.h"

#include <fstream>
#include <iostream>
#include <string>

// constructeur de user met tous les boutons à OFF, il faudra peut être créer un asseceur pour accèder à l'attribut state du bouton
user :: user(Button & b11, Button & b22,Button & b33,Button & b44,Button & b55,Button & b66,I2CActuatorScreen & screen) : b1(b11),b2(b22),b3(b33),b4(b44),b5(b55),b6(b66),S(screen) {


  }

void user :: choisir_corde() { 
  
 cout << "Choisir votre corde sur le répertoire en renommant le fichier texte et taper ok " << endl;
string ok;
cin >> ok;
  if (ifstream("mi")) {
    b1.switchB();

    S.setbuf('e');
 }
   if (ifstream("si")) {
    b2.switchB();
   S.setbuf('B');
 }
    if (ifstream("sol")) {
     
    b3.switchB();
S.setbuf('G');
    //cout << b3.getstate();
 }
     if (ifstream("ré")) {
    b4.switchB();

S.setbuf('D');
 }
      if (ifstream("la")) {
    b5.switchB();
S.setbuf('A');

 }
       if (ifstream("MI")) {
    b6.switchB();
S.setbuf('E');

 }
  
}


I2CActuatorScreen & user:: getS(){
    return S;
}

string user:: jouer_note()  {

  string note;
//cout << b3.getstate()<<"ilias";
  cout << "Jouer votre note" ;
  cin >> note ;

  return note;
}

Button user::getb3()  {

  
  return b3;
}
