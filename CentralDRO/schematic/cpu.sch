EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title "CPU DRO Torno Sanches Blanes"
Date "2021-09-11"
Rev "CPU1.2"
Comp "Open Software Ltda"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L YAAJ_BluePill:YAAJ_BluePill U100
U 1 1 613A261F
P 3200 3550
F 0 "U100" H 3200 2127 50  0000 C CNN
F 1 "YAAJ_BluePill" H 3200 2218 50  0000 C CNN
F 2 "" V 3125 4500 50  0001 C CNN
F 3 "" V 3125 4500 50  0001 C CNN
	1    3200 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	3200 4650 3200 4750
Wire Wire Line
	3400 2350 3400 2450
Text GLabel 10700 1400 2    50   Input ~ 0
5,0v
Wire Wire Line
	3100 4650 3100 4750
Wire Wire Line
	3100 4750 3200 4750
Wire Wire Line
	3300 2450 3300 2350
Wire Wire Line
	3300 2350 3400 2350
Wire Wire Line
	3200 2450 3200 2350
Wire Wire Line
	3200 2350 3300 2350
Connection ~ 3300 2350
Text GLabel 10700 1100 2    50   Input ~ 0
3,3v
$Comp
L power:GNDA #PWR?
U 1 1 614D3878
P 9850 5900
F 0 "#PWR?" H 9850 5650 50  0001 C CNN
F 1 "GNDA" H 9855 5727 50  0000 C CNN
F 2 "" H 9850 5900 50  0001 C CNN
F 3 "" H 9850 5900 50  0001 C CNN
	1    9850 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 5300 10150 5300
Wire Wire Line
	10150 5400 8050 5400
$Comp
L Connector_Generic:Conn_01x05 J102
U 1 1 614B6CA8
P 10350 5500
F 0 "J102" H 10250 5800 50  0000 L CNN
F 1 "Sensor_Y_CPU" H 10050 5200 50  0000 L CNN
F 2 "" H 10350 5500 50  0001 C CNN
F 3 "~" H 10350 5500 50  0001 C CNN
	1    10350 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4900 7200 4450
Connection ~ 7200 4900
Connection ~ 7200 4450
Wire Wire Line
	7200 5050 7200 4900
$Comp
L power:GNDREF #PWR?
U 1 1 6143214F
P 7200 5050
F 0 "#PWR?" H 7200 4800 50  0001 C CNN
F 1 "GNDREF" H 7205 4877 50  0000 C CNN
F 2 "" H 7200 5050 50  0001 C CNN
F 3 "" H 7200 5050 50  0001 C CNN
	1    7200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4450 7300 4450
$Comp
L Connector_Generic:Conn_01x06 J104_B
U 1 1 613AE867
P 7700 4350
F 0 "J104_B" H 7600 4650 50  0000 C CNN
F 1 " " H 7618 4676 50  0000 C CNN
F 2 "" H 7700 4350 50  0001 C CNN
F 3 "~" H 7700 4350 50  0001 C CNN
	1    7700 4350
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J104_A
U 1 1 613AE861
P 7500 4350
F 0 "J104_A" H 7300 4650 50  0000 L CNN
F 1 " " H 7300 4700 50  0000 L CNN
F 2 "" H 7500 4350 50  0001 C CNN
F 3 "~" H 7500 4350 50  0001 C CNN
	1    7500 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4900 6850 4900
Wire Wire Line
	7000 4350 7300 4350
Wire Wire Line
	7000 4350 7000 4750
Connection ~ 7000 4350
$Comp
L Connector_Generic:Conn_01x05 J100
U 1 1 6142E287
P 10800 3250
F 0 "J100" H 10880 3292 50  0000 L CNN
F 1 "J107_Serial01" H 10600 2900 50  0000 L CNN
F 2 "" H 10800 3250 50  0001 C CNN
F 3 "~" H 10800 3250 50  0001 C CNN
	1    10800 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J103_A
U 1 1 614385A4
P 7500 3350
F 0 "J103_A" H 7300 3650 50  0000 L CNN
F 1 " " H 7300 3700 50  0000 L CNN
F 2 "" H 7500 3350 50  0001 C CNN
F 3 "~" H 7500 3350 50  0001 C CNN
	1    7500 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J103_B
