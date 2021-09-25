#include "Ctimer.h"
#include "Dro_axis_y.h"

#define led PC13
#define TOGGLE_LED digitalWrite(led, !digitalRead(led));


char str[32];

C_timer tLed =  C_timer(100);
C_timer tPrint =  C_timer(250);

int contador=0;

void threatLed(){
  if( tLed.isTimeout() ){
    TOGGLE_LED;
  }
}

void printXvalue(){
  int vlr;
  if( tPrint.isTimeout() ){
      vlr = vDroy->getValue();
  
      sprintf(str,"  %06d (%03d.%02d)",contador++,vlr/100,vlr%100);
      Serial1.println(str);
  }
}
void setup() {
  Serial1.begin(115200);
  Serial1.print("FF09200043210");
  pinMode(led, OUTPUT);
  vDroy  = new CDroy(PB10, PB15, PA8);
}

void loop(){
  threatLed();  
  printXvalue();
}




/*
#ifdef TESTE_DRO

#define GATE  PB10
#define DATA  PB15
#define CLOCK PA8

//Registers
int xFlags=0;
int xValue=0;
int xSign=1;
int yValue=0;

long contador=0;



void threatLed(){
  if( tLed.isTimeout() ){
    TOGGLE_LED;
  }
}

static unsigned char gate_status=1;
void printXvalue(){
  int vlr;
  if( tPrint.isTimeout() ){
    if( gate_status == 1 ){
      vlr = xValue;
      contador++;
      sprintf(str,"Vlr:%05d %4X%04X",contador,xFlags,vlr);
      Serial1.print(str);
      sprintf(str,"  (%c%03d.%02d)",xSign==1 ? '+':'-',vlr/100,vlr%100);
      Serial1.println(str);
    }
  }
}
void setup() {
  Serial1.begin(115200);
  Serial1.print("FF09200043210");
  pinMode(led, OUTPUT);
  pinMode(GATE, INPUT_PULLUP);
  pinMode(DATA, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(GATE), Gate_ISR, CHANGE ); 
  attachInterrupt(digitalPinToInterrupt(CLOCK),Clock_ISR, RISING ); 
}

void loop(){
  threatLed();  
  printXvalue();
}

static int bitsLidos=0;
static unsigned long interrupt_time=0;
static unsigned long last_interrupt_time=0;

static long value = 0;


//void printXvalue(){
//  int vlr;
//  if( (millis()- xvalue_print_time) > XVALUE_PRINT_DURATION ){
//    if( gate_status == 1 ){
//      vlr = xValue;
//      sprintf(str,"Vlr:%4X%04X",xFlags,vlr);
//      Serial1.print(str);
//      sprintf(str,"  (%c%03d.%02d)",xSign==1 ? '+':'-',vlr/100,vlr%100);
//      Serial1.println(str);
//      xvalue_print_time = millis();
//    }
//  }
//}

void Clock_ISR(){
  if( gate_status == 0 ){
    value |= (digitalRead(DATA)<<bitsLidos);
    bitsLidos++;    
  }
  if(bitsLidos > 23){
    xValue = (value&0x00FFFF);//-5;
    xFlags = (value&0x00FF0000)>>16;
    if( xFlags && 0x20 ){
      xSign = 1;  // Show "+"  
    }else{
      xSign = 0;  // Show "-"  
    }
  }
}

void Gate_ISR(){
  last_interrupt_time = 0;
  interrupt_time = millis();
  
  // If interrupts come faster than 1, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 1) 
  {
      if( digitalRead(GATE) == 1 ){
        gate_status = 1;
        bitsLidos = 0;
        value = 0;
      }
      else{
        gate_status = 0;
      }
  }
  last_interrupt_time = interrupt_time;
}



void piscaLed(){
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
}

void loopteste() {
  delay(500);
  Serial1.print("FF09200043210");
  delay(500);
  Serial1.print("FF09200143211");
}

#endif
*/
