

#include "accordeur.h"

#include <fstream>
#include <iostream>
#include <string>

//Constructeur
accordeur ::  accordeur(Button & b1 ,Button & b2,Button & b3,Button & b4,Button & b5,Button & b6,Moteur & m1,Moteur & m2,Moteur & m3,Moteur & m4,Moteur & m5,Moteur & m6,Capteur & c, ILED & L1,ILED & L2,ILED & L3) : bmi(b1) ,bsi(b2),bsol(b3),bre(b4),bla(b5),bMI(b6),mmi(m1),msi(m2),msol(m3),mre(m4),mla(m5),mMI(m6),
capt(c), LB(L1), LV(L2), LR(L3) {}

Button & accordeur:: getB(Button & B) {
return B;
}

//Méthode accorder qui gère tout l'accordage 
void accordeur :: accorder(string note,unsigned short port[]) {

  //vérifier le bouton allumé, donc la corde à accorder en vérifiant le state de chaque bouton
   
  if (bmi.getstate()==true) {

    //traduire la note par une valeur grace au capteur
    capt.traduire(note);
    //récupérer la valeur du capteur,  un certain temps pour faire tourner le piston, puis l'éteindre, et enfin switch le bouton en OFF
    if (capt.getval()==1){
      //allumer la LED rouge indiquant que la note est trop haute
      port[15]=1;
      //fixer le sens de rotation du moteur
      mmi.setsens(1);
      //allumer le moteur
      port[6]=1;
      //Attendre un certain temps : piston entrain de tourner
      sleep(3);
      //Eteindre le moteur
      port[6]=0;
      //Eteindre le bouton
      bmi.switchB();
      //Eteindre la LED rouge
      port[15]=0;
      sleep(1.3);
      //Allumer la LED verte pour indiquer que l'accordage est terminé
      port[14]=1;
      sleep(2);
      //Eteindre la LED verte
      port[14]=0;

      
  }

    // cas où la note est un peu plus aigue
     else if (capt.getval()==2){
	port[15]=1;
      	mmi.setsens(1);
        port[6]=1;
      	sleep(4);
       	port[6]=0;
      	bmi.switchB();
	port[15]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
	mmi.setsens(1); 
	port[6]=1;
      	sleep(5);
      	port[6]=0;
      	bmi.switchB();
	port[15]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	mmi.setsens(-1); 
	port[6]=1;
      	sleep(3);
      	port[6]=0;
      	bmi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
	
  }
     else if (capt.getval()==-2){
	port[13]=1;
	mmi.setsens(-1); 
	port[6]=1;
      	sleep(4);
      	port[6]=0;
      	bmi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-3){
	port[13]=1;
	mmi.setsens(-1); 
	port[6]=1;
      	sleep(5);
      	port[6]=0;
      	bmi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
 else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else {
	
      	bmi.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }
    
  }
    else if (bsi.getstate()==true) {
    
    capt.traduire(note);
  
    if (capt.getval()==1){
      port[15]=1;
      msi.setsens(1);
       port[7]=1;
      sleep(3);
       port[7]=0;
      bsi.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==2){
       port[15]=1;
      msi.setsens(1);
       port[7]=1;
      sleep(4);
       port[7]=0;
      bsi.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
      msi.setsens(1);
       port[7]=1;
      sleep(5);
       port[7]=0;
      bsi.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	msi.setsens(-1); 
	port[7]=1;
      	sleep(3);
      	port[7]=0;
      	bsi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-2){
	port[13]=1;
	msi.setsens(-1); 
	port[7]=1;
      	sleep(4);
      	port[7]=0;
      	bsi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if  (capt.getval()==-3){
	port[13]=1;
	msi.setsens(-1); 
	port[7]=1;
      	sleep(5);
      	port[7]=0;
      	bsi.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else {
	
      	bsi.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }

  }
    else if (bsol.getstate()==true) {
         
         capt.traduire(note);
  
    if (capt.getval()==1){
     
      port[15]=1;
      msol.setsens(1);
       port[8]=1;
      sleep(3);
       port[8]=0;
      bsol.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==2){
      port[15]=1;
      msol.setsens(1);
       port[8]=1;
      sleep(4);
       port[8]=0;
      bsol.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
      msol.setsens(1);
       port[8]=1;
      sleep(5);
       port[8]=0;
      bsol.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	msol.setsens(-1); 
	port[8]=1;
      	sleep(3);
      	port[8]=0;
      	bsol.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-2){
	port[13]=1;
	msol.setsens(-1); 
	port[8]=1;
      	sleep(4);
      	port[8]=0;
      	bsol.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-3){
	port[13]=1;
	msol.setsens(-1); 
	port[8]=1;
      	sleep(5);
      	port[8]=0;
      	bsol.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }


else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else {
	
      	bsol.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }

  }
    else if (bre.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
     port[15]=1;
      mre.setsens(1);
       port[9]=1;
      sleep(2);
       port[9]=0;
      bre.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==2){
       port[15]=1;
      mre.setsens(1);
       port[9]=1;
      sleep(3);
       port[9]=0;
      bre.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
      mre.setsens(1);
       port[9]=1;
      sleep(4);
       port[9]=0;
      bre.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	mre.setsens(-1); 
	port[9]=1;
      	sleep(2);
      	port[9]=0;
      	bre.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-2){
	port[13]=1;
	mre.setsens(-1); 
	port[9]=1;
      	sleep(3);
      	port[9]=0;
      	bre.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-3){
	port[13]=1;
	mre.setsens(-1); 
	port[9]=1;
      	sleep(4);
      	port[9]=0;
      	bre.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
else {
	
      	bre.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }
  }
    else if (bla.getstate()==true) {

              capt.traduire(note);
  
    if (capt.getval()==1){
     
      port[15]=1;
      mla.setsens(1);
       port[10]=1;
      sleep(2);
       port[10]=0;
      bla.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==2){
       port[15]=1;
      mla.setsens(1);
       port[10]=1;
      sleep(3);
       port[10]=0;
      bla.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
      mla.setsens(1);
       port[10]=1;
      sleep(4);
       port[10]=0;
      bla.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	mla.setsens(-1); 
	port[10]=1;
      	sleep(2);
      	port[10]=0;
      	bla.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-2){
	port[13]=1;
	mla.setsens(-1); 
	port[10]=1;
      	sleep(3);
      	port[10]=0;
      	bla.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-3){
	port[13]=1;
	mla.setsens(-1); 
	port[10]=1;
      	sleep(4);
      	port[10]=0;
      	bla.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
else {
	
      	bla.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }
  }
    else if (bMI.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
      port[15]=1;
      mMI.setsens(1);
       port[11]=1;
      sleep(2);
       port[11]=0;
      bMI.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==2){
       port[15]=1;
      mMI.setsens(1);
       port[11]=1;
      sleep(3);
       port[11]=0;
      bMI.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==3){
	port[15]=1;
      mMI.setsens(1);
       port[11]=1;
      sleep(4);
       port[11]=0;
      bMI.switchB();
      port[15]=0;
	sleep(1.3) ;
      port[14]=1;
      sleep(3);
      port[14]=0;
  }
     else if (capt.getval()==-1){
	port[13]=1;
	mMI.setsens(-1); 
	port[11]=1;
      	sleep(2);
      	port[11]=0;
      	bMI.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-2){
	port[13]=1;
	mMI.setsens(-1); 
	port[11]=1;
      	sleep(3);
      	port[11]=0;
      	bMI.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }
     else if (capt.getval()==-3){
	port[13]=1;
	mMI.setsens(-1); 
	port[11]=1;
      	sleep(4);
      	port[11]=0;
      	bMI.switchB();
	port[13]=0;
	sleep(1.3);
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else if (capt.getval()==0){
	
      	port[14]=1;
	sleep(3);
      	port[14]=0;
  }

else {
	
      	bMI.switchB();
        throw string ("ERREUR : Note impossible, veuillez respecter le format des notes possibles");
  }
  }



}