U 1 1 61438F81
P 7700 3350
F 0 "J103_B" H 7600 3650 50  0000 C CNN
F 1 " " H 7618 3676 50  0000 C CNN
F 2 "" H 7700 3350 50  0001 C CNN
F 3 "~" H 7700 3350 50  0001 C CNN
	1    7700 3350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7300 3450 6850 3450
Wire Wire Line
	6850 3450 6850 3900
Connection ~ 6850 4900
Wire Wire Line
	7900 3450 8250 3450
Wire Wire Line
	8250 3450 8250 3900
Wire Wire Line
	8250 3900 6850 3900
Connection ~ 6850 3900
Wire Wire Line
	6850 3900 6850 4900
Wire Wire Line
	7300 3350 7000 3350
Connection ~ 7000 3350
Wire Wire Line
	7000 3350 7000 4350
Wire Wire Line
	7300 3150 6350 3150
Wire Wire Line
	4000 3750 6350 3750
Wire Wire Line
	6450 3250 7300 3250
Wire Wire Line
	10600 3450 8250 3450
Connection ~ 8250 3450
Text GLabel 10700 4900 2    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_01x09 J108
U 1 1 6145D4BA
P 1300 3450
F 0 "J108" H 1200 4000 50  0000 L CNN
F 1 "Keyboard" V 1450 3350 50  0000 L CNN
F 2 "" H 1300 3450 50  0001 C CNN
F 3 "~" H 1300 3450 50  0001 C CNN
	1    1300 3450
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J105
U 1 1 6148BC30
P 8450 4350
F 0 "J105" H 8400 4050 50  0000 L CNN
F 1 "MotorViaInversor/RPM" H 8750 4100 50  0000 L CNN
F 2 "" H 8450 4350 50  0001 C CNN
F 3 "~" H 8450 4350 50  0001 C CNN
	1    8450 4350
	1    0    0    1   
$EndComp
Wire Wire Line
	7200 1000 3300 1000
Wire Wire Line
	7200 1000 7200 4450
Text Label 4450 3650 0    50   ~ 0
Cpu_sensor_RPM
Text Label 4500 3550 0    50   ~ 0
Run_Forward
Text Label 4550 3450 0    50   ~ 0
Relays_ON
Text Label 4450 3350 0    50   ~ 0
Run_Backward
$Comp
L Connector_Generic:Conn_01x06 J106
U 1 1 614AFBF8
P 5150 3050
F 0 "J106" H 5050 2650 50  0000 L CNN
F 1 "Torno Control Buttons" H 4900 2550 50  0000 L CNN
F 2 "" H 5150 3050 50  0001 C CNN
F 3 "~" H 5150 3050 50  0001 C CNN
	1    5150 3050
	1    0    0    1   
$EndComp
Wire Wire Line
	4000 2750 4950 2750
Wire Wire Line
	4000 2850 4950 2850
Wire Wire Line
	4000 3150 4950 3150
Text Label 4300 2750 0    50   ~ 0
StartButton
Text Label 4300 2850 0    50   ~ 0
StopButton
Text Label 4300 2950 0    50   ~ 0
ReverseButton
Text Label 4350 3050 0    50   ~ 0
LedStartButton
Text Label 4350 3150 0    50   ~ 0
LedStopButton
Text Label 4350 3250 0    50   ~ 0
LedReverseButton
$Comp
L Connector_Generic:Conn_01x02 J107
U 1 1 614CC548
P 750 4350
F 0 "J107" H 668 4025 50  0000 C CNN
F 1 "EmergencyButton" H 668 4116 50  0000 C CNN
F 2 "" H 750 4350 50  0001 C CNN
F 3 "~" H 750 4350 50  0001 C CNN
	1    750  4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 4250 950  4250
Wire Wire Line
	7200 4900 8050 4900
Wire Wire Line
	8050 5400 8050 4900
Connection ~ 8050 4900
Wire Wire Line
	3200 4750 7000 4750
Connection ~ 3200 4750
Connection ~ 7000 4750
Wire Wire Line
	7000 4750 7000 4800
Wire Wire Line
	2250 4350 2250 4900
Wire Wire Line
	950  4350 2250 4350
