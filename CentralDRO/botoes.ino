
/*
 * The button status byte contain the status for all systema button.
 * 
 * buttonStatus = 0x00 -> all buttons not pressed the beginning state.
 *              = 0xFF -> invalid value because we have button that could not be on at the same time.
 *                0b00000000
 *                      ||||-> startButton status this button cannot be ON when button stop is in ON state.
 *                      |||--> stopButton and emergencyButton status when this button becames ON the 
 *                      ||     start button must be turned OFF and reverseButton should be turned off
 *                      ||---> reverseButton start button must be turned OFF
 *                      |----> Emergency button.
 *                
 *                
 *                
 *                
 *                
 *                
 * 
 */
#include "botoes.h"

unsigned char button_flags = 0x00;

unsigned long timerLedStart=micros();
unsigned char statusLedStart=0;

unsigned long timerLedStop=micros();
unsigned char statusLedStop=0;

unsigned long timerLedReverse=micros();
unsigned char statusLedReverse=0;

void button_setup()
{
  pinMode(LED_START_BUTTON, OUTPUT);
  pinMode(LED_STOP_BUTTON, OUTPUT);
  pinMode(LED_REVERSE_BUTTON, OUTPUT);  
  pinMode(RELE_01, OUTPUT);  
  pinMode(RELE_02, OUTPUT);  

  pinMode( B_START_BUTTON, INPUT_PULLUP);  
  pinMode( B_STOP_BUTTON, INPUT_PULLUP);  
  pinMode( B_REVERSE_BUTTON, INPUT_PULLUP);  
  pinMode( B_EMERGENCY_BUTTON, INPUT_PULLUP);  


  //Timer for leds
  timerLedStart=micros();
  timerLedStop=micros();
  timerLedReverse=micros();
}
void handleLedStart()
{
  Serial.println(button_flags, HEX);
  if( getStartButtonFlag() and getEmergencyButtonFlag() ){
   if( ( micros() - timerLedStart ) > 100000 ){
      if ( statusLedStart == 0 ){
        digitalWrite(LED_START_BUTTON, HIGH);
        statusLedStart = 1;        
      }else{
        digitalWrite(LED_START_BUTTON, LOW);
        statusLedStart = 0;
      }
      timerLedStart = micros();
   }
  }else{
      digitalWrite(LED_START_BUTTON, HIGH);
   }
} 
void handleLedStop()
{
  if( getStopButtonFlag() and getEmergencyButtonFlag() ){
   if( ( micros() - timerLedStop ) > 100000 ){
      if ( statusLedStop == 0 ){
        digitalWrite(LED_STOP_BUTTON, HIGH);
        statusLedStop = 1;        
      }else{
        digitalWrite(LED_STOP_BUTTON, LOW);
        statusLedStop = 0;
      }
      timerLedStop = micros();
   }
  }else{
      digitalWrite(LED_STOP_BUTTON, HIGH);
   }
}
void handleLedReverse()
{
  if( getReverseButtonFlag() and getEmergencyButtonFlag() ){
   if( ( micros() - timerLedReverse ) > 100000 ){
      if ( statusLedReverse == 0 ){
        digitalWrite(LED_REVERSE_BUTTON, HIGH);
        statusLedReverse = 1;        
      }else{
        digitalWrite(LED_REVERSE_BUTTON, LOW);
        statusLedReverse = 0;
      }
      timerLedReverse = micros();
   }
  }else{
      digitalWrite(LED_REVERSE_BUTTON, HIGH);
   }
}

//* START BUTTON
 
boolean getStartButtonFlag()
{
    if( button_flags & BFLAG_START ){
      return true;
    }
    return false;
}
void setStartButtonFlag()
{
   button_flags = button_flags | BFLAG_START;
}
void clearStartButtonFlag()
{
  button_flags = button_flags & (~BFLAG_START);
}
void readStartButton()
{
  int currentState = digitalRead(B_START_BUTTON);

  if ( getStartButtonFlag() == true && currentState == HIGH ){
    clearStopButtonFlag();
    clearReverseButtonFlag();
    setStartButtonFlag();
  }else if ( getStartButtonFlag() == false && currentState == HIGH ){
    clearStopButtonFlag();
    clearReverseButtonFlag();    
    setStartButtonFlag();
  }
}
// STOP BUTTON
 
