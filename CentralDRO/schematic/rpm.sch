EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title "Hear Painel"
Date "2021-10-03"
Rev "CONN2.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:DB9_Female J200
U 1 1 614517EC
P 1300 1950
F 0 "J200" H 1218 2642 50  0000 C CNN
F 1 "DataComFreqInverter" H 1218 2551 50  0000 C CNN
F 2 "" H 1300 1950 50  0001 C CNN
F 3 " ~" H 1300 1950 50  0001 C CNN
	1    1300 1950
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_POT RV200
U 1 1 614539CF
P 1450 3700
F 0 "RV200" H 1380 3746 50  0000 R CNN
F 1 "RPM" H 1380 3655 50  0000 R CNN
F 2 "" H 1450 3700 50  0001 C CNN
F 3 "~" H 1450 3700 50  0001 C CNN
	1    1450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2050 1850 2050
Wire Wire Line
	1850 2050 1850 3450
Wire Wire Line
	1850 3450 1450 3450
Wire Wire Line
	1450 3450 1450 3550
Wire Wire Line
	1600 2150 1700 2150
Wire Wire Line
	1700 2150 1700 3700
Wire Wire Line
	1700 3700 1600 3700
Wire Wire Line
	1600 1650 2050 1650
Wire Wire Line
	2050 1650 2050 4050
Wire Wire Line
	2050 4050 1450 4050
Wire Wire Line
	1450 4050 1450 3850
$Comp
L power:GNDREF #PWR?
U 1 1 614566C4
P 2050 4250
F 0 "#PWR?" H 2050 4000 50  0001 C CNN
F 1 "GNDREF" H 2055 4077 50  0000 C CNN
F 2 "" H 2050 4250 50  0001 C CNN
F 3 "" H 2050 4250 50  0001 C CNN
	1    2050 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4250 2050 4050
Connection ~ 2050 4050
$Comp
L Connector:Screw_Terminal_01x03 J201
U 1 1 61456AEE
P 1450 6100
F 0 "J201" H 1368 6417 50  0000 C CNN
F 1 "SensorRPM" H 1368 6326 50  0000 C CNN
F 2 "" H 1450 6100 50  0001 C CNN
F 3 "~" H 1450 6100 50  0001 C CNN
	1    1450 6100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1650 6000 1950 6000
Text GLabel 1950 5650 1    50   Input ~ 0
5,0V
Wire Wire Line
	1950 5650 1950 6000
$Comp
L power:GNDREF #PWR?
U 1 1 61458722
P 1950 6500
F 0 "#PWR?" H 1950 6250 50  0001 C CNN
F 1 "GNDREF" H 1955 6327 50  0000 C CNN
F 2 "" H 1950 6500 50  0001 C CNN
F 3 "" H 1950 6500 50  0001 C CNN
	1    1950 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6200 1950 6200
Wire Wire Line
	1950 6200 1950 6500
$Comp
L Switch:SW_MEC_5G_LED SW201
U 1 1 6145DE3E
P 6800 1700
F 0 "SW201" H 6800 2085 50  0000 C CNN
F 1 "SW_REVERSE_BUTTON" H 6800 1994 50  0000 C CNN
F 2 "" H 6800 2000 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 6800 2000 50  0001 C CNN
	1    6800 1700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW202
U 1 1 6145EC57
P 7750 1700
F 0 "SW202" H 7750 2085 50  0000 C CNN
F 1 "SW_STOP_BUTTON" H 7750 1994 50  0000 C CNN
F 2 "" H 7750 2000 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 7750 2000 50  0001 C CNN
	1    7750 1700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW203
U 1 1 6145F5F9
P 8650 1700
F 0 "SW203" H 8650 2085 50  0000 C CNN
F 1 "SW_START_BUTTON" H 8650 1994 50  0000 C CNN
F 2 "" H 8650 2000 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 8650 2000 50  0001 C CNN
	1    8650 1700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G SW200
U 1 1 6145FFE3
P 5850 1650
F 0 "SW200" H 5850 1935 50  0000 C CNN
F 1 "SW_EMERGENCY" H 5850 1844 50  0000 C CNN
F 2 "" H 5850 1850 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 5850 1850 50  0001 C CNN
	1    5850 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 1700 7950 2000
Wire Wire Line
	8450 1700 8350 1750
Wire Wire Line
	8350 1750 8350 2700
Wire Wire Line
	7550 1700 7450 1750
Wire Wire Line
	7450 1750 7450 2700
Wire Wire Line
	7450 2700 8350 2700
Connection ~ 8350 2700
Wire Wire Line
	6600 1700 6500 1750
Wire Wire Line
	6500 1750 6500 2700
Wire Wire Line
	6500 2700 7450 2700
Connection ~ 7450 2700
Wire Wire Line
	7950 1600 8050 1650
Wire Wire Line
	8050 1650 8050 1850
Wire Wire Line
	8050 1850 9050 1850
Wire Wire Line
	7000 1600 7100 1650
Wire Wire Line
	7100 1650 7100 1800
Wire Wire Line
	8450 1600 8350 1650
Wire Wire Line
	8350 1650 8350 1750
Connection ~ 8350 1750
Wire Wire Line
	7550 1600 7450 1650
Wire Wire Line
	7450 1650 7450 1750
Connection ~ 7450 1750
Wire Wire Line
	6600 1600 6500 1650
Wire Wire Line
	6500 1650 6500 1750
Connection ~ 6500 1750
Wire Wire Line
	6050 1650 6150 1650
Wire Wire Line
	6150 1650 6150 2600
Wire Wire Line
	5650 1650 5600 1650
Wire Wire Line
	5600 1650 5600 2700
