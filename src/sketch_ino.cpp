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
 
}

// la boucle de controle arduino
void Board::loop(){
  //user U(B1,B2,B3,B4,B5,B6);
   Monuser->choisir_corde();
 bus.write(1,Monuser->getS().getbuf(),100);
   string note;
   note= Monuser->jouer_note() ;
  
  // accordeur SmartCh(B1,B2,B3,B4,B5,B6,M1,M2,M3,M4,M5,M6,C);
  //cout << Monuser->getb3().getstate() ;

  //cout << Monaccordeur->getbsol().getstate() << "chadi";
  Monaccordeur->accorder(note,io);
  // char buf[100];
  //  char buf2[100];
  //   char buf3[100];
  // int val;
  // int val2;
  // int val3;
  // static int cpt=0;
  // static int bascule=0;
  // int i=0;
  // for(i=0;i<10;i++){
  //   // lecture sur la pin 1 et 2 et 4 :
  //   val=analogRead(1);
  //   val2=analogRead(2);
  //   val3=analogRead(4);
    
  //   sprintf(buf,"temperature %d",val);
  //   Serial.println(buf);
  //   sprintf(buf2,"luminosite %d",val2);
  //   Serial.println(buf2);
  //   if (val3==0) {
  //      Serial.println("bouton OFF");
  // 	}
  //     else  {
  //      Serial.println("bouton ON");
  // 	}
   
    
  //   if(cpt%5==0){
  //       // tous les 5 fois on affiche sur l ecran la temperature
  //     sprintf(buf,"%d",val);
  //     bus.write(1,buf,100);
  //     sprintf(buf2,"%d",val2);
  //     bus.write(1,buf2,100);
  //      sprintf(buf3,"%d",val3);
  //     bus.write(1,buf3,100);
  //   }
    
  // if(val3==1){
  //   digitalWrite(3,HIGH);}
  // else{
  //   digitalWrite(3,LOW);}
  //   cpt++;
  //   sleep(1);
  }
// on eteint et on allume la LED
//   if(bascule){
//     digitalWrite(0,HIGH);
//     }
//   else{
//     digitalWrite(0,LOW);
//   }
//   bascule=1-bascule;


// }


