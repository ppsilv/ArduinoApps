#ifndef __RDO_AXIS_X_H__
#define __RDO_AXIS_X_H__


#define X_RESET_KEY PB0

extern void beep(unsigned char b);

class CDrox
{
public:
      CDrox(){
       //Setup for X sensor
       RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
       RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; //AFIO might not even be needed?
      
       // value to count up to : 16 bit so max is 0xFFFF = 65535
       TIM4->ARR = 0xFFFF;
      
       //per datasheet instructions
       TIM4->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  //step 1 and 2
       TIM4->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);  // step 3 and 4
       TIM4->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;   //step 5
       TIM4->CR1 |= TIM_CR1_CEN ;     //step 6   
       pinMode(PB6, INPUT_PULLUP);
       pinMode(PB7, INPUT_PULLUP);
       pinMode(X_RESET_KEY, INPUT_PULLUP);
       xSign = 1;      
      }

      void xResetKey(){
        int key;
        key = digitalRead(X_RESET_KEY);
        if ( key == LOW ) {
          if ((millis() - lastDebounceTime) > 500) {
              TIM4->CNT = 0;
              beep(500);
          }
          lastDebounceTime = millis();
        }
      }
      void printX(){
        unsigned int vlr =TIM4->CNT;

        if ( vlr > 32767 ){
          vlr = 65535 - vlr;
          xSign = 0;
        }else{
          xSign = 1;
        }
        vlr = (vlr * Wvmm)*100;
        if( vlr == 0 )
          sprintf(str,"FF10100%03d%02d12",vlr/100,vlr%100);
        else  
          sprintf(str,"FF10100%03d%02d%d2",vlr/100,vlr%100,this->getSign());        
        Serial1.print(str); 
/*      
        Serial1.print(" ");
        Serial1.print(" Counter...: ");
        Serial1.print(TIM4->CNT );
        Serial1.print(" mm........: ");
        Serial1.print(TIM4->CNT * Wvmm ,3);
        Serial1.print(" Inchs.....: ");
        Serial1.println(TIM4->CNT * Wvpol,3);
 */
      
      }
      int getSign(){
        return (xSign==1 ? 1:0);
      }

private:
const float Wvpol = (.126 * PI) / 600;
const float Wvmm  = (3.199896217262 * PI) / 600;
int xSign = 1;
char str[32];
int lastDebounceTime=millis();
};


extern CDrox * vDrox;

#endif 