Wire Wire Line
	1500 3550 2400 3550
Wire Wire Line
	2400 3650 1500 3650
Wire Wire Line
	1500 3750 2400 3750
Wire Wire Line
	2400 3850 1500 3850
Connection ~ 3300 1550
Connection ~ 2200 3450
Connection ~ 2050 3350
Wire Wire Line
	2050 3350 2400 3350
Wire Wire Line
	1500 3350 2050 3350
Connection ~ 1900 3250
Wire Wire Line
	1900 3250 2400 3250
Wire Wire Line
	1500 3250 1900 3250
Connection ~ 1750 3150
Wire Wire Line
	1750 3150 2400 3150
Wire Wire Line
	1500 3150 1750 3150
Connection ~ 1600 3050
Wire Wire Line
	2200 3450 1500 3450
Wire Wire Line
	2400 3450 2200 3450
Wire Wire Line
	1600 3050 1500 3050
Wire Wire Line
	2400 3050 1600 3050
Wire Wire Line
	3300 1000 3300 1550
Wire Wire Line
	1600 1550 1750 1550
Wire Wire Line
	1600 2000 1600 1550
Wire Wire Line
	2200 2300 2200 3450
Wire Wire Line
	2050 2300 2050 3350
Wire Wire Line
	1900 2300 1900 3250
Wire Wire Line
	1750 2300 1750 3150
Wire Wire Line
	1600 2300 1600 3050
$Comp
L Device:R R5
U 1 1 61529E46
P 2200 2150
F 0 "R5" H 2100 2000 50  0000 L CNN
F 1 "120R" V 2200 2050 50  0000 L CNN
F 2 "" V 2130 2150 50  0001 C CNN
F 3 "~" H 2200 2150 50  0001 C CNN
	1    2200 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 61529CBD
P 2050 2150
F 0 "R4" H 1950 2000 50  0000 L CNN
F 1 "120R" V 2050 2050 50  0000 L CNN
F 2 "" V 1980 2150 50  0001 C CNN
F 3 "~" H 2050 2150 50  0001 C CNN
	1    2050 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 61529A93
P 1900 2150
F 0 "R3" H 1800 2000 50  0000 L CNN
F 1 "120R" V 1900 2050 50  0000 L CNN
F 2 "" V 1830 2150 50  0001 C CNN
F 3 "~" H 1900 2150 50  0001 C CNN
	1    1900 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 615298CB
P 1750 2150
F 0 "R2" H 1650 2000 50  0000 L CNN
F 1 "120R" V 1750 2050 50  0000 L CNN
F 2 "" V 1680 2150 50  0001 C CNN
F 3 "~" H 1750 2150 50  0001 C CNN
	1    1750 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6152977A
P 1600 2150
F 0 "R1" H 1500 2000 50  0000 L CNN
F 1 "120R" V 1600 2050 50  0000 L CNN
F 2 "" V 1530 2150 50  0001 C CNN
F 3 "~" H 1600 2150 50  0001 C CNN
	1    1600 2150
	1    0    0    -1  
$EndComp
Wire Notes Line
	1350 1450 1350 2550
Wire Notes Line
	1350 2550 2450 2550
Wire Notes Line
	2450 2550 2450 1450
Wire Notes Line
	2450 1450 1350 1450
Text Notes 1350 1400 0    50   ~ 0
Talvez não precise desses resistores.
Wire Wire Line
	7900 4450 8050 4450
Wire Wire Line
	8050 4450 8050 4900
Wire Wire Line
	8600 3050 10600 3050
Wire Wire Line
	8600 3050 8600 3350
$Comp
L Connector_Generic:Conn_01x05 J104C
U 1 1 615EF151
P 10800 4550
F 0 "J104C" H 10700 4850 50  0000 L CNN
F 1 "Sensor_X_CPU" H 10500 4250 50  0000 L CNN
F 2 "" H 10800 4550 50  0001 C CNN
F 3 "~" H 10800 4550 50  0001 C CNN
	1    10800 4550
	1    0    0    1   
$EndComp
Wire Wire Line
	7000 1100 7000 3350
Wire Wire Line
	7000 1100 10700 1100
Wire Wire Line
	1700 5000 7100 5000
