
#include "user.h"

#include <fstream>
#include <iostream>
#include <string>

//Constructeur
user :: user(Button & b11, Button & b22,Button & b33,Button & b44,Button & b55,Button & b66,I2CActuatorScreen & screen) : b1(b11),b2(b22),b3(b33),b4(b44),b5(b55),b6(b66),S(screen) {}


//Fonction qui demande à l'utilisateur de choisir sa corde : dans cette simulation, l'utilisateur devra renommer un fichier texte dans le dossier src par le nom de la corde qu'il souhaite accorder

void user :: choisir_corde() { 
  sleep(1);
 cout << "Choisir votre corde sur le répertoire en renommant le fichier texte et taper ok " << endl;
string ok;
cin >> ok;

//la méthode ifstream permet de vérifier si dans le même dossier que là ou se trouve "user.cpp" il y'a un fichier "mi"
  if (ifstream("mi")) {
    //allumer le bouton correspondant à la bonne corde
    b1.switchB();
    //Remplir le buffer du screen par le nom de la note
    S.setbuf('e');
 }
   if (ifstream("si")) {
    b2.switchB();
   S.setbuf('B');
 }
    if (ifstream("sol")) {
     
    b3.switchB();
   S.setbuf('G');

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


//En simulation, l'utilisateur devra simuler la note une fois qu'il aura choisi la corde, et écrire soit "+"(la note est plus haute que la fondamentale) soit "-" (la note est plus basse que la fondamentale) soit "++"...

string user:: jouer_note()  {

  string note;
  cout << "Jouer votre note" ;
  cin >> note ;

  return note;
}


