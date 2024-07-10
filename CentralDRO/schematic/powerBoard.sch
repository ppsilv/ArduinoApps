EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title "External Power Board"
Date "2021-10-03"
Rev "PWRBRD2.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Relay:DIPxx-1Axx-11x Relay400
U 1 1 61492258
P 6300 2100
F 0 "Relay400" H 6630 2146 50  0000 L CNN
F 1 "12V" H 6630 2055 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 6650 2050 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 6300 2100 50  0001 C CNN
	1    6300 2100
	1    0    0    -1  
$EndComp
$Comp
L Relay:DIPxx-1Axx-11x Relay401
U 1 1 61493E1C
P 6900 3000
F 0 "Relay401" H 6750 3400 50  0000 L CNN
F 1 "12V" H 6800 2700 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 7250 2950 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 6900 3000 50  0001 C CNN
	1    6900 3000
	1    0    0    -1  
$EndComp
$Comp
L Isolator:CNY17-1 U400
U 1 1 614948B2
P 5650 3700
F 0 "U400" H 5650 4025 50  0000 C CNN
F 1 "CNY17-1" H 5650 3934 50  0000 C CNN
F 2 "" H 5650 3700 50  0001 L CNN
F 3 "http://www.vishay.com/docs/83606/cny17.pdf" H 5650 3700 50  0001 L CNN
	1    5650 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 61499947
P 6050 4300
F 0 "#PWR?" H 6050 4050 50  0001 C CNN
F 1 "GNDREF" H 6055 4127 50  0000 C CNN
F 2 "" H 6050 4300 50  0001 C CNN
F 3 "" H 6050 4300 50  0001 C CNN
	1    6050 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3700 6100 3700
Wire Wire Line
	5950 3800 6050 3800
Wire Wire Line
	6050 3800 6050 4050
Wire Wire Line
	5350 3800 5200 3800
Wire Wire Line
	5200 3800 5200 4050
Wire Wire Line
	5200 4050 6050 4050
Connection ~ 6050 4050
Wire Wire Line
	6050 4050 6050 4300
Text GLabel 4900 3600 0    50   Input ~ 0
Relays_ON
Wire Wire Line
	5350 3600 4900 3600
$Comp
L Connector:Screw_Terminal_01x02 J400
U 1 1 614AABEB
P 9550 1100
F 0 "J400" H 9630 1092 50  0000 L CNN
F 1 "220V_FROM_MAIN" H 9630 1001 50  0000 L CNN
F 2 "" H 9550 1100 50  0001 C CNN
F 3 "~" H 9550 1100 50  0001 C CNN
	1    9550 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J401
U 1 1 614AB667
P 9550 2450
F 0 "J401" H 9630 2442 50  0000 L CNN
F 1 "220V_TO_INVERTER" H 9630 2351 50  0000 L CNN
F 2 "" H 9550 2450 50  0001 C CNN
F 3 "~" H 9550 2450 50  0001 C CNN
	1    9550 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 1800 6500 1100
Wire Wire Line
	6500 1100 9350 1100
Wire Wire Line
	6500 2400 6500 2450
Wire Wire Line
	6500 2450 9350 2450
$Comp
L Connector:Screw_Terminal_01x02 J402
U 1 1 614AFEB1
P 5250 1200
F 0 "J402" H 5168 875 50  0000 C CNN
F 1 "220V_TO_12V_POWER" H 5168 966 50  0000 C CNN
F 2 "" H 5250 1200 50  0001 C CNN
F 3 "~" H 5250 1200 50  0001 C CNN
	1    5250 1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 1100 5450 1100
Connection ~ 6500 1100
$Comp
L Connector:Screw_Terminal_01x02 J403
U 1 1 614B3176
P 3600 1200
F 0 "J403" H 3518 875 50  0000 C CNN
F 1 "12V_POWER" H 3518 966 50  0000 C CNN
F 2 "" H 3600 1200 50  0001 C CNN
F 3 "~" H 3600 1200 50  0001 C CNN
	1    3600 1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 4350 6100 4250
Wire Wire Line
	5650 1650 6100 1650
Wire Wire Line
	6100 1650 6100 1800
Wire Wire Line
	3800 1100 4150 1100
Wire Wire Line
	4500 1100 4500 1650
Wire Wire Line
	4500 1650 5650 1650
Connection ~ 5650 1650
$Comp
L power:GNDREF #PWR?
U 1 1 614B52A3
P 3900 1450
F 0 "#PWR?" H 3900 1200 50  0001 C CNN
F 1 "GNDREF" H 3905 1277 50  0000 C CNN
F 2 "" H 3900 1450 50  0001 C CNN
F 3 "" H 3900 1450 50  0001 C CNN
	1    3900 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 1200 3900 1200
Wire Wire Line
	3900 1200 3900 1450
$Comp
L power:+12V #PWR?
U 1 1 614B6553
P 4150 850
F 0 "#PWR?" H 4150 700 50  0001 C CNN
F 1 "+12V" H 4165 1023 50  0000 C CNN
F 2 "" H 4150 850 50  0001 C CNN
F 3 "" H 4150 850 50  0001 C CNN
	1    4150 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 850  4150 1100
Connection ~ 4150 1100
Wire Wire Line
	4150 1100 4500 1100
Text GLabel 4600 1100 2    50   Input ~ 0
12V
Wire Wire Line
	4600 1100 4500 1100
Connection ~ 4500 1100
Text Notes 2400 1200 0    89   ~ 0
From DRO box
Wire Wire Line
	5450 1200 7100 1200
Wire Wire Line
	5650 1650 5650 2600
Wire Wire Line
	6100 3400 6250 3400
Wire Wire Line
	6700 3400 6700 3300
Connection ~ 7100 1200
Wire Wire Line
	7100 1200 9350 1200
Wire Wire Line
	7450 2550 7450 3450
Wire Wire Line
	7450 3450 7100 3450
Wire Wire Line
	7100 3450 7100 3300
Wire Wire Line
	7100 1200 7100 2700
Wire Wire Line
	6700 2600 6700 2700
Wire Wire Line
	5650 2600 6700 2600
Wire Wire Line
	6100 2400 6100 3400
Wire Wire Line
	6100 3700 6100 3400
Connection ~ 6100 3400
Wire Wire Line
	7450 2550 9350 2550
$Comp
L Diode:1N4148 D?
U 1 1 616CD348
P 6250 3750
F 0 "D?" V 6204 3829 50  0000 L CNN
F 1 "1N4148" V 6295 3829 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6250 3575 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 6250 3750 50  0001 C CNN
	1    6250 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4050 6250 4050
Wire Wire Line
	6250 4050 6250 3900
Wire Wire Line
	6250 3600 6250 3400
Connection ~ 6250 3400
Wire Wire Line
	6250 3400 6700 3400
$EndSCHEMATC