Wire Wire Line
	5600 2700 6500 2700
Connection ~ 6500 2700
Wire Wire Line
	1600 1750 3300 1750
Wire Notes Line
	650  1050 650  2700
Wire Notes Line
	650  2700 3100 2700
Wire Notes Line
	3100 2700 3100 1050
Wire Notes Line
	3100 1050 650  1050
Text Notes 1000 950  0    129  ~ 0
DB9 in hear panel.
Text Notes 650  3250 0    129  ~ 0
Pontentiometer in front panel.
Wire Notes Line
	650  3350 3650 3350
Wire Notes Line
	3650 3350 3650 4700
Wire Notes Line
	3650 4700 650  4700
Wire Notes Line
	650  4700 650  3350
Wire Notes Line
	5350 1200 5350 3000
Wire Notes Line
	5350 3000 9200 3000
Wire Notes Line
	9200 3000 9200 1200
Wire Notes Line
	9200 1200 5350 1200
Text Notes 6250 1150 0    129  ~ 0
Keys in front panel.
$Comp
L Connector_Generic:Conn_01x05 J202
U 1 1 6140CAFE
P 5150 1750
F 0 "J202" H 5000 2050 50  0000 L CNN
F 1 "DB9_to_mother_board" H 4700 1450 50  0000 L CNN
F 2 "" H 5150 1750 50  0001 C CNN
F 3 "~" H 5150 1750 50  0001 C CNN
	1    5150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1650 3300 1650
Wire Wire Line
	3300 1650 3300 1750
Wire Wire Line
	3400 1850 3400 1750
Wire Wire Line
	3400 1750 4550 1750
Wire Wire Line
	1600 1850 3400 1850
Wire Wire Line
	4950 1850 3500 1850
Wire Wire Line
	3500 1850 3500 1950
Wire Wire Line
	1600 1950 3500 1950
Wire Wire Line
	4950 1950 3600 1950
Wire Wire Line
	3600 1950 3600 2350
Wire Wire Line
	1600 2350 3600 2350
Text Notes 3500 1550 0    50   ~ 0
orange wire 12V
Text Notes 3500 1650 0    50   ~ 0
gray wire run forward
Text Notes 3500 1750 0    50   ~ 0
black wire gnd from power board
Text Notes 3450 1850 0    50   ~ 0
white wire turn relays ON, power board
Text Notes 3600 1950 0    50   ~ 0
yellow wire run backward.
$Comp
L Connector_Generic:Conn_01x06 J204
U 1 1 614196C1
P 10850 1800
F 0 "J204" H 10700 2150 50  0000 L CNN
F 1 "LedsButtonsFrontPanel" V 11050 1350 50  0000 L CNN
F 2 "" H 10850 1800 50  0001 C CNN
F 3 "~" H 10850 1800 50  0001 C CNN
	1    10850 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1700 8850 1900
Wire Wire Line
	8850 1900 10650 1900
Wire Wire Line
	9050 1850 9050 1700
Wire Wire Line
	9050 1700 10650 1700
Wire Wire Line
	7950 2000 10650 2000
Wire Wire Line
	7100 1800 10650 1800
Text Notes 9900 1600 0    50   ~ 0
start button
Wire Wire Line
	7000 2100 10650 2100
Text Notes 9900 1700 0    50   ~ 0
stop button
Text Notes 9900 1800 0    50   ~ 0
reverse button
Text Notes 9900 1900 0    50   ~ 0
led start button
Text Notes 9900 2000 0    50   ~ 0
led stop button
Text Notes 9800 2100 0    50   ~ 0
led reverse button
$Comp
L Connector_Generic:Conn_01x02 J205
U 1 1 614315FA
P 10850 2600
F 0 "J205" H 10750 2750 50  0000 L CNN
F 1 "Emergency button" V 11000 2200 50  0000 L CNN
F 2 "" H 10850 2600 50  0001 C CNN
F 3 "~" H 10850 2600 50  0001 C CNN
	1    10850 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2600 10650 2600
Wire Wire Line
	8350 2700 10650 2700
Wire Notes Line
	800  5200 800  7000
Wire Notes Line
	800  7000 3400 7000
Wire Notes Line
	3400 7000 3400 5200
Wire Notes Line
	3400 5200 800  5200
Text Notes 800  5150 0    129  ~ 0
Sensor RPM in hear panel.
Wire Wire Line
	7000 2100 7000 1700
Wire Wire Line
	8850 1600 10650 1600
Text Notes 1700 1250 0    89   ~ 0
External
Text Notes 2300 1250 0    89   ~ 0
connector
Text Notes 1750 5350 0    89   ~ 0
External connector
$Comp
L Connector_Generic:Conn_01x02 J203
U 1 1 61484C95
P 4800 950
F 0 "J203" H 4880 942 50  0000 L CNN
F 1 "Conn_01x02" H 4880 851 50  0000 L CNN
F 2 "" H 4800 950 50  0001 C CNN
F 3 "~" H 4800 950 50  0001 C CNN
	1    4800 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1550 4250 1550
Wire Wire Line
	4250 1550 4250 950 
Wire Wire Line
	4250 950  4600 950 
Wire Wire Line
	4550 1750 4550 1050
Wire Wire Line
	4550 1050 4600 1050
Connection ~ 4550 1750
Wire Wire Line
	4550 1750 4950 1750
Wire Wire Line
	4750 6100 4750 1550
Wire Wire Line
	4750 1550 4950 1550
Wire Wire Line
	1650 6100 4750 6100
Text Notes 3700 6050 0    89   ~ 0
SENSOR RPM
$EndSCHEMATC
