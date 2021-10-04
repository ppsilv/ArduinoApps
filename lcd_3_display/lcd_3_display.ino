/* This is the code for Atmega8, it'll just control
 *  the 7 segments displays, one for Axix X, Axis Y 
 *  and the last for the RPM.
 *  
 *  MCU..: Atmega8
 *  Freq.: 8Mhz clock internal
 *          
 *  
 *  Autor: Paulo da Silva
 *  Date.: 2021-09-09
 *  Version.: 1.20
 *  
 *  Version Date       Description 
 *  1.2     2021/09/30 inserted decimal places 1,2,3,4,5. data string size = 10bytes
 *                     
 *  
 *  Platform: Arduino
 *  This code are being tested using an arduino UNO but
 *  the target is an Atmega8, to write the atmega8 do the following:
 *  1 - Test program using arduino UNO
 *  2 - Use menu sketch/export compiled binary
 *  2 - To write the binary exported into atmega8, I use the stk500 to do so.
 *  
 *  I changed the table into library LedControl as follow:
 *  const static byte charTable [] PROGMEM  = {
    B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,
    B01111111,B01111011,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,
    B10000000,B00000001,B01100111,B00001000,B00110111,B00001110,B00010101,B00011101,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000
  };
 *   
 *  
 *  
 *  The byte stream it receives is formed as follow.
 *  
 *  FF101001234513
 *   | || ||    ||-> decimal places
 *   | || ||    |--> Signal 0 = negativ 1 = positiv
 *   | || ||-------> Data.      
 *   | || |--------> cmd command 00 write lcd 01 clear lcd 
 *   | ||----------> number of target display.
 *   | |-----------> Total of data bytes. 
 *   |-------------> Fixed header.   
 *      
 */

//We always have to include the library
#include "LedControl.h"
/*
 * LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
 * 
LedControl lc1=LedControl(5,3,4,1);
LedControl lc2=LedControl(8,6,7,1);
LedControl lc3=LedControl(12,10,11,1);
*/
LedControl lc1=LedControl(5,4,3,1);
LedControl lc2=LedControl(5,4,6,1);
LedControl lc3=LedControl(5,4,7,1);

/*
 * ATmega8 pinout
 *  Arduino    Atmega8-PORT,PIN  Display
 *      3        PD3, 5           lc1.CS
 *      4        PD4, 6           lc1.CLK
 *      5        PD5, 11          lc1.DIN
 *      
 *      6        PD6, 12          lc2.CS
 *      4        PD7, 6           lc2.CLK
 *      5        PB0, 16          lc2.DIN
 *      
 *      7        PB2, 13          lc3.CS
 *      4        PB3, 6           lc3.CLK
 *      5        PB4, 11          lc3.DIN
 *              
 */




int numDisplay = 1,cmd = 0;
int sign,dig5,dig4,dig3,dig2,dig1;
int ponto = 0;

#define CMD_IMPRIME 0
#define CMD_CLEAR   1