$Comp
L Device:Buzzer BZ100
U 1 1 6167FBB9
P 8550 5950
F 0 "BZ100" H 8702 5979 50  0000 L CNN
F 1 "Buzzer" H 8702 5888 50  0000 L CNN
F 2 "" V 8525 6050 50  0001 C CNN
F 3 "~" V 8525 6050 50  0001 C CNN
	1    8550 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 6167FF9D
P 8300 6250
F 0 "#PWR?" H 8300 6000 50  0001 C CNN
F 1 "GNDREF" H 8305 6077 50  0000 C CNN
F 2 "" H 8300 6250 50  0001 C CNN
F 3 "" H 8300 6250 50  0001 C CNN
	1    8300 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 6050 8300 6050
Wire Wire Line
	8300 6050 8300 6250
Wire Wire Line
	8000 5850 8450 5850
Connection ~ 8600 3350
Wire Wire Line
	8600 3350 8600 5300
Wire Wire Line
	7900 3350 8600 3350
Wire Wire Line
	8600 3050 8600 1400
Wire Wire Line
	8600 1400 10700 1400
Connection ~ 8600 3050
Wire Wire Line
	8000 3550 7900 3550
Wire Wire Line
	8000 3550 8000 5850
Wire Wire Line
	7100 3550 7300 3550
Wire Wire Line
	6350 3750 6350 3150
Wire Wire Line
	6450 3850 6450 3250
Wire Wire Line
	4000 3850 6450 3850
Wire Wire Line
	10400 3250 10400 3150
Wire Wire Line
	10400 3150 10600 3150
Wire Wire Line
	7900 3250 10400 3250
Wire Wire Line
	10600 3350 10300 3350
Wire Wire Line
	10300 3350 10300 3150
Wire Wire Line
	10300 3150 7900 3150
$Comp
L Comparator:LM339 U101
U 1 1 614BFEED
P 4450 6350
F 0 "U101" H 4450 6717 50  0000 C CNN
F 1 "LM339" H 4450 6626 50  0000 C CNN
F 2 "" H 4400 6450 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 4500 6550 50  0001 C CNN
	1    4450 6350
	-1   0    0    -1  
$EndComp
$Comp
L Comparator:LM339 U101
U 2 1 614C162D
P 4450 7350
F 0 "U101" H 4450 7717 50  0000 C CNN
F 1 "LM339" H 4450 7626 50  0000 C CNN
F 2 "" H 4400 7450 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 4500 7550 50  0001 C CNN
	2    4450 7350
	-1   0    0    -1  
$EndComp
$Comp
L Comparator:LM339 U101
U 3 1 614C2E93
P 2450 6350
F 0 "U101" H 2450 6717 50  0000 C CNN
F 1 "LM339" H 2450 6626 50  0000 C CNN
F 2 "" H 2400 6450 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 2500 6550 50  0001 C CNN
	3    2450 6350
	-1   0    0    -1  
$EndComp
$Comp
L Comparator:LM339 U101
U 5 1 614C3D58
P 6150 6800
F 0 "U101" H 6108 6846 50  0000 L CNN
F 1 "LM339" H 6108 6755 50  0000 L CNN
F 2 "" H 6100 6900 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 6200 7000 50  0001 C CNN
	5    6150 6800
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 614D0BE9
P 5250 6550
F 0 "R8" H 5150 6400 50  0000 L CNN
F 1 "10k" V 5250 6450 50  0000 L CNN
F 2 "" V 5180 6550 50  0001 C CNN
F 3 "~" H 5250 6550 50  0001 C CNN
	1    5250 6550
	-1   0    0    -1  
$EndComp
$Comp
L Device:CP C100
U 1 1 614D1244
P 3050 7100
F 0 "C100" H 2932 7146 50  0000 R CNN
F 1 "2,2uF" H 2932 7055 50  0000 R CNN
F 2 "" H 3088 6950 50  0001 C CNN
F 3 "~" H 3050 7100 50  0001 C CNN
	1    3050 7100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4150 6350 3900 6350
$Comp
L Comparator:LM339 U101
U 4 1 614DD204
P 3400 6450
F 0 "U101" H 3400 6817 50  0000 C CNN
F 1 "LM339" H 3400 6726 50  0000 C CNN
F 2 "" H 3350 6550 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 3450 6650 50  0001 C CNN
	4    3400 6450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3100 6450 3050 6450
