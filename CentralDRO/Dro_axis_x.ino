/*
 * https://create.arduino.cc/projecthub/PracticeMakesBetter/do-it-yourself-digital-read-out-86e2d5?ref=platform&ref_id=424_trending___&offset=6.........More
 */
// X Axis Sketch 
/*


// James Rovere 2019 Z Axis
// A Digital Readout using a quaduture rotary encoder,an IC2 LCD display
// and a GT2-16 pulley, 16 teeth spaced 2 mm apart; .37" outside Diameter.
#include <Encoder.h>// Encoder library.
Encoder myEnc(2,3);// Connected to Digital pins 2 and 3.


void setupAxisX() {
  
}
long oldPosition = -999;
void loopAxisX() {
  const float Wv = (.1 * PI) / 600; // Math formula for .37" diameter pulley
                                    //and 600 pulse/revolution encoder.
  
  Serial1.print("Z Axis");
  
  Serial1.print("inch");
 
  Serial1d.print("mm");
 
  Serial1.print("<->");// Graphic symbols for a Z axis left and right travel.
  long newPosition = myEnc.read();
  if (newPosition != oldPosition)

  Serial1.print (newPosition); // Display number of pulses, 1"~=1902.2 pulses.                       

  Serial1.print(Wv * newPosition, 3);//Math formula * Encoder reading ,3 decimals

  Serial1.print("|");// Graphic symbol to separate imperial and metric display.

  Serial1.print("|");

  Serial1.print(Wv * newPosition * 25.4, 2); // Formula to convert imperial
                                         // and metric, 2 decimals.
                                         
}
*/
