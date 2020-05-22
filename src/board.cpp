#include "core_simulation.h"
#include "mydevices.h"
#include "user.h"
#include "accordeur.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs

  Button B1(false,'e');
   Button B2(false,'B');
    Button B3(false,'G');
     Button B4(false,'D');
      Button B5(false,'A');
       Button B6(false,'E');
       Moteur M1('e');
         Moteur M2('B');
	   Moteur M3('G');
	     Moteur M4('D');
	       Moteur M5('A');
	         Moteur M6('E');
		 Capteur C (DELAY,0);
		  user U(B1,B2,B3,B4,B5,B6);
		 accordeur SmartCh(B1,B2,B3,B4,B5,B6,M1,M2,M3,M4,M5,M6,C);
		 
       

 
  //I2CActuatorScreen screen;
  
  
 
 
  // branchement des capteurs actionneurs

  esp8266.pin(0,B1);
   esp8266.pin(1,B2);
    esp8266.pin(2,B3);
     esp8266.pin(3,B4);
      esp8266.pin(4,B5);
       esp8266.pin(5,B6);
       
 
  esp8266.pin(6,M1);
  esp8266.pin(7,M2);

  esp8266.pin(8,M3);

  esp8266.pin(9,M4);
  esp8266.pin(10,M5);

 esp8266.pin(11,M6);

  esp8266.pin(12,C);
  //esp8266.i2c(1,screen);
  
  
  
  // allumage de la carte
  esp8266.run();
  return 0;
}


