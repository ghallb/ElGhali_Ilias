
#include "mydevices.h"


#include <fstream>
#include <string>
using namespace std;

//int inc = 0 ;
//classe Capteur
Capteur::Capteur(int t, int s) : Device(), val(s), temps(t){
  alea=1;
}
Capteur::Capteur(const Capteur & C) : Device(), val(C.val), temps(C.temps){
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


int Capteur::getval(){
  return this->val ;
    }

void Capteur::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val;
    sleep(temps);
  }
}


Actionneur::Actionneur(float t):Device(),temps(t) {
}


void Actionneur::run(){
  while(1){
    cout << "empty actionneur\n";
    sleep(3);
  }
}
  

Moteur::Moteur(char c):Actionneur(2),corde(c),state(false),sens(0) {
}
Moteur::Moteur( const Moteur & M):Actionneur(1),corde(M.corde),state(false),sens(1) {
}
void Moteur::switchM (){
  if ((this->state)==true) {
    (this->state)=false ;}
 else {
   (this->state)=true;}
}

void Moteur::setsens(int i) {
  //exception si i vaut autre chose
  if (i==1) {
    (this->sens)=1 ;}
    else if (i==-1) {
      (this->sens)=-1 ;
    }
}

void Moteur::run(){
  // while(1){
    
  //   if (state==false)
  //     *ptrmem = 0;
  //   else
  //     *ptrmem = 1 ;
    
  //   sleep(temps);
  //   }
    while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if ((state==true) and (sens==1)){ sleep(1);
      cout << "((((moteur sens positif allumé : en train d'accorder))))\n";
}
     
else if ((state==true) and (sens==-1)){
sleep(1);
   cout << "((((moteur sens négatif allumé : en train d'accorder))))\n";
}

   
    sleep(temps);
    }
}



// //classe DigitalActuatorLED
// DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
// }

// void DigitalActuatorLED::run(){
//   while(1){
//     if(ptrmem!=NULL)
//       state=*ptrmem;
//     if (state==LOW)
//       cout << "((((eteint))))\n";
//     else
//     cout << "((((allume))))\n";
//     sleep(temps);
//     }
// }


// // classe IntelligentDigitalActuatorLED
// IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
// }

// void IntelligentDigitalActuatorLED::run(){
//   while(1){
//     if(ptrmem!=NULL)
//       state=*ptrmem;
//     if (state==LOW){
//       cout << "((((eteintINT))))\n";
//     inc=-50; }
//     else{
//     cout << "((((allumeINT))))\n";
//     inc=50; }
//     sleep(temps);
//     }
// }

//class Button
Button::Button(bool b,char c):Actionneur(3), state(b),corde(c){
}

Button :: Button(const Button & B) : Actionneur(3), state(B.state), corde(B.corde){
}
void Button::switchB() {
  if(this->state==true){
    this->state=false;
}
   else{
    
    this->state=true;
//cout << state ;
}

}
bool Button::getstate(){
  return this->state;
}
  
void Button::run(){
  while(1){
if (ptrmem != NULL) {
//cout << state ;
if(state==1){
   
  *ptrmem=1 ;
  //a voir apres sa
   //sprintf(S.buf,"%c",corde);
 }
 else{

   *ptrmem=0;
   
 }
sleep(1);
}
  }
    
    }

ILED::ILED( string c):Actionneur(1),state(LOW),couleur(c){
}
//void ILED::SetCouleur(char c) {
//this->couleur = c ;
//}

//void ILED::switchLED(){
  //if(this->state==true){
    //this->state=false;
//}
  // else{
    
    //this->state=true;

//}

//}
void ILED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      }
      
     // cout << "((((_eteint))))\n";
      
    else {
    cout << "La LED"<< this->couleur << endl ;   
    cout << "((((_allume))))\n";}
    sleep(temps);
    }
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen :: setbuf(char c){
sprintf(buf,"%c",c) ;
  }
char * I2CActuatorScreen :: getbuf(){
return buf ;
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





