#ifndef __TACHOMETER_H__
#define __TACHOMETER_H__

#define SENSOR_HALL_PIN PA11

class CTachometer{
public:

  CTachometer();
  void loopTachometer();
  void Pulse_Event();
  void  writeRpm();
  
private:
const byte PulsesPerRevolution = 2;   // Set how many pulses there are on each revolution. Default: 2.
                                  // If the period between pulses is too high, or even if the pulses stopped, 
                                  // then we would get stuck showing the last value instead of a 0. Because 
                                  // of this we are going to set a limit for the maximum period allowed.
                                  // If the period is above this value, the RPM will show as 0.
                                  // The higher the set value, the longer lag/delay will have to sense that pulses 
                                  // stopped, but it will allow readings at very low RPM.
                                  // Setting a low value is going to allow the detection of stop situations faster, 
                                  // but it will prevent having low RPM readings.
                                  // The unit is in microseconds.
const unsigned long ZeroTimeout = 1200000;  // For high response time, a good value would be 100000.
                                  // For reading very low RPM, a good value would be 300000.
// Calibration for smoothing RPM:
static const byte numReadings = 2;  // Number of samples for smoothing. The higher, the more smoothing, 
                                    // but it's going to react slower to changes. 1 = no smoothing. Default: 2.

////////////
// Variables:
/////////////
volatile unsigned long LastTimeWeMeasured;  // Stores the last time we measured a pulse so we can calculate the period.
volatile unsigned long PeriodBetweenPulses;  // Stores the period between pulses in microseconds.
                                             // It has a big number so it doesn't start with 0 which would be interpreted as a high frequency.
volatile unsigned long PeriodAverage;  // Stores the period between pulses in microseconds in total, if we are taking multiple pulses.
                                       // It has a big number so it doesn't start with 0 which would be interpreted as a high frequency.
unsigned long FrequencyRaw;  // Calculated frequency, based on the period. This has a lot of extra decimals without the decimal point.
unsigned long FrequencyReal; // Frequency without decimals.
unsigned long RPM;  // Raw RPM without any processing.
unsigned int PulseCounter ;  // Counts the amount of pulse readings we took so we can average multiple pulses before calculating the period.
unsigned long PeriodSum; // Stores the summation of all the periods to do the average.
unsigned long LastTimeCycleMeasure ;// Stores the last time we measure a pulse in that cycle.
                                    // We need a variable with a value that is not going to be affected by the interrupt
                                    // because we are going to do math and functions that are going to mess up if the values
                                    // changes in the middle of the cycle.
unsigned long CurrentMicros; // Stores the micros in that cycle.
                             // We need a variable with a value that is not going to be affected by the interrupt
                             // because we are going to do math and functions that are going to mess up if the values
                             // changes in the middle of the cycle.

// We get the RPM by measuring the time between 2 or more pulses so the following will set how many pulses to
// take before calculating the RPM. 1 would be the minimum giving a result every pulse, which would feel very responsive
// even at very low speeds but also is going to be less accurate at higher speeds.
// With a value around 10 you will get a very accurate result at high speeds, but readings at lower speeds are going to be
// farther from eachother making it less "real time" at those speeds.
// There's a function that will set the value depending on the speed so this is done automatically.
unsigned int AmountOfReadings;
unsigned int ZeroDebouncingExtra;  // Stores the extra value added to the ZeroTimeout to debounce it.
                                   // The ZeroTimeout needs debouncing so when the value is close to the threshold it
                                   // doesn't jump from 0 to the value. This extra value changes the threshold a little
                                   // when we show a 0.

// Variables for smoothing tachometer:
unsigned long readings[numReadings];  // The input.
unsigned long readIndex;  // The index of the current reading.
unsigned long total;  // The running total.
unsigned long average;  // The RPM value after applying the smoothing.
  
};



extern CTachometer * vTachometer;

void extPulse_Event() {
  vTachometer->Pulse_Event();
}

#endif
