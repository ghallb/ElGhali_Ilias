

#include "accordeur.h"

#include <fstream>
#include <iostream>
#include <string>

accordeur ::  accordeur(Button & b1 ,Button & b2,Button & b3,Button & b4,Button & b5,Button & b6,Moteur & m1,Moteur & m2,Moteur & m3,Moteur & m4,Moteur & m5,Moteur & m6,Capteur & c) : bmi(b1) ,bsi(b2),bsol(b3),bre(b4),bla(b5),bMI(b6),mmi(m1),msi(m2),msol(m3),mre(m4),mla(m5),mMI(m6),capt(c) {}


Button & accordeur :: getbsol() {
return  (* this).bsol;
}
void accordeur :: accorder(string note,unsigned short port[]) {
  //vérifier le bouton allumé, donc la corde à accorder
//cout << bsol.getstate() << "z" ;
  if (bmi.getstate()==true) {
cout << "accorder mi" ;

    //traduire la note par une valeur grace au capteur
    capt.traduire(note);
    //récupérerla valeur du capteur, allumer le moteur un certain temps pour faire tourner le piston, puis l'éteindre, et enfin switch le bouton en OFF
    if (capt.getval()==1){
      //asseceur à définir, permettant de fixer le sens de rotation du moteur
      mmi.setsens(1);
      // mmi.switchM();
       port[6]=1;
      sleep(3);
      // mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
     else if (capt.getval()==2){

       mmi.setsens(1);
       //mmi.switchM();
        port[6]=1;
      sleep(4);
      //mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
     else if (capt.getval()==3){
	mmi.setsens(1);  
	//mmi.switchM();
	 port[6]=1;
      sleep(5);
      //mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
     else if (capt.getval()==-1){
	mmi.setsens(-1);  
	//mmi.switchM();
	 port[6]=1;
      sleep(3);
      //mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
     else if (capt.getval()==-2){
	mmi.setsens(-1);  
	//mmi.switchM();
	 port[6]=1;
      sleep(4);
      //mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
     else if (capt.getval()==-3){
	mmi.setsens(-1);  
	//mmi.switchM();
	 port[6]=1;
      sleep(5);
      //mmi.switchM();
       port[6]=0;
      bmi.switchB();
  }
    
  }
    else if (bsi.getstate()==true) {
        cout << "accorder si";
    capt.traduire(note);
  
    if (capt.getval()==1){
     
      msi.setsens(1);
      //msi.switchM();
       port[7]=1;
      sleep(3);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }
     else if (capt.getval()==2){
       msi.setsens(1);
       //msi.switchM();
        port[7]=1;
      sleep(4);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }
     else if (capt.getval()==3){
	msi.setsens(1);  
	//msi.switchM();
	 port[7]=1;
      sleep(5);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }
     else if (capt.getval()==-1){
	msi.setsens(-1);  
	//msi.switchM();
	 port[7]=1;
      sleep(3);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }
     else if (capt.getval()==-2){
	msi.setsens(-1);  
	//msi.switchM();
	 port[7]=1;
      sleep(4);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }
     else if  (capt.getval()==-3){
	msi.setsens(-1);  
	//msi.switchM();
	 port[7]=1;
      sleep(5);
      //msi.switchM();
       port[7]=0;
      bsi.switchB();
  }


  }
    else if (bsol.getstate()==true) {
cout<< "accorderSol";
         capt.traduire(note);
  
    if (capt.getval()==1){
     
      msol.setsens(1);
      //msol.switchM();
       port[8]=1;
      sleep(3);
      //msol.switchM();
       port[8]=0;
      bsol.switchB();
  }
     else if (capt.getval()==2){
       msol.setsens(1);
       //msol.switchM();
        port[8]=1;

      sleep(4);
      //msol.switchM();
      port[8]=0;
      bsol.switchB();
  }
     else if (capt.getval()==3){
	msol.setsens(1);  
	//msol.switchM();
	 port[8]=1;
      sleep(5);
      //msol.switchM();
      port[8]=0;
      bsol.switchB();
  }
     else if (capt.getval()==-1){
	msol.setsens(-1);  
	//msol.switchM();
	 port[8]=1;
      sleep(3);
      //msol.switchM();
      port[8]=0;
      bsol.switchB();
  }
     else if (capt.getval()==-2){
	msol.setsens(-1);  
	//msol.switchM();
	 port[8]=1;
      sleep(4);
      //msol.switchM();
      port[8]=0;
      bsol.switchB();
  }
     else if (capt.getval()==-3){
	msol.setsens(-1);  
	//msol.switchM();
	 port[8]=1;
      sleep(5);
      //msol.switchM();
      port[8]=0;
      bsol.switchB();
  }




  }
    else if (bre.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mre.setsens(1);
      //mre.switchM();
       port[9]=1;
      sleep(2);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }
     else if (capt.getval()==2){
       mre.setsens(1);
       //mre.switchM();
        port[9]=1;
      sleep(3);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }
     else if (capt.getval()==3){
	mre.setsens(1);  
	//mre.switchM();
	 port[9]=1;
      sleep(4);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }
     else if (capt.getval()==-1){
	mre.setsens(-1);  
	//mre.switchM();
	 port[9]=1;
      sleep(2);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }
     else if (capt.getval()==-2){
	mre.setsens(-1);  
	//mre.switchM();
	 port[9]=1;
      sleep(3);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }
     else if (capt.getval()==-3){
	mre.setsens(-1);  
	//mre.switchM();
	 port[9]=1;
      sleep(4);
      //mre.switchM();
      port[9]=0;
      bre.switchB();
  }



  }
    else if (bla.getstate()==true) {

              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mla.setsens(1);
      //mla.switchM();
       port[10]=1;
      sleep(1);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }
     else if (capt.getval()==2){
       mla.setsens(1);
       //mla.switchM();
        port[10]=1;
      sleep(2);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }
     else if (capt.getval()==3){
	mla.setsens(1);  
	//mla.switchM();
	 port[10]=1;
      sleep(3);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }
     else if (capt.getval()==-1){
	mla.setsens(-1);  
	//mla.switchM();
	 port[10]=1;
      sleep(1);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }
     else if (capt.getval()==-2){
	mla.setsens(-1);  
	//mla.switchM();
	 port[10]=1;
      sleep(2);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }
     else if (capt.getval()==-3){
	mla.setsens(-1);  
	//mla.switchM();
	 port[10]=1;
      sleep(3);
      //mla.switchM();
      port[10]=0;
      bla.switchB();
  }

  }
    else if (bMI.getstate()==true) {
              capt.traduire(note);
  
    if (capt.getval()==1){
     
      mMI.setsens(1);
      //mMI.switchM();
       port[11]=1;
      sleep(1);
      //mMI.switchM();
       port[11]=0;
      bMI.switchB();
  }
     else if (capt.getval()==2){
       mMI.setsens(1);
       //mMI.switchM();
        port[11]=1;
      sleep(2);
      //mMI.switchM();
      port[11]=0;
      bMI.switchB();
  }
     else if (capt.getval()==3){
	mMI.setsens(1);  
	//mMI.switchM();
	 port[11]=1;
      sleep(3);
      //mMI.switchM();
      port[11]=0;
      bMI.switchB();
  }
     else if (capt.getval()==-1){
	mMI.setsens(-1);  
	//mMI.switchM();
	 port[11]=1;
      sleep(1);
      //mMI.switchM();
      port[11]=0;
      bMI.switchB();
  }
     else if (capt.getval()==-2){
	mMI.setsens(-1);  
	//mMI.switchM();
	 port[11]=1;
      sleep(2);
      //mMI.switchM();
      port[11]=0;
      bMI.switchB();
  }
     else if (capt.getval()==-3){
	mMI.setsens(-1);  
	//mMI.switchM();
	 port[11]=1;
      sleep(3);
      //mMI.switchM();
      port[11]=0;
      bMI.switchB();
  }

  }



}
