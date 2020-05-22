#include "mydevices.h"
#include "core_simulation.h"
#include "user.h"
#include <fstream>
#include <iostream>


accordeur ::  accordeur(button b1 ,button b2,button b3,button b4,button b5,button b6,moteur m1,moteur m2,moteur m3,moteur m4,moteur m5,moteur m6,capteur c) : bmi(b1) ,bsi(b2),bsol(b3),bre(b4),bla(b5),bMI(b6),mmi(m1),msi(m2),msol(m3),mre(m4),mla(m5),mMI(m6),capt(c) {}

accordeur :: accorder(string note) {
  //vérifier le bouton allumé, donc la corde à accorder
  if (bmi.getstate()==true) {
    //traduire la note par une valeur grace au capteur
    capt.traduire(note);
    //récupérerla valeur du capteur, allumer le moteur un certain temps pour faire tourner le piston, puis l'éteindre, et enfin switch le bouton en OFF
    if (capt.getval()==1){
      //asseceur à définir, permettant de fixer le sens de rotation du moteur
      mmi.setsens(1);
      mmi.switchM();
      sleep(1);
      mmi.swithchM();
      bmi.switchB();
  }
     else if (capt.getval()==2){
       mmi.setsens(1);
      mmi.switchM();
      sleep(2);
      mmi.swithchM();
      bmi.switchB();
  }
     else if (capt.getval()==3){
	mmi.setsens(1);  
      mmi.switchM();
      sleep(3);
      mmi.swithchM();
      bmi.switchB();
  }
     else if (capt.getval()==-1){
	mmi.setsens(-1);  
      mmi.switchM();
      sleep(1);
      mmi.swithchM();
      bmi.switchB();
  }
     else if (capt.getval()==-2){
	mmi.setsens(-1);  
      mmi.switchM();
      sleep(2);
      mmi.swithchM();
      bmi.switchB();
  }
     else  (capt.getval()==-3){
	mmi.setsens(-1);  
      mmi.switchM();
      sleep(3);
      mmi.swithchM();
      bmi.switchB();
  }
    
  }
    else if (bsi.getstate()==true) {
        
    capt.traduire(note);
  
    if (capt.getval()==1){
     
      msi.setsens(1);
      msi.switchM();
      sleep(1);
      msi.swithchM();
      bsi.switchB();
  }
     else if (capt.getval()==2){
       msi.setsens(1);
      msi.switchM();
      sleep(2);
      msi.swithchM();
      bsi.switchB();
  }
     else if (capt.getval()==3){
	msi.setsens(1);  
      msi.switchM();
      sleep(3);
      msi.swithchM();
      bsi.switchB();
  }
     else if (capt.getval()==-1){
	msi.setsens(-1);  
      msi.switchM();
      sleep(1);
      msi.swithchM();
      bsi.switchB();
  }
     else if (capt.getval()==-2){
	msi.setsens(-1);  
      msi.switchM();
      sleep(2);
      msi.swithchM();
      bsi.switchB();
  }
     else  (capt.getval()==-3){
	msi.setsens(-1);  
      msi.switchM();
      sleep(3);
      msi.swithchM();
      bsi.switchB();
  }


  }
    else if (bsol.getstate()==true) {
         capt.traduire(note);
  
    if (capt.getval()==1){
     
      msol.setsens(1);
      msol.switchM();
      sleep(1);
      msol.swithchM();
      bsol.switchB();
  }
     else if (capt.getval()==2){
       msol.setsens(1);
      msol.switchM();
      sleep(2);
      msol.swithchM();
      bsol.switchB();
  }
     else if (capt.getval()==3){
	msol.setsens(1);  
      msol.switchM();
      sleep(3);
      msol.swithchM();
      bsol.switchB();
  }
     else if (capt.getval()==-1){
	msol.setsens(-1);  
      msol.switchM();
      sleep(1);
      msol.swithchM();
      bsol.switchB();
  }
     else if (capt.getval()==-2){
	msol.setsens(-1);  
      msol.switchM();
      sleep(2);
      msol.swithchM();
      bsol.switchB();
  }
     else  (capt.getval()==-3){
	msol.setsens(-1);  
      msol.switchM();
      sleep(3);
      msol.swithchM();
      bsol.switchB();
  }




  }
    else if (bre.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mre.setsens(1);
      mre.switchM();
      sleep(1*0.8);
      mre.swithchM();
      bre.switchB();
  }
     else if (capt.getval()==2){
       mre.setsens(1);
      mre.switchM();
      sleep(2*0.8);
      mre.swithchM();
      bre.switchB();
  }
     else if (capt.getval()==3){
	mre.setsens(1);  
      mre.switchM();
      sleep(3*0.8);
      mre.swithchM();
      bre.switchB();
  }
     else if (capt.getval()==-1){
	mre.setsens(-1);  
      mre.switchM();
      sleep(1*0.8);
      mre.swithchM();
      bre.switchB();
  }
     else if (capt.getval()==-2){
	mre.setsens(-1);  
      mre.switchM();
      sleep(2*0.8);
      mre.swithchM();
      bre.switchB();
  }
     else  (capt.getval()==-3){
	mre.setsens(-1);  
      mre.switchM();
      sleep(3*0.8);
      mre.swithchM();
      bre.switchB();
  }



  }
    else if (bla.getstate()==true) {

              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mla.setsens(1);
      mla.switchM();
      sleep(1*0.5);
      mla.swithchM();
      bla.switchB();
  }
     else if (capt.getval()==2){
       mla.setsens(1);
      mla.switchM();
      sleep(2*0.5);
      mla.swithchM();
      bla.switchB();
  }
     else if (capt.getval()==3){
	mla.setsens(1);  
      mla.switchM();
      sleep(3*0.5);
      mla.swithchM();
      bla.switchB();
  }
     else if (capt.getval()==-1){
	mla.setsens(-1);  
      mla.switchM();
      sleep(1*0.5);
      mla.swithchM();
      bla.switchB();
  }
     else if (capt.getval()==-2){
	mla.setsens(-1);  
      mla.switchM();
      sleep(2*0.5);
      mla.swithchM();
      bla.switchB();
  }
     else  (capt.getval()==-3){
	mla.setsens(-1);  
      mla.switchM();
      sleep(3*0.5);
      mla.swithchM();
      bla.switchB();
  }

  }
    else (bMI.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mMI.setsens(1);
      mla.switchM();
      sleep(1*0.3);
      mMI.swithchM();
      bMI.switchB();
  }
     else if (capt.getval()==2){
       mMI.setsens(1);
      mMI.switchM();
      sleep(2*0.3);
      mMI.swithchM();
      bMI.switchB();
  }
     else if (capt.getval()==3){
	mMI.setsens(1);  
      mMI.switchM();
      sleep(3*0.3);
      mMI.swithchM();
      bMI.switchB();
  }
     else if (capt.getval()==-1){
	mMI.setsens(-1);  
      mMI.switchM();
      sleep(1*0.3);
      mMI.swithchM();
      bMI.switchB();
  }
     else if (capt.getval()==-2){
	mMI.setsens(-1);  
      mMI.switchM();
      sleep(2*0.3);
      mMI.swithchM();
      bMI.switchB();
  }
     else  (capt.getval()==-3){
	mMI.setsens(-1);  
      mMI.switchM();
      sleep(3*0.3);
      mMI.swithchM();
      bMI.switchB();
  }

  }



}