Wire Wire Line
	3700 6550 3800 6550
Wire Wire Line
	3800 6550 3800 6700
Wire Wire Line
	3800 6700 3050 6700
Wire Wire Line
	3050 6700 3050 6450
Connection ~ 3050 6450
Wire Wire Line
	3050 6450 2750 6450
$Comp
L Device:R R10
U 1 1 614EE037
P 3050 6100
F 0 "R10" V 3150 6050 50  0000 L CNN
F 1 "1k" V 3050 6000 50  0000 L CNN
F 2 "" V 2980 6100 50  0001 C CNN
F 3 "~" H 3050 6100 50  0001 C CNN
	1    3050 6100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3050 6450 3050 6250
$Comp
L Device:R R7
U 1 1 614F61ED
P 3900 6100
F 0 "R7" V 4000 6050 50  0000 L CNN
F 1 "1k" V 3900 6000 50  0000 L CNN
F 2 "" V 3830 6100 50  0001 C CNN
F 3 "~" H 3900 6100 50  0001 C CNN
	1    3900 6100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3900 5950 3900 5750
Wire Wire Line
	3900 5750 3200 5750
Wire Wire Line
	3050 5750 3050 5950
Wire Wire Line
	4750 6450 5000 6450
Wire Wire Line
	5000 6450 5000 6800
Wire Wire Line
	5000 7450 4750 7450
$Comp
L Device:R R11
U 1 1 6150FF60
P 5250 7000
F 0 "R11" H 5150 6850 50  0000 L CNN
F 1 "470R" V 5250 6900 50  0000 L CNN
F 2 "" V 5180 7000 50  0001 C CNN
F 3 "~" H 5250 7000 50  0001 C CNN
	1    5250 7000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6250 7100 6250 7300
Wire Wire Line
	6250 7600 5250 7600
Wire Wire Line
	5250 7600 5250 7150
Wire Wire Line
	6250 6500 6250 6350
Wire Wire Line
	6250 5750 5250 5750
Wire Wire Line
	5250 5750 5250 6400
Wire Wire Line
	3900 5750 5250 5750
Connection ~ 3900 5750
Connection ~ 5250 5750
Wire Wire Line
	5250 6700 5250 6800
Wire Wire Line
	5250 6800 5000 6800
Connection ~ 5250 6800
Wire Wire Line
	5250 6800 5250 6850
Connection ~ 5000 6800
Wire Wire Line
	5000 6800 5000 7450
Text Notes 5000 7100 1    50   ~ 0
220mV Offset
Wire Wire Line
	3900 6250 3900 6350
Connection ~ 3900 6350
Wire Wire Line
	3900 6350 3700 6350
Wire Wire Line
	3050 6950 3050 6700
Connection ~ 3050 6700
Wire Wire Line
	5250 7600 3050 7600
Wire Wire Line
	3050 7600 3050 7250
Connection ~ 5250 7600
Wire Wire Line
	2750 6250 2850 6250
Wire Wire Line
	2850 6250 2850 5750
Wire Wire Line
	2850 5750 3050 5750
Connection ~ 3050 5750
$Comp
L Device:R R9
U 1 1 6156713E
P 1800 6050
F 0 "R9" V 1900 6000 50  0000 L CNN
F 1 "1k" V 1800 5950 50  0000 L CNN
F 2 "" V 1730 6050 50  0001 C CNN
F 3 "~" H 1800 6050 50  0001 C CNN
	1    1800 6050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2850 5750 1950 5750
Wire Wire Line
	1800 5750 1800 5900
Connection ~ 2850 5750
Wire Wire Line
	1800 6200 1800 6350
Wire Wire Line
	1800 6350 2150 6350
Text Notes 2200 6450 2    50   ~ 0
Gate
Wire Wire Line
	3900 6350 3900 6850
Text Notes 1750 6850 2    50   ~ 0
Clock
$Comp
L Device:R R6
U 1 1 615AB50C
P 1950 7150
F 0 "R6" V 2050 7100 50  0000 L CNN
F 1 "1k" V 1950 7050 50  0000 L CNN
F 2 "" V 1880 7150 50  0001 C CNN
F 3 "~" H 1950 7150 50  0001 C CNN
	1    1950 7150
	-1   0    0    -1  
