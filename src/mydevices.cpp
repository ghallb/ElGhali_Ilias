
#include "mydevices.h"


#include <fstream>
#include <string>
using namespace std;

//classe Capteur
Capteur::Capteur(int t, int s) : Device(), val(s), temps(t){
  alea=1;
}
Capteur::Capteur(const Capteur & C) : Device(), val(C.val), temps(C.temps){
  alea=1;
}
void Capteur::traduire(string note){
 cout<<"looooo";
    if (note=="+"){
      val= 1;
    }
     else if (note=="++"){
      val= 2;
    }
      else if (note=="+++"){
      val= 3;
    }
       else if (note=="-"){
      val=-1;
    }
        else if (note=="--"){
      val= -2;
    }
	 else if (note=="---"){
      val= -3;
    }
	  else if (note=="0"){
	    val=0;
    }
 else  {
          
	 val= -100000;
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


// Class Actionneur

Actionneur::Actionneur(float t):Device(),temps(t) {
}


void Actionneur::run(){
  while(1){
    cout << "empty actionneur\n";
    sleep(3);
  }
}
  
//Class Moteur : class fille de Actionneur

Moteur::Moteur(char c):Actionneur(0.9),corde(c),state(false),sens(0) {
}

Moteur::Moteur( const Moteur & M):Actionneur(1),corde(M.corde),state(false),sens(1) {
}

void Moteur::setsens(int i) {
  //exception si i vaut autre chose
  if (i==1) {
    (this->sens)=1 ;}
    else if (i==-1) {
      (this->sens)=-1 ;
    }
}

void Moteur:: run() {
 while(1){
	
    if(ptrmem!=NULL)
      state=*ptrmem;
    if ((state==true) and (sens==1)){
sleep(1);
      cout << "((Le moteur de la corde " << "["<<this->corde<<"]"<< "  tourne au sens NEGATIF : en train d'accorder))\n";}
else if ((state==true) and (sens==-1)){
sleep(1);
   cout << "((Le moteur de la corde " << "["<<this->corde<<"]"<< "  tourne au sens POSITIF : en train d'accorder))\n";}
    sleep(temps);
    }
}





//class Button : class fille de Actionneur

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
}

}

bool Button::getstate(){
  return this->state;
}
  
void Button::run(){
  while(1){
if (ptrmem != NULL) {

if(state==1){
   
  *ptrmem=1 ;
  
 }
 else{

   *ptrmem=0;
   
 }
sleep(1);
}
  }
    
    }


//class ILED : class fille de Actionneur

ILED::ILED( string c):Actionneur(1.8),state(LOW),couleur(c){
}


void ILED::run(){
unsigned short aux1 = *ptrmem;
unsigned short aux2 = *ptrmem;

  while(1){
aux1 = *ptrmem ;
    if(ptrmem!=NULL)
      state=*ptrmem;
	
    if ((state==LOW) and (aux1!= aux2)){
      
     cout << "La LED"<< this->couleur << "  s'((((_eteint))))\n" ;}  
      
    else if ((state==HIGH)) { 
    cout << "La LED"<< this->couleur << " est ((((_allume))))\n" ;}
    sleep(temps);
aux2=aux1 ;
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





