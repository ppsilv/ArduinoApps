#ifndef __RDO_AXIS_Y_H__
#define __RDO_AXIS_Y_H__

void extGate_ISR();
void extClock_ISR();

class CDroy
{
  public:
  
  CDroy(int gate,int data,int clk){
    this->gate = gate;  //PB10
    this->data = data;  //PB15
    this->clk= clk; //PA8
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

    attachInterrupt(digitalPinToInterrupt(gate), extGate_ISR, CHANGE ); 
    attachInterrupt(digitalPinToInterrupt(clk), extClock_ISR, RISING );        
  }
  int getValue(){
    if( gate_status == 1 )
      return yValue;    
  }

  bool isSignPositive(){
    return (ySign==1 ? true:false);
  }

  inline void Clock_ISR(){
    if( gate_status == 0 ){
      value |= (digitalRead(data)<<bitsLidos);
      bitsLidos++;    
    }
    if(bitsLidos > 23){
      yValue = (value&0x00FFFF);//-5;
      yFlags = (value&0x00FF0000)>>16;
      if( yFlags && 0x20 ){
        ySign = 1;  // Show "+"  
      }else{
        ySign = 0;  // Show "-"  
      }
    }
  }

  inline void Gate_ISR(){
    last_interrupt_time = 0;
    interrupt_time = millis();
    
    // If interrupts come faster than 14, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 1) 
    {
        if( digitalRead(gate) == 1 ){
          gate_status = 1;
          bitsLidos = 0;
          value = 0;
        }
        else{
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
  
};

extern CDroy * vDroy;

void extGate_ISR(){
  vDroy->Gate_ISR();
}
void extClock_ISR(){
  vDroy->Clock_ISR();
}

#endif