$EndComp
Text Notes 1700 7350 2    50   ~ 0
Data
Wire Wire Line
	4150 7350 1950 7350
Wire Wire Line
	1950 7350 1950 7300
Connection ~ 1950 7350
Wire Wire Line
	1950 7000 1950 5750
Connection ~ 1950 5750
Wire Wire Line
	1950 5750 1800 5750
Text Notes 5050 6250 2    50   ~ 0
Clock
Text Notes 4950 7450 2    50   ~ 0
Data
Wire Wire Line
	4750 6250 5700 6250
Wire Wire Line
	4750 7250 5900 7250
Text Notes 10150 5600 2    50   ~ 0
Channel A\n
Text Notes 10150 5500 2    50   ~ 0
Channel B
Text Notes 9900 5400 0    50   ~ 0
GND
Text Notes 9900 5300 0    50   ~ 0
5,0V
Wire Wire Line
	3200 4750 3200 5750
Connection ~ 3200 5750
Wire Wire Line
	3200 5750 3050 5750
Wire Wire Line
	6250 7600 6850 7600
Wire Wire Line
	6850 7600 6850 4900
Connection ~ 6250 7600
Wire Wire Line
	1650 6850 1650 5550
Wire Wire Line
	1650 5550 4700 5550
Wire Wire Line
	4700 5550 4700 3950
Wire Wire Line
	4700 3950 4000 3950
Wire Wire Line
	1650 6850 3900 6850
Wire Wire Line
	4000 4050 4450 4050
Wire Wire Line
	4450 4050 4450 5400
Wire Wire Line
	4450 5400 1500 5400
Wire Wire Line
	1500 5400 1500 7350
Wire Wire Line
	1500 7350 1950 7350
Text Label 1800 5000 0    50   ~ 0
Buzzer
Wire Wire Line
	2400 4050 1700 4050
Wire Wire Line
	1700 4050 1700 5000
Wire Wire Line
	1400 4150 2400 4150
Text Label 1950 4150 0    50   ~ 0
Gate
Text Label 1900 4050 0    50   ~ 0
Buzzer
Text Label 4500 3950 0    50   ~ 0
Clock
Text Label 4350 4050 0    50   ~ 0
Data
$Comp
L pspice:C C101
U 1 1 616741D2
P 6500 6800
F 0 "C101" H 6550 6900 50  0000 L CNN
F 1 "100nF" H 6550 6700 50  0000 L CNN
F 2 "" H 6500 6800 50  0001 C CNN
F 3 "~" H 6500 6800 50  0001 C CNN
	1    6500 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 7050 6500 7300
Wire Wire Line
	6500 7300 6250 7300
Connection ~ 6250 7300
Wire Wire Line
	6250 7300 6250 7600
Wire Wire Line
	6500 6550 6500 6350
Wire Wire Line
	6500 6350 6250 6350
Connection ~ 6250 6350
Wire Wire Line
	6250 6350 6250 5750
Wire Wire Line
	8050 4900 8200 4900
Wire Wire Line
	7000 4800 8700 4800
Wire Wire Line
	10600 4450 8800 4450
Wire Wire Line
	8800 4450 8800 4550
Connection ~ 8800 4900
Wire Wire Line
	8800 4900 10700 4900
Wire Wire Line
	10600 4550 8800 4550
Connection ~ 8800 4550
Wire Wire Line
	8800 4550 8800 4900
Wire Wire Line
	5700 5300 7700 5300
Wire Wire Line
	7700 5300 7700 5100
Wire Wire Line
	7700 5100 8900 5100
Wire Wire Line
	8900 5100 8900 4650
Wire Wire Line
	5700 5300 5700 6250
Wire Wire Line
	5900 5400 7800 5400
Wire Wire Line
	7800 5400 7800 5200
Wire Wire Line
	7800 5200 9000 5200
Wire Wire Line
	9000 5200 9000 4750
Wire Wire Line
	5900 5400 5900 7250
