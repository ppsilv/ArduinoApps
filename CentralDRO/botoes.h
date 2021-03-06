#ifndef __BOTOES_H__
#define __BOTOES_H__

#define VERSION 1.0.20

#define DIAMES 0310
#define ANO    2021 

#define LED_START_BUTTON    PB12
#define LED_STOP_BUTTON     PB5
#define LED_REVERSE_BUTTON  PB4
#define RELAYS              PA15
#define RUN_BACKWARD        PB3
#define RUN_FORWARD         PA12
#define RELE_01             RUN_FORWARD
#define RELE_02             RUN_BACKWARD


//Port of buttons.
#define B_START_BUTTON        PB9
#define B_STOP_BUTTON         PB8
#define B_REVERSE_BUTTON      PB13
#define B_EMERGENCY_BUTTON    PB11 


//Flags to button position in button_flags
#define BFLAG_START          0x01
#define BFLAG_STOP           0x02
#define BFLAG_REVERSE        0x04 
#define BFLAG_EMERGECY       0x08

#endif