boolean getStopButtonFlag()
{
    if( button_flags & BFLAG_STOP ){
      return true;
    }
    return false;
}
void setStopButtonFlag()
{
   button_flags = button_flags | BFLAG_STOP; 
}
void clearStopButtonFlag()
{
  button_flags = button_flags & (~BFLAG_STOP);
}
void readStopButton()
{
  int currentState = digitalRead(B_STOP_BUTTON);
  
  if ( getStopButtonFlag() == true && currentState == HIGH ){
    clearStopButtonFlag();
    clearReverseButtonFlag();
    setStopButtonFlag();
  }else if ( getStopButtonFlag() == false && currentState == HIGH ){
    clearStopButtonFlag();
    clearReverseButtonFlag();
    setStopButtonFlag();
  }
}

  //REVERSE BUTTON
 
boolean getReverseButtonFlag()
{
    if( button_flags & BFLAG_REVERSE ){
      return true;
    }
    return false;
}
void setReverseButtonFlag()
{
   button_flags = button_flags | BFLAG_REVERSE;
}
void clearReverseButtonFlag()
{
  button_flags = button_flags & (~BFLAG_REVERSE);
}
void readReverseButton()
{
  int currentState = digitalRead(B_REVERSE_BUTTON);
  
  if ( getReverseButtonFlag() == true && currentState == HIGH ){
    clearStopButtonFlag();
    clearStopButtonFlag();
    setReverseButtonFlag();
  }else if ( getReverseButtonFlag() == false && currentState == HIGH ){
    clearStopButtonFlag();
    clearStopButtonFlag();
    setReverseButtonFlag();
  }
}

//EMERGENCY BUTTON
//STOP BUTTON

boolean getEmergencyButtonFlag()
{
    if( button_flags & BFLAG_EMERGECY ){
      return true;
    }
    return false;
}
//inverted logic because the button is NO all others button are NC
void setEmergencyButtonFlag()
{
  clearStartButtonFlag();
  clearStopButtonFlag();
  clearReverseButtonFlag();  
  button_flags = button_flags | BFLAG_EMERGECY;
}
void clearEmergencyButtonFlag()
{
  clearStartButtonFlag();
  clearStopButtonFlag();
  clearReverseButtonFlag();  
  button_flags = button_flags  & (~BFLAG_EMERGECY);
}
void readEmergencyButton()
{
  int currentState = digitalRead(B_EMERGENCY_BUTTON);
  
  if ( getEmergencyButtonFlag() == true && currentState == LOW ){
    Serial.println("Emergency estava true vai ficar false");
    clearEmergencyButtonFlag();
  }else if ( getEmergencyButtonFlag() == false && currentState == HIGH ){
    Serial.println("Emergency estava false vai ficar true");
    setEmergencyButtonFlag();
  }
}

void handleButtons()
{
  readStartButton();
  readStopButton();
  readReverseButton();
  readEmergencyButton();
}

void hadleOutputs()
{
  if( getEmergencyButtonFlag() == false ){
    digitalWrite(RELE_01, LOW);
    digitalWrite(RELE_02, LOW);
    //Todo
    //Write Emercency button on display
    //writeInteger(5000);
    return;  
  }
  if( getStartButtonFlag() == true ){
    //clearStopButtonFlag();
    //clearReverseButtonFlag();
    digitalWrite(RELE_01, HIGH); 
  }
  if( getStopButtonFlag() == true ){
    clearStartButtonFlag();
    clearReverseButtonFlag();
    digitalWrite(RELE_01, LOW);
    digitalWrite(RELE_02, LOW);
  }
  if( getReverseButtonFlag() == true ){
    clearStartButtonFlag();
    clearStopButtonFlag();
    digitalWrite(RELE_02, HIGH);    
  }
}
