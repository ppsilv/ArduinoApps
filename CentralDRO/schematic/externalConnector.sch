EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title "External Connectors Reference Design"
Date "2021-10-03"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:DB9_Female J?
U 1 1 615D1086
P 1450 1800
AR Path="/613170B8/615D1086" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615D1086" Ref="J500"  Part="1" 
F 0 "J500" H 1368 2492 50  0000 C CNN
F 1 "DataComFreqInverter" H 1368 2401 50  0000 C CNN
F 2 "" H 1450 1800 50  0001 C CNN
F 3 " ~" H 1450 1800 50  0001 C CNN
	1    1450 1800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1750 1900 2000 1900
Wire Wire Line
	2000 1900 2000 2700
Wire Wire Line
	1750 2000 1850 2000
$Comp
L Connector:Screw_Terminal_01x03 J?
U 1 1 615D10A5
P 1250 6100
AR Path="/613170B8/615D10A5" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615D10A5" Ref="J503"  Part="1" 
F 0 "J503" H 1168 6417 50  0000 C CNN
F 1 "SensorRPM" H 1168 6326 50  0000 C CNN
F 2 "" H 1250 6100 50  0001 C CNN
F 3 "~" H 1250 6100 50  0001 C CNN
	1    1250 6100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1450 6000 1750 6000
Text GLabel 1750 5650 1    50   Input ~ 0
5,0V
Wire Wire Line
	1750 5650 1750 6000
$Comp
L power:GNDREF #PWR?
U 1 1 615D10AE
P 1750 6500
AR Path="/613170B8/615D10AE" Ref="#PWR?"  Part="1" 
AR Path="/615C5CB8/615D10AE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1750 6250 50  0001 C CNN
F 1 "GNDREF" H 1755 6327 50  0000 C CNN
F 2 "" H 1750 6500 50  0001 C CNN
F 3 "" H 1750 6500 50  0001 C CNN
	1    1750 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 6200 1750 6200
Wire Wire Line
	1750 6200 1750 6500
Wire Wire Line
	1750 1600 3450 1600
Text Notes 1150 800  0    129  ~ 0
External connectors.
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 615D10C1
P 9650 1600
AR Path="/613170B8/615D10C1" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615D10C1" Ref="J500B"  Part="1" 
F 0 "J500B" H 9500 1900 50  0000 L CNN
F 1 "DB9_to_mother_board" H 9200 1300 50  0000 L CNN
F 2 "" H 9650 1600 50  0001 C CNN
F 3 "~" H 9650 1600 50  0001 C CNN
	1    9650 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 1500 3450 1500
Wire Wire Line
	3450 1500 3450 1600
Wire Wire Line
	3550 1700 3550 1600
Wire Wire Line
	1750 1700 3550 1700
Wire Wire Line
	9450 1700 5900 1700
Wire Wire Line
	5900 1700 5900 1800
Wire Wire Line
	1750 1800 5900 1800
Wire Wire Line
	9450 1800 5950 1800
Wire Wire Line
	5950 1800 5950 2200
Wire Wire Line
	1750 2200 5950 2200
Text Notes 7350 1400 0    50   ~ 0
orange wire 12V
Text Notes 7350 1500 0    50   ~ 0
gray wire run forward
Text Notes 7350 1600 0    50   ~ 0
black wire gnd from power board
Text Notes 7350 1700 0    50   ~ 0
white wire turn relays ON, power board
Text Notes 7350 1800 0    50   ~ 0
yellow wire run backward.
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 615D10DF
P 9650 800
AR Path="/613170B8/615D10DF" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615D10DF" Ref="J500A"  Part="1" 
F 0 "J500A" H 9730 792 50  0000 L CNN
F 1 "Conn_01x02" H 9730 701 50  0000 L CNN
F 2 "" H 9650 800 50  0001 C CNN
F 3 "~" H 9650 800 50  0001 C CNN
	1    9650 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 1400 8750 1400
Wire Wire Line
	8750 1400 8750 800 
Wire Wire Line
	8750 800  9450 800 
Wire Wire Line
	9250 1400 9450 1400
Wire Wire Line
	1450 6100 9250 6100
Text Notes 8200 6050 0    89   ~ 0
SENSOR RPM
Wire Wire Line
	1750 1500 2200 1500
$Comp
L Connector_Generic:Conn_01x03 J500C
U 1 1 615D18B4
P 9650 2800
F 0 "J500C" H 9730 2842 50  0000 L CNN
F 1 "Conn_01x03" H 9730 2751 50  0000 L CNN
F 2 "" H 9650 2800 50  0001 C CNN
F 3 "~" H 9650 2800 50  0001 C CNN
	1    9650 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1500 2200 2900
Wire Wire Line
	9450 2900 8050 2900
Wire Wire Line
	9450 2800 1850 2800
Wire Wire Line
	1850 2000 1850 2800
Wire Wire Line
	9450 2700 2000 2700
Wire Wire Line
	1750 6200 8050 6200
Wire Wire Line
	8050 6200 8050 4850
