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

uint32_t getFreq(void){
  //return SystemCoreClock;
  return HAL_RCC_GetHCLKFreq();
} 

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
  Serial1.begin(115200);
  //Serial1.print("Frequencia..: ");
  //Serial1.println(getFreq());
  pinMode(BUZZER_PIN, OUTPUT);
  beep(500);
  
  //Setup for Y sensor
  pinMode(led, OUTPUT);
  
  //Clearing displays.
  sprintf(str,"FF101010000000");
  Serial1.println(str);
  sprintf(str,"FF102010000000");
  Serial1.println(str);
  sprintf(str,"FF103010000000");
  Serial1.println(str);  
  //Initializing axis X and Y  
  vDrox  = new CDrox();
  vDroy  = new CDroy(PB10, PB15, PA8);
  vTachometer = new CTachometer();
  //This give time to things happen
  delay(1000);

  beep(50);delay(300);beep(50);
}

void loop(){
  
  vDrox->xResetKey();  
  vDroy->yResetKey();   
  printValue();
  threatLed();
  handleLeds();
  handleButtons();
  hadleOutputs();
  
  handleKeyboard();  
}
