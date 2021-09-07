/* Include DigitLedDisplay Library */
#include "DigitLedDisplay.h"

/* Arduino Pin to Display Pin
   7 to DIN,
   6 to CS,
   5 to CLK */
DigitLedDisplay ld = DigitLedDisplay(7, 6, 5);

void wr( byte data, byte dsp)
{
  //ld.write(dsp, data);
  ld.printDigit(data,dsp);
}

void setup() {
  
  /* Set the brightness min:1, max:15 */
  ld.setBright(7);

  /* Set the digit count */
  ld.setDigitLimit(8); 
  ld.clear();
  ld.printDigit(12345678);
  delay(2000);
  ld.clear();
  setup1();
  
}
void cls()
{
  ld.clear();
}

void setBright1(){
  ld.setBright(5);
}
void lcdon(){
  ld.on();
}
void lcdoff(){
  ld.off();
}
