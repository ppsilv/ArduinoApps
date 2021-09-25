#ifndef __TIMER_H__
#define __TIMER_H__



class C_timer
{

  public:
      C_timer(int duration){
        this->duration = duration;
        lastTimerTimeout = millis();
      }
      boolean isTimeout(){
        if( ( millis() - lastTimerTimeout ) > duration ){
          lastTimerTimeout = millis();
          return true;
        }
        return false;
      }
  private:
  int duration;
  int lastTimerTimeout;
};

#endif
