#include "Ctimer.h"
#include "Dro_axis_x.h"
#include "Dro_axis_y.h"
#include "Tachometer.h"

#define TESTE_KEY_PWR_ON  PB0
#define BUZZER_PIN PB1
#define led PC13
#define TOGGLE_LED digitalWrite( led, !digitalRead(led) );

C_timer tLed    =  C_timer(100);
C_timer tPrint  =  C_timer(250);

void threatLed(){
  if( tLed.isTimeout() ){
    TOGGLE_LED;
  }
}

void beep(unsigned char b){
  digitalWrite(BUZZER_PIN, HIGH);
  delay(b);
  digitalWrite(BUZZER_PIN, LOW);  
}

void printValue(){
  if( tPrint.isTimeout() ){
      vDroy->printY();
      vDrox->printX();
      vTachometer->writeRpm();
  }
}

void setup() {
  char str[32];
  Serial1.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  beep(500);
  //Setup for Y sensor
  pinMode(led, OUTPUT);
  //Initializing axis X and Y  
  vDrox  = new CDrox();
  vDroy  = new CDroy(PB10, PB15, PA8);
  vTachometer = new CTachometer();
  
  //This give time to things happen
  delay(2000);
  //Clearing displays.
  sprintf(str,"FF101010000000");
  Serial1.println(str);
  sprintf(str,"FF102010000000");
  Serial1.println(str);
  sprintf(str,"FF103010000000");
  Serial1.println(str);  
}

void loop(){
  vDrox->xResetKey();  
  vDroy->yResetKey();   
  printValue();
  threatLed();
}
