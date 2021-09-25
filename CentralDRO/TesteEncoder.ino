/*
static int pinA = PA8;
static int pinB = PA15;
volatile bool aFlag = 0;
volatile bool bFlag = 0;
volatile uint16_t encoderPos = 0;
volatile uint16_t oldEncPos = 0;
volatile uint16_t reading = 0;

void setupEncoder() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), PinA, RISING);
  attachInterrupt(digitalPinToInterrupt(pinB), PinB, RISING);
  Serial.begin(115200);
}

void PinA(){
  noInterrupts();
  reading = GPIOA->IDR & 0x3;
  if(reading == 0b0000000000000011 && aFlag && encoderPos) {
    encoderPos --;
    bFlag = 0;
    aFlag = 0;
  }else if (reading == 0b0000000000000001) bFlag = 1;
    interrupts();
}

void PinB(){
  noInterrupts();
  reading = GPIOA->IDR & 0x3;
  if (reading == 0b0000000000000011 && bFlag) {
    encoderPos ++;
    bFlag = 0;
    aFlag = 0;
  }else if (reading == 0b0000000000000010) aFlag = 1;
    interrupts();
}

void loopEncoder(){
  if(oldEncPos != encoderPos) {
    Serial.println(encoderPos);
    oldEncPos = encoderPos;
  }
}
*/
/*
In this example the rotary encoder connects to PA0, PA1 and GND
It also prevents the count going negative by making sure encoderPos is true.
I've included a screenshot to show it working. If you can't get it to work, check your setup and wiring.

Thank you Simon for your article, it inspired me!
*/ 
#include <stdint.h>

//-------| prototypes |------------
void EXTI1_IRQHandler(void);
void delayMS(uint16_t ms);
uint32_t val = 0;
uint32_t MSTICKS = 0;
void init_debug(void);

/* Sensor X in
 * PB15 and PA8
 */

//encoder functions
void init_interrupt_version(void);
void init_hardware_timer_version(void);

int mainold(void)
{
  char message[32];
 init_debug();

 //init_interrupt_version();
 init_hardware_timer_version();

 while(1)
 {
  
  //printMsg("d: %d\n",TIM4->CNT); // for Timer hardware version
  //printMsg("d: %d\n",val); // for interrupt version
  sprintf(message,"FF09100%05d0",TIM4->CNT);
  Serial1.print(message);
  delayMS(50);
 }

}
void init_hardware_timer_version(void)
{
 RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
 RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; //AFIO might not even be needed?

 //GPIO must be input floating which is default so no code to write for that

 // value to count up to : 16 bit so max is 0xFFFF = 65535
 TIM4->ARR = 0xFFFF;

 //per datasheet instructions
 TIM4->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  //step 1 and 2
 TIM4->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);  // step 3 and 4
 TIM4->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;   //step 5
 TIM4->CR1 |= TIM_CR1_CEN ;     //step 6
}
void init_interrupt_version(void)
{
   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
   EXTI->IMR |= 1<<1; //enable interrupt on EXTI-1
   EXTI->IMR |= 1; //enable interrupt on EXTI-1
   NVIC_EnableIRQ(EXTI1_IRQn); //enable the IRQ line that corresponds to EXT-1
   NVIC_EnableIRQ(EXTI0_IRQn); //enable the IRQ line that corresponds to EXT-1
   EXTI->RTSR |= 1<<1; //enable rising edge interrupt on line 1
   EXTI->FTSR |= 1; //enable rising edge interrupt on line 1
   AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI1_PB; // set interrupt to be on port B
   AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI0_PB; // set interrupt to be on port B
}

void EXTI1_IRQHandler(void)
{
 EXTI->PR |= 1<<1; //clear pending request interrupt flag
 if(GPIOB->IDR & 0x01) //high  on PB 0
 {
  val++;
 }
 else
 {
  val--;
 }
}
void EXTI0_IRQHandler(void)
{
 EXTI->PR |= 1<<1; //clear pending request interrupt flag
 if(GPIOB->IDR & 0x02) //if high  on PB 1
 {
  val++;
 }
 else
 {
  val--;
 }
}
void init_debug(void)
{
 SysTick_Config(SystemCoreClock /1000);
 /*
 printMsg_config_Type printer;
 printer.TX_pinNumber = 9;
 printer.Uart_instance = USART1;
 printer.tx_port = GPIOA;
 printMsg_init(printer);
 printMsg("Debug UART initialized | SystemCore Clock : %d", SystemCoreClock);
 */
}

void SysTick_Handler(void)
{
 MSTICKS++;
}

void delayMS(uint16_t ms)
{
 MSTICKS = 0;

 while(MSTICKS < ms);
}
