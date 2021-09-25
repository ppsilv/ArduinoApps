/* This code is the POC that we can read igaging with an arduino.
 * It is tested with an arduino UNO
 * 
 * Date.....: 20210906
 * Time.....: 00:21
 * Autor....: Paulo da Silva
 * 
 * 
 */
#include "Dro_axis_y.h"

CDroy * vDroy;





















































 /* FROM HERE I'LL CUT OFF WHEN CLASS TESTED.
unsigned int datapulse[24];
unsigned int gate=0, gi;
volatile unsigned int datavalue, datavalue_old, first_inch; // The measured value
unsigned int data[24]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,0,0,0,1,0,0,0,1};
int sign,digit_sign;
int terminou = 0;
int iniciou = 0;
volatile unsigned int digit0, digit1, digit2, digit3, digit4, digit5; // Single digits
int offset = 0;
int offsetFixed = -3;

#define PIN_CLOCK_INT0_ENABLE (EIMSK |= 0x01)
#define PIN_CLOCK_DATA_INT1_ENABLE (EIMSK |= 0x02)

#define PIN_CLOCK_INT0_DISABLE (EIMSK &= ~(0x01))
#define PIN_CLOCK_DATA_INT1_DISABLE (EIMSK &= ~(0x02))

#define INT0_gate_INT1_FALLING (EICRA = 0x0E) //0x0E)

//disableInterrupt

//ISR(INT0_vect){
void interruptGate(){  
  cli();
  gate = 1;
  iniciou = 1;
  datavalue = 0;
}

//ISR(INT1_vect){
void interruptClock(){  
  if (iniciou == 1) // Gate is set (start point)
  {         //In may case the signal are inverted, I amplified the signal with a transistor NPN
          if (PIND & (1 << PD4) ) // Check PD4 if high
            {
            datapulse[gi] = 0; // Set datapulse to 0
            }
          else
            {
            datapulse[gi] = 1; // Set datapulse to 1
            }
      
          if (gi <24) // Just do this 24 times (for 24 bits, 0-23)
            {
              {
              datavalue = datavalue + (data[gi] * datapulse[gi]); // Sum of all single bits
              }
            gi ++;
            }
            
          if (datapulse[22] == 1)
            {
            sign = 1; //45; // Show "+"
            digit_sign = 11; 
            }
            
          if (datapulse[22] == 0)
            {
            sign = 0; //43; // Show "-" 
            digit_sign = 12;
            }
          // End
      
          if (gi == 24) // Reset to 0, no more pulses
            {
            iniciou = 0;
            gi = 0;
            terminou = 1;
            }
  } 
    
  else // Gate = 0, no gate connected
    {
    // Maybe "error gate" message,if gate signal is not there ...
    }  
}

void setupAxisY() {
  DDRD &= 0xE0; //0b11100000
  PORTD = 0xFC; //0b11111100

  
   //TODO: Iniciar as interrupções.
   
  
  //EICRA |= (0b10 << ISC10) | (0b10 << ISC00);
  INT0_gate_INT1_FALLING;
  
  //EIMSK = 0x03; //0b00000011
  PIN_CLOCK_INT0_ENABLE;
  
  
  sei();
  while(1){
    if( gate == 1 ){
        gate = 0;
        delayMicroseconds(250);  
    }
    if(gate == 0){
      delayMicroseconds(20000);  
    }
    if(gate == 0){
      break;
    }
  }
  Serial.begin(115200);
  Serial.println("DRO 2021SET");
  
}

void loopAxisY(){
  int lixo;
  //loopLcd01();
  if( gate == 1 ) {
    //Serial.println("gate");
    PIN_CLOCK_INT0_DISABLE;
    terminou = 0;
    gate = 0;
    PIN_CLOCK_DATA_INT1_ENABLE;
    sei();
  }  
  if( terminou == 1 ){
        cli();
        digit0 = digit_sign;
        
        offset = datavalue % 4;
        datavalue = (datavalue / 4) + offset + offsetFixed;
        digit1 = (datavalue/10000);   
        digit2 = ((datavalue%10000)/1000);
        digit3 = (((datavalue%10000)%1000)/100); //&led_pattern[10]; // & dp for 7-segment display (for uart: UDR=44)
        digit4 = ((((datavalue%10000)%1000)%100)/10);
        digit5 = ((((datavalue%10000)%1000)%100)%10);

        Serial.print(datavalue);
        Serial.print(" ");
        if ( sign == 1 )
          Serial.print(" +");
        else    
          Serial.print(" -");
        Serial.print(digit1);
        Serial.print(digit2);
        Serial.print(digit3);
        Serial.print(",");
        Serial.print(digit4);
        Serial.print(digit5);
        Serial.println(" mm ");

        PIN_CLOCK_DATA_INT1_DISABLE;
        PIN_CLOCK_INT0_ENABLE;
        
        //TODO: Escrever o resultado no display Y
        // write all digits.
        
        delayMicroseconds(60000);
        
        sei();
    }
}
*/
