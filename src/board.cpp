
#include "core_simulation.h"
#include "mydevices.h"
#include "accordeur.h"
#include "user.h"


#include <string>

int main(){
 
  // achat des senseurs et actionneurs

  I2CActuatorScreen S1;
  I2CActuatorScreen & MarefS1 = S1;

  Button  B1(false,'e');
  Button & MarefB1 = B1;
   Button  B2(false,'B');
  Button & MarefB2 = B2;
    Button  B3(false,'G');
Button & MarefB3 = B3;
     Button  B4(false,'D');
Button & MarefB4 = B4;
      Button  B5(false,'A');
Button & MarefB5 = B5;
       Button  B6(false,'E');
Button & MarefB6 = B6;
       Moteur  M1('e');
Moteur & MarefM1 = M1;
         Moteur  M2('B');
Moteur & MarefM2 = M2;
	   Moteur  M3('G');
Moteur & MarefM3 = M3;
	     Moteur  M4('D');
Moteur & MarefM4 = M4;
	       Moteur  M5('A');
Moteur & MarefM5 = M5;
	         Moteur  M6('E');
Moteur & MarefM6 = M6;
		 Capteur  C (DELAY,0);
Capteur & MarefC = C;
		  user U(MarefB1,MarefB2,MarefB3,MarefB4,MarefB5,MarefB6,MarefS1);
		 accordeur SmartCh(MarefB1, MarefB2, MarefB3,MarefB4,MarefB5,MarefB6,MarefM1,MarefM2,MarefM3,MarefM4,MarefM5,MarefM6,MarefC);
		 
  // creation d'une board
		 Board esp8266;
		 esp8266.initAU(&SmartCh,&U);

 
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
  esp8266.i2c(1,MarefS1);
  
  
  
  // allumage de la carte
  esp8266.run();
  return 0;
}


