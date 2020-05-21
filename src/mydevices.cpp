
#include "mydevices.h"
#include "core_simulation.h"
#include <fstream>

using namespace std;

int inc = 0 ;
//classe Capteur
Capteur::Capteur(int t, int s) : Device(), val(s), temps(t){
  alea=1;
}

void Capteur::traduire(string note){
 
    if (note=="+"){
      val= 1;
    }
     if (note=="++"){
      val= 2;
    }
      if (note=="+++"){
      val= 3;
    }
       if (note=="-"){
      val=-1;
    }
        if (note=="--"){
      val= -2;
    }
	 if (note=="---"){
      val= -3;
    }
	  if (note=="0"){
	    val=0;
    }
}

void Capteur::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val;
    sleep(temps);
  }
}





//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((eteint))))\n";
    else
    cout << "((((allume))))\n";
    sleep(temps);
    }
}


// classe IntelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void IntelligentDigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      cout << "((((eteintINT))))\n";
    inc=-50; }
    else{
    cout << "((((allumeINT))))\n";
    inc=50; }
    sleep(temps);
    }
}

//class ExternalDigitalSensorButton
ExternalDigitalSensorButton::ExternalDigitalSensorButton(bool b,int t):Device(),state(b),temps(t){
}

void  ExternalDigitalSensorButton::run(){
  while(1){
if(ifstream("ON")){
  *ptrmem=1 ;
  state=true;
 }
 else{
   *ptrmem=0;
   state=false;
 }
  }
    sleep(temps);
    }

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}





