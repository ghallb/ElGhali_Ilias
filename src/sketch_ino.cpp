#include "core_simulation.h"
#include "accordeur.h"
#include "user.h"
#include <unistd.h>


#include <string>

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(0,INPUT);
    pinMode(1,INPUT);
      pinMode(2,INPUT);
        pinMode(3,INPUT);
	  pinMode(4,INPUT);
	    pinMode(5,INPUT);
  pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
     pinMode(9,OUTPUT);
      pinMode(10,OUTPUT);
       pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
}

// la boucle de controle arduino
void Board::loop(){
   //Nettoyer certains ports de la carte arduino pour éviter l'allumage à la première itération des LEDs
   this->io[15]=0;
   this->io[14]=0;
   this->io[13]=0;
   try{

   Monuser->choisir_corde();

   bus.write(1,Monuser->getS().getbuf(),100);
   string note;
   
   note= Monuser->jouer_note() ;
   

   Monaccordeur->accorder(note,io);
  
}
   catch(string const & chaine){
   if (chaine== "ERREUR : Mauvais bouton , veuillez mettre un bouton valide"){
    cerr << chaine << endl ;
}

  else{
    
    cerr << chaine << endl ;
}

 }  
 }


