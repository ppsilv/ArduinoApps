EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
Title "Power Supply"
Date "2021-10-03"
Rev "PWR1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:LM7805_TO220 U200
U 1 1 6132AECF
P 5200 1750
F 0 "U200" H 5200 1992 50  0000 C CNN
F 1 "LM7805_TO220" H 5200 1901 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5200 1975 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 5200 1700 50  0001 C CNN
	1    5200 1750
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM317L_TO92 U201
U 1 1 6132BADD
P 6800 2500
F 0 "U201" H 6800 2742 50  0000 C CNN
F 1 "LM1117-3.3V" H 6800 2651 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6800 2725 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/snvs775k/snvs775k.pdf" H 6800 2500 50  0001 C CNN
	1    6800 2500
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C201
U 1 1 6132DCBF
P 4500 2250
F 0 "C201" H 4678 2296 50  0000 L CNN
F 1 "100nF" H 4678 2205 50  0000 L CNN
F 2 "" H 4500 2250 50  0001 C CNN
F 3 "~" H 4500 2250 50  0001 C CNN
	1    4500 2250
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C102
U 1 1 6132EFAE
P 5900 2250
F 0 "C102" H 6078 2296 50  0000 L CNN
F 1 "100nF" H 6078 2205 50  0000 L CNN
F 2 "" H 5900 2250 50  0001 C CNN
F 3 "~" H 5900 2250 50  0001 C CNN
	1    5900 2250
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C204
U 1 1 6132FBB2
P 7900 2900
F 0 "C204" H 8078 2946 50  0000 L CNN
F 1 "100nF" H 8078 2855 50  0000 L CNN
F 2 "" H 7900 2900 50  0001 C CNN
F 3 "~" H 7900 2900 50  0001 C CNN
	1    7900 2900
	1    0    0    -1  
$EndComp
$Comp
L pspice:C C203
U 1 1 6132FFCD
P 6800 3600
F 0 "C203" H 6978 3646 50  0000 L CNN
F 1 "10uF" H 6978 3555 50  0000 L CNN
F 2 "" H 6800 3600 50  0001 C CNN
F 3 "~" H 6800 3600 50  0001 C CNN
	1    6800 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C200
U 1 1 61330784
P 3950 2250
F 0 "C200" H 4068 2296 50  0000 L CNN
F 1 "100uF" H 4068 2205 50  0000 L CNN
F 2 "" H 3988 2100 50  0001 C CNN
F 3 "~" H 3950 2250 50  0001 C CNN
	1    3950 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C206
U 1 1 61330A8B
P 9000 2000
F 0 "C206" H 9118 2046 50  0000 L CNN
F 1 "100uF" H 9118 1955 50  0000 L CNN
F 2 "" H 9038 1850 50  0001 C CNN
F 3 "~" H 9000 2000 50  0001 C CNN
	1    9000 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C205
U 1 1 61331766
P 8500 2900
F 0 "C205" H 8618 2946 50  0000 L CNN
F 1 "100uF" H 8618 2855 50  0000 L CNN
F 2 "" H 8538 2750 50  0001 C CNN
F 3 "~" H 8500 2900 50  0001 C CNN
	1    8500 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1750 4500 1750
Wire Wire Line
	3450 4300 3950 4300
Wire Wire Line
	8500 4300 8500 3050
Wire Wire Line
	3950 2100 3950 1750
Connection ~ 3950 1750
Wire Wire Line
	4500 2000 4500 1750
Connection ~ 4500 1750
Wire Wire Line
	4500 1750 3950 1750
Wire Wire Line
	3950 2400 3950 4300
Connection ~ 3950 4300
Wire Wire Line
	3950 4300 4500 4300
Wire Wire Line
	4500 2500 4500 4300
Connection ~ 4500 4300
Wire Wire Line
	4500 4300 5200 4300
Wire Wire Line
	5200 2050 5200 4300
Connection ~ 5200 4300
Wire Wire Line
	5200 4300 5900 4300
Wire Wire Line
	5900 2500 5900 4300
Connection ~ 5900 4300
Wire Wire Line
	5500 1750 5900 1750
Wire Wire Line
	9000 1750 9000 1850
Wire Wire Line
	5900 2000 5900 1750
Connection ~ 5900 1750
Wire Wire Line
	5900 1750 6300 1750
Wire Wire Line
	6500 2500 6300 2500
Wire Wire Line
	6300 2500 6300 1750
Connection ~ 6300 1750
Wire Wire Line
	6300 1750 9000 1750
Wire Wire Line
	8500 2500 8500 2750
Wire Wire Line
	7900 2650 7900 2500
Connection ~ 7900 2500
Wire Wire Line
	7900 2500 8500 2500
Wire Wire Line
	7900 3150 7900 4300
Connection ~ 7900 4300
Wire Wire Line
	7900 4300 8500 4300
Wire Wire Line
	8500 4300 9000 4300
Wire Wire Line
	9000 4300 9000 2150
Connection ~ 8500 4300
Text GLabel 9450 1750 2    50   Input ~ 10
5,0V
Wire Wire Line
	9450 1750 9000 1750