Text Label 10250 4650 0    50   ~ 0
Clock
Text Label 10300 4750 0    50   ~ 0
Data
Text Label 4800 7250 0    50   ~ 0
Data
Wire Wire Line
	10150 5600 4100 5600
Text Label 10300 4450 0    50   ~ 0
GND
Text Label 10300 4550 0    50   ~ 0
GND
Text Label 10300 4350 0    50   ~ 0
3,3V
Wire Wire Line
	4000 3050 4100 3050
Wire Wire Line
	4100 3050 4100 5600
Wire Wire Line
	4000 2950 4200 2950
Wire Wire Line
	4200 5500 10150 5500
Wire Wire Line
	4200 2950 4200 5500
Wire Wire Line
	4250 4250 4250 2950
Wire Wire Line
	4250 2950 4950 2950
Wire Wire Line
	4000 4250 4250 4250
Wire Wire Line
	4300 3050 4950 3050
Wire Wire Line
	4000 4350 4300 4350
$Comp
L Switch:SW_Push SW100
U 1 1 61573A77
P 4150 1650
F 0 "SW100" V 4196 1602 50  0000 R CNN
F 1 "Test" V 4105 1602 50  0000 R CNN
F 2 "" H 4150 1850 50  0001 C CNN
F 3 "~" H 4150 1850 50  0001 C CNN
	1    4150 1650
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J106
U 1 1 61574B64
P 4800 1650
F 0 "J106" H 4880 1692 50  0000 L CNN
F 1 "Reset_X_Y" H 4880 1601 50  0000 L CNN
F 2 "" H 4800 1650 50  0001 C CNN
F 3 "~" H 4800 1650 50  0001 C CNN
	1    4800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2050 4150 2050
Wire Wire Line
	4150 2050 4150 1850
Connection ~ 3300 2050
Wire Wire Line
	3300 2050 3300 2350
Wire Wire Line
	4150 2050 4600 2050
Wire Wire Line
	4600 2050 4600 1750
Connection ~ 4150 2050
Wire Wire Line
	4600 1550 4600 1350
Wire Wire Line
	4600 1350 4150 1350
Wire Wire Line
	4150 1350 4150 1450
Wire Wire Line
	2400 2950 2250 2950
Wire Wire Line
	2350 1850 3700 1850
Wire Wire Line
	3700 1850 3700 1350
Wire Wire Line
	3700 1350 4150 1350
Connection ~ 4150 1350
Wire Wire Line
	2400 3950 900  3950
Wire Wire Line
	900  3950 900  2650
Wire Wire Line
	2500 1950 4450 1950
Wire Wire Line
	4450 1950 4450 1650
Wire Wire Line
	4450 1650 4600 1650
Wire Wire Line
	900  2650 2350 2650
Wire Wire Line
	2350 1850 2350 2650
Wire Wire Line
	2250 2950 2250 2700
Wire Wire Line
	2250 2700 2500 2700
Wire Wire Line
	2500 1950 2500 2700
Wire Wire Line
	4000 3250 4950 3250
Wire Wire Line
	4300 3050 4300 4350
$Comp
L Device:Q_PNP_BCE Q100
U 1 1 61602192
P 9650 3750
F 0 "Q100" V 9800 4000 50  0000 C CNN
F 1 "BC327" V 9550 3950 50  0000 C CNN
F 2 "" H 9850 3850 50  0001 C CNN
F 3 "~" H 9650 3750 50  0001 C CNN
	1    9650 3750
	0    1    -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 61614BA0
P 5000 4150
F 0 "R6" H 4900 4000 50  0000 L CNN
F 1 "10k" V 5000 4050 50  0000 L CNN
F 2 "" V 4930 4150 50  0001 C CNN
F 3 "~" H 5000 4150 50  0001 C CNN
	1    5000 4150
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 4150 4850 4150
Wire Wire Line
	5150 4150 5300 4150
Wire Wire Line
	5300 4150 5300 4000
Wire Wire Line
	9650 4000 9650 3950
Wire Wire Line
	5300 4000 9650 4000
Wire Wire Line
	9850 3650 10150 3650
Wire Wire Line
	10150 3650 10150 4350
Wire Wire Line
	10150 4350 10600 4350
Wire Wire Line
	8700 3650 9450 3650
Wire Wire Line
	3300 1550 3300 2050
