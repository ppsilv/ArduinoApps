#ifndef __RDO_AXIS_Y_H__
#define __RDO_AXIS_Y_H__

#define YSENSOR_PWR_ON  PB14
#define Y_RESET_KEY     PC14

void extGate_ISR();
void extClock_ISR();
extern void beep(unsigned char b);

class CDroy
{
  public:

    CDroy(int gate, int data, int clk) {
      this->gate = gate;  //PB10
      this->data = data;  //PB15
      this->clk = clk; //PA8
      yFlags = 0;
      yValue = 0;
      ySign  = 1;
      bitsLidos = 0;
      gate_status = 1;
      value       = 0;
      interrupt_time = 0;
      last_interrupt_time = 0;
      pinMode(gate, INPUT_PULLUP);
      pinMode(clk, INPUT_PULLUP);
      pinMode(Y_RESET_KEY, INPUT_PULLUP);
      pinMode(YSENSOR_PWR_ON, OUTPUT);
      digitalWrite(YSENSOR_PWR_ON, HIGH);
      delay(1000);
      attachInterrupt(digitalPinToInterrupt(gate), extGate_ISR, CHANGE );
      attachInterrupt(digitalPinToInterrupt(clk), extClock_ISR, RISING );
      digitalWrite(YSENSOR_PWR_ON, LOW);
    }
    void yResetKey(){
      int key;
      key = digitalRead(Y_RESET_KEY);
      if ( key == LOW) {
        if ((millis() - lastDebounceTime) > 500) {
            digitalWrite(YSENSOR_PWR_ON, HIGH);
            beep(500);
            digitalWrite(YSENSOR_PWR_ON, LOW);
        }
        lastDebounceTime = millis();
      }  
    }
    int getValue() {
      if ( gate_status == 1 )
        return yValue;
    }
    int getSign() {
      return ySign;
    }
    void printY() {
      int vlr = yValue;
      if ( vlr == 0 )
        sprintf(str, "FF10200%03d%02d12", vlr / 100, vlr % 100);
      else
        sprintf(str, "FF10200%03d%02d%d2", vlr / 100, vlr % 100, this->getSign());
      Serial1.print(str);
    }
    char getSignSignal() {
      return (ySign == 1 ? '+' : '-');
    }
    void printFlags() {
      char str[32];
      sprintf(str, " %04X ", yFlags);
      Serial1.print(str);
    }
    inline void Clock_ISR() {
      if ( gate_status == 0 ) {
        value |= (digitalRead(data) << bitsLidos);
        bitsLidos++;
      }
      if (bitsLidos > 23) {
        yValue = (value & 0x00FFFF); //-5;
        yFlags = (value & 0x00FF0000) >> 16;
        if ( yFlags && 0x10 ) {
          ySign = 1;  // Show "+"
        } else {
          ySign = 0;  // Show "-"
        }
      }
    }

    inline void Gate_ISR() {
      last_interrupt_time = 0;
      interrupt_time = millis();

      // If interrupts come faster than 14, assume it's a bounce and ignore
      if (interrupt_time - last_interrupt_time > 1)
      {
        if ( digitalRead(gate) == 1 ) {
          gate_status = 1;
          bitsLidos = 0;
          value = 0;
        }
        else {
          gate_status = 0;
        }
      }
      last_interrupt_time = interrupt_time;
    }
  private:
    int gate;  //PB10
    int data;  //PB15
    int clk; //PA8
    //Registers
    int yFlags;
    int yValue;
    int ySign;
    //Controllers
    int bitsLidos;
    unsigned char gate_status;
    long value;
    unsigned long interrupt_time, last_interrupt_time;
    char str[32];
    int lastDebounceTime=millis();
};

extern CDroy * vDroy;

void extGate_ISR() {
  vDroy->Gate_ISR();
}
void extClock_ISR() {
  vDroy->Clock_ISR();
}

#endif
