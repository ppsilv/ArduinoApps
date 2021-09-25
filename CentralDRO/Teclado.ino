/*
https://www.filipeflop.com/blog/teclado-matricial-4x4-arduino/
*/
/*
 4x5 Matrix Array 20 Keypad [S187] : http://rdiot.tistory.com/135 [RDIoT Demo] 

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
const byte numRows= 5; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
 
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','C'},
  {'L','0','R','E'}
};

#include <Wire.h>
#include <Keypad.h>

const byte numRows= 5; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{‘A’,‘B’,’#’,’*’},
{‘1’,‘2’,‘3’,‘U’},
{‘4’,‘5’,‘6’,‘D’},
{‘7’,‘8’,‘9’,‘C’},
{‘L’,‘0’,‘R’,‘E’}
};

byte rowPins[numRows] = {2, 3, 4, 5, 6};
byte colPins[numCols]= {10, 9, 8, 7};

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

String numstr = “”;

void setup(){
Serial.begin(9600);
Serial.println(“Setup”);
} // setup

void loop()
{
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY) {
// Serial.print(keypressed);
//lcd.setCursor(0,1);
Serial.println(“keypressed=” + (String)keypressed + " ");
switch (keypressed) {
case ‘1’:
numstr = "1 ";
break;
case ‘2’:
numstr = "2 ";
break;
case ‘3’:
numstr = "3 ";
break;
case ‘4’:
numstr = "4 ";
break;
case ‘5’:
numstr = "5 ";
break;
case ‘6’:
numstr = "6 ";
break;
case ‘7’:
numstr = "7 ";
break;
case ‘8’:
numstr = "9 ";
break;
case ‘0’:
numstr = "0 ";
break;
case ‘A’:
numstr = "F1 ";
break;
case ‘B’:
numstr = "F2 ";
break;
case ‘C’:
numstr = "ESC ";
break;
case ‘E’:
numstr = “ENTER”;
break;
case ‘D’:
numstr = "DOWN ";
break;
case ‘U’:
numstr = "UP ";
break;
case ‘R’:
numstr = "RIGHT ";
break;
case ‘L’:
numstr = "LEFT ";
break;
case '’:
numstr = " ";
break;
case ‘#’:
numstr = "# ";
break;

default:
break;
}

if(numstr !="") {
//lcd.setCursor(0,2);
Serial.println(“numstr=” + (String)numstr + " ");
}
}
} // loop

*/

//Programa : Teste teclado matricial 4x4
//Autor : FILIPEFLOP
 
void setupTeclado()
{
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
   
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
   
  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}
 
void loopTeclado()
{
    for (int ti = 3; ti<7; ti++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(8) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(8) == HIGH){}
    }
 
    //Verifica se alguma tecla da coluna 2 foi pressionada    
    if (digitalRead(9) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(9) == HIGH){};
    }
     
    //Verifica se alguma tecla da coluna 3 foi pressionada
    if (digitalRead(10) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(10) == HIGH){}
    }
     
    //Verifica se alguma tecla da coluna 4 foi pressionada
    if (digitalRead(11) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(11) == HIGH){} 
    }
   }
   delay(10);
}
 
void imprime_linha_coluna(int x, int y)
{
       Serial.print("Linha : ");
       Serial.print(x);
       Serial.print(" x Coluna : ");
       Serial.print(y);
       delay(10);
       Serial.println();
}