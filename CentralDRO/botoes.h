#ifndef __BOTOES_H__
#define __BOTOES_H__

#define VERSION 1.0.10

#define DIAMES 2706
#define ANO    2021 

#define LED_START_BUTTON    13
#define LED_STOP_BUTTON     A0
#define LED_REVERSE_BUTTON  A1
#define RELE_01             A2
#define RELE_02             A3

//Flags to button position in button_flags
#define BFLAG_START          0x01
#define BFLAG_STOP           0x02
#define BFLAG_REVERSE        0x04 
#define BFLAG_EMERGECY       0x08
//Port of buttons.
#define B_START_BUTTON        12
#define B_STOP_BUTTON         A5
#define B_REVERSE_BUTTON      A4
#define B_EMERGENCY_BUTTON    11 

#endif