Wire Wire Line
	1750 1550 1750 2000
Connection ~ 1750 1550
Wire Wire Line
	1750 1550 1900 1550
Wire Wire Line
	1900 1550 1900 2000
Connection ~ 1900 1550
Wire Wire Line
	1900 1550 2050 1550
Wire Wire Line
	2050 1550 2050 2000
Connection ~ 2050 1550
Wire Wire Line
	2050 1550 2200 1550
Wire Wire Line
	2200 1550 2200 2000
Connection ~ 2200 1550
Wire Wire Line
	2200 1550 3300 1550
Wire Wire Line
	8900 4650 10600 4650
Wire Wire Line
	9000 4750 10600 4750
Wire Wire Line
	9850 5900 9850 5700
Wire Wire Line
	9850 5700 10150 5700
Wire Wire Line
	7100 3550 7100 5000
Wire Wire Line
	2250 4900 6850 4900
Wire Wire Line
	6300 3350 6300 4150
Wire Wire Line
	6300 4150 7300 4150
Wire Wire Line
	4000 3350 6300 3350
Wire Wire Line
	6250 3450 6250 4250
Wire Wire Line
	6250 4250 7300 4250
Wire Wire Line
	4000 3450 6250 3450
Wire Wire Line
	6200 3550 6200 4550
Wire Wire Line
	6200 4550 7300 4550
Wire Wire Line
	4000 3550 6200 3550
Wire Wire Line
	6150 3650 6150 4650
Wire Wire Line
	6150 4650 7300 4650
Wire Wire Line
	4000 3650 6150 3650
Wire Wire Line
	8700 3650 8700 4800
Wire Wire Line
	7900 4150 8250 4150
Wire Wire Line
	7900 4250 8250 4250
Wire Wire Line
	7900 4550 8100 4550
Wire Wire Line
	8100 4550 8100 4450
Wire Wire Line
	8100 4450 8250 4450
Wire Wire Line
	7900 4650 8150 4650
Wire Wire Line
	8150 4650 8150 4550
Wire Wire Line
	8150 4550 8250 4550
Wire Wire Line
	8250 4350 8200 4350
Wire Wire Line
	8200 4350 8200 4900
Connection ~ 8200 4900
Wire Wire Line
	8200 4900 8800 4900
Wire Wire Line
	8600 5300 7950 5300
Wire Wire Line
	7950 5300 7950 4350
Wire Wire Line
	7950 4350 7900 4350
Connection ~ 8600 5300
$Comp
L 74xx:74HC14 U102
U 1 1 618E74CB
P 900 5650
F 0 "U102" V 946 5470 50  0000 R CNN
F 1 "74HC14" V 855 5470 50  0000 R CNN
F 2 "" H 900 5650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 900 5650 50  0001 C CNN
	1    900  5650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R12
U 1 1 618EBFB5
P 1200 6350
F 0 "R12" V 1300 6300 50  0000 L CNN
F 1 "2k7" V 1200 6250 50  0000 L CNN
F 2 "" V 1130 6350 50  0001 C CNN
F 3 "~" H 1200 6350 50  0001 C CNN
	1    1200 6350
	0    1    -1   0   
$EndComp
$Comp
L Device:CP C102
U 1 1 61925C9E
P 900 6700
F 0 "C102" H 782 6746 50  0000 R CNN
F 1 "1uF" H 782 6655 50  0000 R CNN
F 2 "" H 938 6550 50  0001 C CNN
F 3 "~" H 900 6700 50  0001 C CNN
	1    900  6700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	900  6850 900  7600
Wire Wire Line
	900  7600 3050 7600
Connection ~ 3050 7600
Wire Wire Line
	900  6550 900  6350
Wire Wire Line
	1050 6350 900  6350
Connection ~ 900  6350
Wire Wire Line
	900  6350 900  5950
Wire Wire Line
	1350 6350 1800 6350
Connection ~ 1800 6350
Wire Wire Line
	900  5350 900  4550
Wire Wire Line
	900  4550 1400 4550
Wire Wire Line
	1400 4550 1400 4150
Text Notes 9700 7350 0    50   ~ 0
202110CPUPWR1210CONNPWRBRD2010
$EndSCHEMATC
