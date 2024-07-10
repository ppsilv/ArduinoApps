EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:USB_B_Micro J400
U 1 1 6131787D
P 2050 2550
F 0 "J400" H 2107 3017 50  0000 C CNN
F 1 "USB_B_Micro" H 2107 2926 50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 2107 2925 50  0001 C CNN
F 3 "~" H 2200 2500 50  0001 C CNN
	1    2050 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BCE Q400
U 1 1 61318E91
P 3850 2550
F 0 "Q400" H 4041 2596 50  0000 L CNN
F 1 "bc337" H 4041 2505 50  0000 L CNN
F 2 "" H 4050 2650 50  0001 C CNN
F 3 "~" H 3850 2550 50  0001 C CNN
	1    3850 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BCE Q401
U 1 1 61319DC2
P 4900 3500
F 0 "Q401" H 5091 3546 50  0000 L CNN
F 1 "bc337" H 5091 3455 50  0000 L CNN
F 2 "" H 5100 3600 50  0001 C CNN
F 3 "~" H 4900 3500 50  0001 C CNN
	1    4900 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R401
U 1 1 6131A7B4
P 3950 1950
F 0 "R401" H 4020 1996 50  0000 L CNN
F 1 "4k5" H 4020 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 3880 1950 50  0001 C CNN
F 3 "~" H 3950 1950 50  0001 C CNN
	1    3950 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R403
U 1 1 6131AD41
P 5000 3000
F 0 "R403" H 5070 3046 50  0000 L CNN
F 1 "4k7" H 5070 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4930 3000 50  0001 C CNN
F 3 "~" H 5000 3000 50  0001 C CNN
	1    5000 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R400
U 1 1 6131B1CB
P 3300 2550
F 0 "R400" V 3093 2550 50  0000 C CNN
F 1 "1k" V 3184 2550 50  0000 C CNN
F 2 "Resistor_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 3230 2550 50  0001 C CNN
F 3 "~" H 3300 2550 50  0001 C CNN
	1    3300 2550
	0    1    1    0   
$EndComp
$Comp
L Device:R R402
U 1 1 6131B698
P 4350 3500
F 0 "R402" V 4143 3500 50  0000 C CNN
F 1 "1k" V 4234 3500 50  0000 C CNN
F 2 "Resistor_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4280 3500 50  0001 C CNN
F 3 "~" H 4350 3500 50  0001 C CNN
	1    4350 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 2550 3150 2550
Wire Wire Line
	3450 2550 3650 2550
Wire Wire Line
	3950 2350 3950 2300
Wire Wire Line
	4500 3500 4700 3500
Wire Wire Line
	5000 3300 5000 3200
Wire Wire Line
	3950 1500 5000 1500
Wire Wire Line
	5000 1500 5000 2850
Wire Wire Line
	3950 1500 3950 1800
Wire Wire Line
	3950 2750 3950 4350
Wire Wire Line
	3950 4350 5000 4350
Wire Wire Line
	5000 4350 5000 3700
Wire Wire Line
	2350 2650 3300 2650
Wire Wire Line
	3300 2650 3300 3500
Wire Wire Line
	3300 3500 4200 3500
Connection ~ 3950 2300
Wire Wire Line
	3950 2300 3950 2100
Connection ~ 5000 3200
Wire Wire Line
	5000 3200 5000 3150
$Comp
L power:GNDREF #PWR0101
U 1 1 61322DC0
P 2350 4800
F 0 "#PWR0101" H 2350 4550 50  0001 C CNN
F 1 "GNDREF" H 2355 4627 50  0000 C CNN
F 2 "" H 2350 4800 50  0001 C CNN
F 3 "" H 2350 4800 50  0001 C CNN
	1    2350 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2750 2350 4350
Wire Wire Line
	3950 4350 2350 4350
Connection ~ 3950 4350
Text GLabel 5900 1600 2    50   Input ~ 10
3,3V
Text GLabel 10200 4350 2    50   Input ~ 10
GND
Connection ~ 5000 4350
Wire Wire Line
	5900 1600 2950 1600
Wire Wire Line
	2950 1600 2950 2350
NoConn ~ 2050 2950
NoConn ~ 1950 2950
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 6133D3F7
P 2350 4800
F 0 "#FLG0101" H 2350 4875 50  0001 C CNN
F 1 "PWR_FLAG" V 2350 4928 50  0000 L CNN
F 2 "" H 2350 4800 50  0001 C CNN
F 3 "~" H 2350 4800 50  0001 C CNN
	1    2350 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 4800 2350 4350
Connection ~ 2350 4800
Connection ~ 2350 4350
Wire Wire Line
	2350 2350 2950 2350
$Comp
L MCU_Microchip_ATmega:ATmega8-16AU U400
U 1 1 613446FA
P 8550 2600
F 0 "U400" H 9000 1250 50  0000 C CNN
F 1 "ATmega8-16AU" H 9100 4000 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 8550 2600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2486-8-bit-avr-microcontroller-atmega8_l_datasheet.pdf" H 8550 2600 50  0001 C CNN
	1    8550 2600
	-1   0    0    -1  
$EndComp
Text GLabel 10200 800  2    50   Input ~ 10
5,0V
Wire Wire Line
	10200 800  8550 800 
Wire Wire Line
	8550 800  8550 1200
Wire Wire Line
	8550 800  8450 800 
Wire Wire Line
	8450 800  8450 1200
Connection ~ 8550 800 
Wire Wire Line
	8450 4000 8450 4350
Wire Wire Line
	5000 4350 8450 4350
Connection ~ 8450 4350
Wire Wire Line
	8450 4350 8550 4350
Wire Wire Line
	8550 4000 8550 4350
Connection ~ 8550 4350
Wire Wire Line
	8550 4350 10200 4350
Wire Wire Line
	7950 2200 6000 2200
Wire Wire Line
	6000 2200 6000 2300
Wire Wire Line
	3950 2300 6000 2300
Wire Wire Line
	7950 2300 6050 2300
Wire Wire Line
	6050 2300 6050 3200
Wire Wire Line
	5000 3200 6050 3200
NoConn ~ 7950 1500
NoConn ~ 7950 1600
NoConn ~ 7950 1700
NoConn ~ 7950 1800
NoConn ~ 7950 1900
NoConn ~ 7950 2000
NoConn ~ 7950 2400
NoConn ~ 7950 2500
NoConn ~ 7950 2600
NoConn ~ 7950 2700
NoConn ~ 7950 2900
NoConn ~ 7950 3000
NoConn ~ 7950 3100
NoConn ~ 7950 3200
NoConn ~ 7950 3300
NoConn ~ 7950 3400
NoConn ~ 7950 3500
NoConn ~ 7950 3600
NoConn ~ 9150 1500
NoConn ~ 9150 1700
NoConn ~ 9150 1900
NoConn ~ 9150 2100
NoConn ~ 9150 2300
NoConn ~ 9150 2400
$Comp
L Connector:USB_B_Micro J?
U 1 1 613CAC01
P 3200 -300
F 0 "J?" H 3257 167 50  0000 C CNN
F 1 "USB_B_Micro" H 3257 76  50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 3257 75  50  0001 C CNN
F 3 "~" H 3350 -350 50  0001 C CNN
	1    3200 -300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