void writeLcd1()
{
  //Display 1;
  if( sign == 0 ){
    lc1.setDigit(0,5,17,false);
  }else{
      lc1.setDigit(0,5,32,false);
  }
  if( ponto == 4 ) lc1.setDigit(0,4,dig5,true); else lc1.setDigit(0,4,dig5,false);
  if( ponto == 3 ) lc1.setDigit(0,3,dig4,true); else lc1.setDigit(0,3,dig4,false);
  if( ponto == 2 ) lc1.setDigit(0,2,dig3,true); else lc1.setDigit(0,2,dig3,false);
  if( ponto == 1 ) lc1.setDigit(0,1,dig2,true); else lc1.setDigit(0,1,dig2,false);
  if( ponto == 0 ) lc1.setDigit(0,0,dig1,false); else lc1.setDigit(0,0,dig1,false);
}
void writeLcd2()
{
  Serial.println("Escrevendo no lcd 2");
  if( sign == 0 ){
    lc2.setDigit(0,5,17,false);
  }else{
      lc2.setDigit(0,5,32,false);
  } 
  //Display 2;
  
  if( ponto == 4 ) lc2.setDigit(0,4,dig5,true); else lc2.setDigit(0,4,dig5,false);
  if( ponto == 3 ) lc2.setDigit(0,3,dig4,true); else lc2.setDigit(0,3,dig4,false);
  if( ponto == 2 ) lc2.setDigit(0,2,dig3,true); else lc2.setDigit(0,2,dig3,false);
  if( ponto == 1 ) lc2.setDigit(0,1,dig2,true); else lc2.setDigit(0,1,dig2,false);
  if( ponto == 0 ) lc2.setDigit(0,0,dig1,false); else lc2.setDigit(0,0,dig1,false);
  
}
void writeLcd3()
{  
  //Display 1;
  
  lc3.setDigit(0,4,dig5,false);
  lc3.setDigit(0,3,dig4,false);
  lc3.setDigit(0,2,dig3,false);
  lc3.setDigit(0,1,dig2,false);
  lc3.setDigit(0,0,dig1,false);
  
}
//           111  
// 0123456789012  
// FF09200043210 display = 2 cmd clear   00
// FF09301043210 display = 3 cmd imprime 01
int totalBytesRecebidos = 0;
int lenght = 0;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.begin(9600);
  lc1.shutdown(0,false);
  lc1.setIntensity(0,8);
  lc1.clearDisplay(0);

  lc2.shutdown(0,false);
  lc2.setIntensity(0,8);
  lc2.clearDisplay(0);

  lc3.shutdown(0,false);
  lc3.setIntensity(0,8);
  lc3.clearDisplay(0);

  lc1.setDigit(0,7,2,false);lc1.setDigit(0,6,0,false);lc1.setDigit(0,5,2,false);lc1.setDigit(0,4,1,false);
  lc1.setDigit(0,3,0,false);lc1.setDigit(0,2,9,false);
  lc1.setDigit(0,1,3,false);lc1.setDigit(0,0,0,false);
  //Version
  lc2.setDigit(0,3,0,false);lc2.setDigit(0,2,1,true);
  lc2.setDigit(0,1,2,false);lc2.setDigit(0,0,0,false);
  delay(2000);
  
}
void loop(){
   if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    if( incomingByte == 'F' && totalBytesRecebidos == 0 ){
      totalBytesRecebidos = 1;
    }else    if( incomingByte == 'F' && totalBytesRecebidos == 1 ){
      totalBytesRecebidos = 2;
    }else if( totalBytesRecebidos == 2 ){
      lenght = (incomingByte - 48) * 10;
      totalBytesRecebidos = 3;
    }else if( totalBytesRecebidos == 3 ){
      lenght += (incomingByte - 48);    
      totalBytesRecebidos = 4;
      Serial.print("lenght ");
      Serial.println(lenght);      
    }else if( lenght > 0 && totalBytesRecebidos == 4){
      totalBytesRecebidos=5;
      numDisplay = incomingByte - 48;
      Serial.print("numDisplay ");
      Serial.println(numDisplay);      
    }else if( lenght > 0 && (totalBytesRecebidos == 5)){
      totalBytesRecebidos=6;
      cmd = (incomingByte - 48) * 10;
    }else if( lenght > 0 && (totalBytesRecebidos == 6)){
      totalBytesRecebidos=7;
      cmd += (incomingByte - 48);
      Serial.print("cmd ");
      Serial.println(cmd);
      
    }else if( lenght > 0 && (totalBytesRecebidos == 7)){
      totalBytesRecebidos=8;
      dig5 = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 8)){
      totalBytesRecebidos=9;
      dig4 = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 9)){
      totalBytesRecebidos=10;
      dig3 = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 10)){
      totalBytesRecebidos=11;
      dig2 = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 11)){
      totalBytesRecebidos=12;
      dig1 = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 12)){
      totalBytesRecebidos=13;
      sign = (incomingByte - 48); 
    }else if( lenght > 0 && (totalBytesRecebidos == 13)){
      if ( (totalBytesRecebidos - 3 ) == lenght){
        ponto = (incomingByte - 48); 
        switch(cmd){
          case CMD_IMPRIME:
              cmd_00(); break;
          case CMD_CLEAR:
              cmd_01(); break;    
        }
      }else{
        Serial.println("Not all bytes were being received...");
      }
      totalBytesRecebidos = 0;
    }
   }  
}

void cmd_00(){
        
        Serial.print("totalBytesRecebidos ");
        Serial.println(totalBytesRecebidos);
        
        //Serial.println(" Todos os bytes foram recebidos");
        Serial.print(sign);
        Serial.print(dig5);
        Serial.print(dig4);
        Serial.print(dig3);
        Serial.print(dig2);
        Serial.println(dig1);
        
        if( numDisplay == 1 ){
          writeLcd1();
        }else if( numDisplay == 2 ){
          writeLcd2();
        }else if( numDisplay == 3 ){
          writeLcd3();
        }      
}

void cmd_01(){
        if( numDisplay == 1 ){
          Serial.println("Limpando lcd 1");
          lc1.clearDisplay(0);
          /*
          lc1.setDigit(0,7,32,false);
          lc1.setDigit(0,6,32,false);
          lc1.setDigit(0,5,32,false);
          lc1.setDigit(0,4,32,false);
          lc1.setDigit(0,3,32,false);
          lc1.setDigit(0,2,32,false);
          lc1.setDigit(0,1,32,false);
          lc1.setDigit(0,0,32,false);      
          */    
        }else if( numDisplay == 2 ){
          Serial.println("Limpando lcd 2");
          lc2.clearDisplay(0);
          /*
          lc2.setDigit(0,7,32,false);
          lc2.setDigit(0,6,32,false);
          lc2.setDigit(0,5,32,false);
          lc2.setDigit(0,4,32,false);
          lc2.setDigit(0,3,32,false);
          lc2.setDigit(0,2,32,false);
          lc2.setDigit(0,1,32,false);
          lc2.setDigit(0,0,32,false);          
          */
        }else if( numDisplay == 3 ){
          Serial.println("Limpando lcd 3");
          lc3.clearDisplay(0);
          /*
          lc3.setDigit(0,7,32,false);
          lc3.setDigit(0,6,32,false);
          lc3.setDigit(0,5,32,false);
          lc3.setDigit(0,4,32,false);
          lc3.setDigit(0,3,32,false);
          lc3.setDigit(0,2,32,false);
          lc3.setDigit(0,1,32,false);
          lc3.setDigit(0,0,32,false);  
          */        
        }      
}