Connection ~ 9000 1750
Text GLabel 9450 2500 2    50   Input ~ 10
3,3V
Wire Wire Line
	9450 2500 8500 2500
Connection ~ 8500 2500
Connection ~ 9000 4300
$Comp
L power:+12V #PWR0105
U 1 1 61340375
P 3950 1200
F 0 "#PWR0105" H 3950 1050 50  0001 C CNN
F 1 "+12V" H 3965 1373 50  0000 C CNN
F 2 "" H 3950 1200 50  0001 C CNN
F 3 "" H 3950 1200 50  0001 C CNN
	1    3950 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 1200 3950 1750
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 61341523
P 3950 1200
F 0 "#FLG0104" H 3950 1275 50  0001 C CNN
F 1 "PWR_FLAG" V 3950 1328 50  0000 L CNN
F 2 "" H 3950 1200 50  0001 C CNN
F 3 "~" H 3950 1200 50  0001 C CNN
	1    3950 1200
	0    1    1    0   
$EndComp
Connection ~ 3950 1200
Text GLabel 9400 4300 2    50   Input ~ 10
GND
Wire Wire Line
	9400 4300 9000 4300
Wire Wire Line
	5900 4300 6800 4300
Wire Wire Line
	6800 3850 6800 4300
Connection ~ 6800 4300
$Comp
L power:GNDREF #PWR?
U 1 1 613FF226
P 3450 4600
F 0 "#PWR?" H 3450 4350 50  0001 C CNN
F 1 "GNDREF" H 3455 4427 50  0000 C CNN
F 2 "" H 3450 4600 50  0001 C CNN
F 3 "" H 3450 4600 50  0001 C CNN
	1    3450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4600 3450 4300
Connection ~ 3450 4300
$Comp
L power:+3.3V #PWR?
U 1 1 614007D2
P 8500 2250
F 0 "#PWR?" H 8500 2100 50  0001 C CNN
F 1 "+3.3V" H 8515 2423 50  0000 C CNN
F 2 "" H 8500 2250 50  0001 C CNN
F 3 "" H 8500 2250 50  0001 C CNN
	1    8500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 614014D7
P 9000 1450
F 0 "#PWR?" H 9000 1300 50  0001 C CNN
F 1 "+5V" H 9015 1623 50  0000 C CNN
F 2 "" H 9000 1450 50  0001 C CNN
F 3 "" H 9000 1450 50  0001 C CNN
	1    9000 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1450 9000 1750
Wire Wire Line
	8500 2250 8500 2500
$Comp
L Connector:Screw_Terminal_01x02 J200
U 1 1 614038CA
P 3150 1850
F 0 "J200" H 3068 1525 50  0000 C CNN
F 1 "Power_12v" H 3068 1616 50  0000 C CNN
F 2 "" H 3150 1850 50  0001 C CNN
F 3 "~" H 3150 1850 50  0001 C CNN
	1    3150 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 1850 3350 1850
Wire Wire Line
	3450 1850 3450 4300
$Comp
L Analog_Switch:ADG417BR SW200A
U 1 1 61477179
P 2050 1750
F 0 "SW200A" H 2050 2000 50  0000 C CNN
F 1 "PowerSwitch" H 2050 1926 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2050 1650 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADG417.pdf" H 2050 1750 50  0001 C CNN
	1    2050 1750
	1    0    0    -1  
$EndComp
NoConn ~ 3350 1950
Wire Wire Line
	6800 2800 6800 3150
Wire Wire Line
	6800 4300 7350 4300
Wire Wire Line
	7100 2500 7900 2500
Text Notes 6400 2150 0    50   ~ 0
Not adj, it is 3,3V fixed
Wire Wire Line
	3350 1750 3950 1750
NoConn ~ 2050 1900
Wire Notes Line
	2350 1750 3100 1750
Wire Notes Line
	1200 1400 1200 2850
Wire Notes Line
	1200 2850 2450 2850
Wire Notes Line
	2450 2850 2450 1400
Wire Notes Line
	2450 1400 1200 1400
Text Notes 1400 1350 0    50   ~ 0
This key is place in front panel.
Wire Wire Line
	6800 3150 7350 3150
Wire Wire Line
	7350 3150 7350 4300
Connection ~ 6800 3150
Wire Wire Line
	6800 3150 6800 3350
Connection ~ 7350 4300
Wire Wire Line
	7350 4300 7900 4300
$Comp
L Analog_Switch:ADG417BR SW200B
U 1 1 61460ED3
P 2050 2500
F 0 "SW200B" H 2050 2750 50  0000 C CNN
F 1 "PowerSwitch" H 2050 2676 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2050 2400 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADG417.pdf" H 2050 2500 50  0001 C CNN
	1    2050 2500
	1    0    0    -1  
$EndComp
Wire Notes Line
	2300 2500 2800 2500
Wire Notes Line
	2800 2500 2800 1850
Wire Notes Line
	2800 1850 3150 1850
NoConn ~ 2050 2700
NoConn ~ 2350 2500
NoConn ~ 2350 1750
NoConn ~ 1750 1750
NoConn ~ 1750 2500
$EndSCHEMATC