Connection ~ 1750 6200
Connection ~ 8050 2900
Wire Wire Line
	8050 2900 7100 2900
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 615DD731
P 1250 4950
AR Path="/613170B8/615DD731" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615DD731" Ref="J502"  Part="1" 
F 0 "J502" H 1100 5250 50  0000 L CNN
F 1 "External_X_sensor" H 800 4650 50  0000 L CNN
F 2 "" H 1250 4950 50  0001 C CNN
F 3 "~" H 1250 4950 50  0001 C CNN
	1    1250 4950
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 615E3B4D
P 9650 4950
AR Path="/613170B8/615E3B4D" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615E3B4D" Ref="J503A"  Part="1" 
F 0 "J503A" H 9500 5250 50  0000 L CNN
F 1 "Internal_X_sensor" H 9200 4650 50  0000 L CNN
F 2 "" H 9650 4950 50  0001 C CNN
F 3 "~" H 9650 4950 50  0001 C CNN
	1    9650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4750 7900 4750
Wire Wire Line
	1450 4850 8050 4850
Wire Wire Line
	9450 4950 1450 4950
Wire Wire Line
	1450 5050 9450 5050
Wire Wire Line
	9450 5150 1450 5150
$Comp
L Connector:USB_B_Micro J?
U 1 1 615EC9D8
P 1400 3900
AR Path="/61343E5A/615EC9D8" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615EC9D8" Ref="J501"  Part="1" 
F 0 "J501" H 1450 4250 50  0000 R CNN
F 1 "Sensor_Y" H 1550 3400 50  0000 R CNN
F 2 "" H 1550 3850 50  0001 C CNN
F 3 "~" H 1550 3850 50  0001 C CNN
	1    1400 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4000 2050 4000
Wire Wire Line
	1700 4100 7250 4100
Wire Notes Line width 45 rgb(194, 74, 9)
	6000 600  6000 7600
Text Notes 6600 750  0    128  ~ 0
Internal connectors
Wire Wire Line
	3550 1600 7100 1600
Wire Wire Line
	9000 900  9000 1600
Wire Wire Line
	9000 900  9450 900 
Connection ~ 9000 1600
Wire Wire Line
	9000 1600 9450 1600
Wire Wire Line
	1700 3900 8050 3900
Wire Wire Line
	9250 1400 9250 6100
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 615E9B0D
P 9650 3900
AR Path="/613170B8/615E9B0D" Ref="J?"  Part="1" 
AR Path="/615C5CB8/615E9B0D" Ref="J501A"  Part="1" 
F 0 "J501A" H 9500 4200 50  0000 L CNN
F 1 "Internal_Y_sensor" H 9200 3600 50  0000 L CNN
F 2 "" H 9650 3900 50  0001 C CNN
F 3 "~" H 9650 3900 50  0001 C CNN
	1    9650 3900
	1    0    0    -1  
$EndComp
Connection ~ 8050 3900
Wire Wire Line
	8050 3900 8050 3700
Wire Wire Line
	1750 6000 7900 6000
Connection ~ 1750 6000
Text Label 8550 4750 0    89   ~ 0
5,0V
Text Label 8550 4850 0    89   ~ 0
GND
Connection ~ 8050 4850
Wire Wire Line
	8050 4850 9450 4850
Wire Wire Line
	7900 6000 7900 4750
Connection ~ 7900 4750
Wire Wire Line
	7900 4750 9450 4750
Text GLabel 7250 3400 1    50   Input ~ 0
3,3V
Wire Wire Line
	7250 3400 7250 3800
Wire Wire Line
	8050 3900 8050 4100
Wire Wire Line
	9450 3700 8500 3700
Connection ~ 8050 3700
Wire Wire Line
	8050 3700 8050 2900
Wire Wire Line
	9450 4100 8050 4100
Connection ~ 8050 4100
Wire Wire Line
	8050 4100 8050 4850
Wire Wire Line
	1700 3700 5700 3700
Wire Wire Line
	5700 3700 5700 4000
Wire Wire Line
	5700 4000 9450 4000
Wire Wire Line
	9450 3900 8200 3900
Wire Wire Line
	8200 3900 8200 4250
Wire Wire Line
	8200 4250 2050 4250
Wire Wire Line
	2050 4250 2050 4000
Wire Wire Line
	9450 3800 7250 3800
Connection ~ 7250 3800
Wire Wire Line
	7250 3800 7250 4100
Text GLabel 8500 3400 1    50   Input ~ 0
GND
Wire Wire Line
	8500 3700 8500 3400
Connection ~ 8500 3700
Wire Wire Line
	8500 3700 8050 3700
Text Label 8000 2700 0    89   ~ 0
5VPotentiometer
Text Label 7650 2800 0    89   ~ 0
Signal_Potentiometer
Text Label 8300 2900 0    89   ~ 0
GND
Wire Wire Line
	7100 2900 7100 1600
Connection ~ 7100 2900
Wire Wire Line
	7100 2900 2200 2900
Connection ~ 7100 1600
Wire Wire Line
	7100 1600 9000 1600
$EndSCHEMATC
