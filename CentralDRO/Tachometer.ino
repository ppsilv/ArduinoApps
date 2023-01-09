/*
 * At the moment of this project I was so lazy, then I copied this code from InterlinkKnight
 * below you have the youtybe address for his video.
 * 
 * Paulo Silva 2021.
 * 
Tachometer using micros

On this sketch we are going to measure the period between pulses using the micros() function to get the RPM
(Revolutions Per Minute) from a sensor on pin 2.
This way of measuring RPM makes it accurate, responsive and versatile. No matter how fast or slow the loop is
running, the reading accuracy is not going to be affected. Although, the faster you run the loop, the more amount
of readings you are going to be able to display every second.

It's coded in a way that the micros rollover doesn't create glitches every 71 minutes, so it can run forever
without problems.

We use an interrupt for the input so you have to choose pin 2 or 3 (for Arduino Uno/nano). In this example we
use pin 2.

/////// OLED 0.96" Display:
We are going to use the OLED 128x64 I2C with SSD1306 driver using the Adafruit library.

Pins for OLED display and arduino uno/nano:
 * GND = GND
 * VCC = 5V
 * SCL = A5
 * SDA = A4

It's a good idea to put a resistor between A4-5V and A5-5V to help stabilize the connection.
What that does is pull-up the I2C pins to make it more reliable and prevents lock-ups.

Libraries needed for the OLED display:
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library

This sketch was made for my video tutorial shown here: https://www.youtube.com/watch?v=u2uJMJWsfsg

Made by InterlinkKnight
Last update: 05/23/2019
*/
#include "Tachometer.h"
#include "botoes.h"
CTachometer * vTachometer;

CTachometer::CTachometer()
{
  PeriodBetweenPulses = ZeroTimeout+1000;    
  PeriodAverage = ZeroTimeout+1000;          
  PulseCounter = 1;                          
  LastTimeCycleMeasure = LastTimeWeMeasured; 
  CurrentMicros = micros();                  
  AmountOfReadings = 1;
  average = 0;
  
  attachInterrupt(digitalPinToInterrupt(SENSOR_HALL_PIN), extPulse_Event, RISING);  // Enable interruption pin 2 when going from LOW to HIGH.

  delay(1000);  // We sometimes take several readings of the period to average. Since we don't have any readings
                // stored we need a high enough value in micros() so if divided is not going to give negative values.
                // The delay allows the micros() to be high enough for the first few cycles.
  
}  // End of setup.





void CTachometer::loopTachometer()
{

  LastTimeCycleMeasure = LastTimeWeMeasured;  // Store the LastTimeWeMeasured in a variable.
  CurrentMicros = micros();  // Store the micros() in a variable.
  if(CurrentMicros < LastTimeCycleMeasure)
  {
    LastTimeCycleMeasure = CurrentMicros;
  }
  FrequencyRaw = 10000000000 / PeriodAverage;  // Calculate the frequency using the period between pulses.
  if(PeriodBetweenPulses > ZeroTimeout - ZeroDebouncingExtra || CurrentMicros - LastTimeCycleMeasure > ZeroTimeout - ZeroDebouncingExtra)
  {  // If the pulses are too far apart that we reached the timeout for zero:
    FrequencyRaw = 0;  // Set frequency as 0.
    ZeroDebouncingExtra = 2000;  // Change the threshold a little so it doesn't bounce.
  }
  else
  {
    ZeroDebouncingExtra = 0;  // Reset the threshold to the normal value so it doesn't bounce.
  }
  FrequencyReal = FrequencyRaw / 10000;  // Get frequency without decimals.
                                          // This is not used to calculate RPM but we remove the decimals just in case
                                          // you want to print it.

  // Calculate the RPM:
  RPM = FrequencyRaw / PulsesPerRevolution * 60;  // Frequency divided by amount of pulses per revolution multiply by
                                                  // 60 seconds to get minutes.
  RPM = RPM / 10000;  // Remove the decimals.
  // Smoothing RPM:
  total = total - readings[readIndex];  // Advance to the next position in the array.
  readings[readIndex] = RPM;  // Takes the value that we are going to smooth.
  total = total + readings[readIndex];  // Add the reading to the total.
  readIndex = readIndex + 1;  // Advance to the next position in the array.

  if (readIndex >= numReadings){  // If we're at the end of the array:
    readIndex = 0;  // Reset array index.
  }
  // Calculate the average:
  average = total;//- / numReadings;  // The average value it's the smoothed result.

//Chamara a func para escrever no display
//writeInteger(average);
}  // End of loop.

void  CTachometer::writeRpm(){
      char str[32];
      unsigned long vlr = average;
      sprintf(str, "FF10300%03d%02d12", vlr / 100, vlr % 100);
      Serial1.print(str);  
}
 
void CTachometer::Pulse_Event()  // The interrupt runs this to calculate the period between pulses:
{

  PeriodBetweenPulses = micros() - LastTimeWeMeasured;  // Current "micros" minus the old "micros" when the last pulse happens.
                                                        // This will result with the period (microseconds) between both pulses.
                                                        // The way is made, the overflow of the "micros" is not going to cause any issue.

  LastTimeWeMeasured = micros();  // Stores the current micros so the next time we have a pulse we would have something to compare with.





  if(PulseCounter >= AmountOfReadings)  // If counter for amount of readings reach the set limit:
  {
    PeriodAverage = PeriodSum / AmountOfReadings;  // Calculate the final period dividing the sum of all readings by the
                                                   // amount of readings to get the average.
    PulseCounter = 1;  // Reset the counter to start over. The reset value is 1 because its the minimum setting allowed (1 reading).
    PeriodSum = PeriodBetweenPulses;  // Reset PeriodSum to start a new averaging operation.


    // Change the amount of readings depending on the period between pulses.
    // To be very responsive, ideally we should read every pulse. The problem is that at higher speeds the period gets
    // too low decreasing the accuracy. To get more accurate readings at higher speeds we should get multiple pulses and
    // average the period, but if we do that at lower speeds then we would have readings too far apart (laggy or sluggish).
    // To have both advantages at different speeds, we will change the amount of readings depending on the period between pulses.
    // Remap period to the amount of readings:
    int RemapedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);  // Remap the period range to the reading range.
    // 1st value is what are we going to remap. In this case is the PeriodBetweenPulses.
    // 2nd value is the period value when we are going to have only 1 reading. The higher it is, the lower RPM has to be to reach 1 reading.
    // 3rd value is the period value when we are going to have 10 readings. The higher it is, the lower RPM has to be to reach 10 readings.
    // 4th and 5th values are the amount of readings range.
    RemapedAmountOfReadings = constrain(RemapedAmountOfReadings, 1, 10);  // Constrain the value so it doesn't go below or above the limits.
    AmountOfReadings = RemapedAmountOfReadings;  // Set amount of readings as the remaped value.
  }
  else
  {
    PulseCounter++;  // Increase the counter for amount of readings by 1.
    PeriodSum = PeriodSum + PeriodBetweenPulses;  // Add the periods so later we can average.
  }

}  // End of Pulse_Event.
