#include <Keypad.h>

const byte numRows = 5; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad
byte ini;
byte fim;
unsigned char buf[16];
  
char keymap[numRows][numCols]={
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','C'},
  {'L','0','R','E'}
};
//byte rowPins[numRows] = {PA7, PA6, PA5, PA4, PA3};
//byte colPins[numCols]= {PC15, PA0, PA1, PA2};

byte rowPins[numRows] = {PC15, PA0, PA1, PA2, PA3};
byte colPins[numCols] = { PA7, PA6, PA5, PA4 };


//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

String numstr = "";
void handleKeyboard()
{
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    beep(50);
    Serial1.print("keypressed=" + (String)keypressed + " ");
    switch (keypressed)
    {
      case '1':
        numstr = "1    ";
        break;
      case '2':
        numstr = "2    ";
        break;
      case '3':
        numstr = "3    ";
        break;
      case '4':
        numstr = "4    ";
        break;
      case '5':
        numstr = "5    ";
        break;
      case '6':
        numstr = "6    ";
        break;
      case '7':
        numstr = "7    ";
        break;
      case '8':
        numstr = "9    ";
        break;
      case '0':
        numstr = "0    ";
        break;
      case 'A':
        numstr = "F1   ";
        break;
      case 'B':
        numstr = "F2   ";
        break;
      case 'C':
        numstr = "ESC  ";
        break;
      case 'E':
        numstr = "ENTER";
        break;
      case 'D':
        numstr = "DOWN ";
        break;
      case 'U':
        numstr = "UP   ";
        break;
      case 'R':
        numstr = "RIGHT ";
        break;
      case 'L':
        numstr = "LEFT ";
        break;
      case '*':
        numstr = "*    ";
        break;
      case '#':
        numstr = "#    ";
        break;
      default:
        break;
    }
    if (numstr != "")
    {
      Serial1.println("numstr=" + (String)numstr + " ");
    }
  }
}
void putChar(unsigned char ch){
  buf[fim++] = ch;
  if( fim == 16 ){
    fim = 0;
  }
}
unsigned char getChar(){
  unsigned char ch = buf[ini++];
  if( ini == 16 ){
    ini = 0;
  }
  return ch;
}

/**************************************************************************************
   https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/
   4x5 Matrix Array 20 Keypad [S187] : http://rdiot.tistory.com/135 [RDIoT Demo]

                     Teclado    5 x 4



  #include "Teclado.h"

   const byte numRows= 5; //number of rows on the keypad
   const byte numCols= 4; //number of columns on the keypad
    char keymap[numRows][numCols]=
  {
    {'A','B','#','*'},
    {'1','2','3','U'},
    {'4','5','6','D'},
    {'7','8','9','C'},
    {'L','0','R','E'}
  };
    byte rowPins[numRows] = {PA7, PA6, PA5, PA4, PA3};
    byte colPins[numCols]= {PC15, PA0, PA1, PA2};



  CTeclado::CTeclado(){
  myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
  numstr = "";
  }

  void CTeclado::loopTeclado()
  {
    char keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY) {
      Serial.print("keypressed=" + (String)keypressed + " ");
      switch (keypressed) {
        case '1':
          numstr = "1 ";
          break;
        case '2':
          numstr = "2 ";
          break;
        case '3':
          numstr = "3 ";
          break;
        case '4':
          numstr = "4 ";
          break;
        case '5':
          numstr = "5 ";
          break;
        case '6':
          numstr = "6 ";
          break;
        case '7':
          numstr = "7 ";
          break;
        case '8':
          numstr = "9 ";
          break;
        case '0':
          numstr = "0 ";
          break;
        case 'A':
          numstr = "F1 ";
          break;
        case 'B':
          numstr = "F2 ";
          break;
        case 'C':
          numstr = "ESC ";
          break;
        case 'E':
          numstr = "ENTER";
          break;
        case 'D':
          numstr = "DOWN ";
          break;
        case 'U':
          numstr = "UP ";
          break;
        case 'R':
          numstr = "RIGHT ";
          break;
        case 'L':
          numstr = "LEFT ";
          break;
        case ' ':
          numstr = " ";
          break;
        case '#':
          numstr = "# ";
          break;

        default:
          break;
      }


      if(numstr !="") {
        Serial1.println("numstr=" + (String)numstr + " ");
      }
   }
  }

  void CTeclado::putChar(unsigned char ch){
  buf[fim++] = ch;
  if( fim == 16 ){
    fim = 0;
  }
  }
  unsigned char CTeclado::getChar(){
  unsigned char ch = buf[ini++];
  if( ini == 16 ){
    ini = 0;
  }
  return ch;
  }
*/
