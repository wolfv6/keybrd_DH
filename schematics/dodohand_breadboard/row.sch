EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:DH_component
LIBS:dodohand_BB-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "Row of shift registers with 2 keys"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC165 U2
U 1 1 5809DC59
P 2450 4700
AR Path="/5809DAC4/5809DC59" Ref="U2"  Part="1" 
AR Path="/580AEA89/5809DC59" Ref="U5"  Part="1" 
F 0 "U2" V 2404 5278 50  0000 L CNN
F 1 "74HC165" V 2495 5278 50  0000 L CNN
F 2 "" H 2450 4700 50  0000 C CNN
F 3 "" H 2450 4700 50  0000 C CNN
	1    2450 4700
	0    1    1    0   
$EndComp
$Comp
L 74HC165 U4
U 1 1 5809DD6D
P 5100 4750
AR Path="/5809DAC4/5809DD6D" Ref="U4"  Part="1" 
AR Path="/580AEA89/5809DD6D" Ref="U7"  Part="1" 
F 0 "U4" V 5054 5328 50  0000 L CNN
F 1 "74HC165" V 5145 5328 50  0000 L CNN
F 2 "" H 5100 4750 50  0000 C CNN
F 3 "" H 5100 4750 50  0000 C CNN
	1    5100 4750
	0    1    1    0   
$EndComp
$Comp
L SN74AHC1G125 U3
U 1 1 5809E85F
P 4900 1600
AR Path="/5809DAC4/5809E85F" Ref="U3"  Part="1" 
AR Path="/580AEA89/5809E85F" Ref="U6"  Part="1" 
F 0 "U3" V 4696 1022 50  0000 R CNN
F 1 "SN74AHC1G125" V 4605 1022 50  0000 R CNN
F 2 "" H 4750 1600 50  0000 C CNN
F 3 "" H 4750 1600 50  0000 C CNN
	1    4900 1600
	0    -1   -1   0   
$EndComp
Text HLabel 2650 900  1    60   Input ~ 0
3.3V
Text HLabel 5200 1150 1    60   Input ~ 0
MISO
$Comp
L 2keys X1
U 1 1 580A71BC
P 7050 4650
AR Path="/5809DAC4/580A71BC" Ref="X1"  Part="1" 
AR Path="/580AEA89/580A71BC" Ref="X2"  Part="1" 
F 0 "X1" V 7053 4372 60  0000 R CNN
F 1 "2keys" V 6947 4372 60  0000 R CNN
F 2 "" H 7050 4650 60  0000 C CNN
F 3 "" H 7050 4650 60  0000 C CNN
	1    7050 4650
	0    -1   -1   0   
$EndComp
Text HLabel 6400 1100 1    60   Input ~ 0
strobe
Text HLabel 2000 750  1    60   Input ~ 0
GND
Text HLabel 2900 900  1    60   Input ~ 0
CS
Text HLabel 2800 950  1    60   Input ~ 0
CLK
$Comp
L C C1
U 1 1 580B7854
P 2350 1150
AR Path="/5809DAC4/580B7854" Ref="C1"  Part="1" 
AR Path="/580AEA89/580B7854" Ref="C2"  Part="1" 
F 0 "C1" V 2098 1150 50  0000 C CNN
F 1 "C" V 2189 1150 50  0000 C CNN
F 2 "" H 2388 1000 50  0000 C CNN
F 3 "" H 2350 1150 50  0000 C CNN
	1    2350 1150
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 580AD28D
P 2250 5700
AR Path="/5809DAC4/580AD28D" Ref="R1"  Part="1" 
AR Path="/580AEA89/580AD28D" Ref="R4"  Part="1" 
F 0 "R1" H 2320 5746 50  0000 L CNN
F 1 "4.7K" H 2320 5655 50  0000 L CNN
F 2 "" V 2180 5700 50  0000 C CNN
F 3 "" H 2250 5700 50  0000 C CNN
	1    2250 5700
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 580AD589
P 5500 5700
AR Path="/5809DAC4/580AD589" Ref="R2"  Part="1" 
AR Path="/580AEA89/580AD589" Ref="R5"  Part="1" 
F 0 "R2" H 5570 5746 50  0000 L CNN
F 1 "4.7K" H 5570 5655 50  0000 L CNN
F 2 "" V 5430 5700 50  0000 C CNN
F 3 "" H 5500 5700 50  0000 C CNN
	1    5500 5700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 580AEF70
P 7200 5800
AR Path="/5809DAC4/580AEF70" Ref="R3"  Part="1" 
AR Path="/580AEA89/580AEF70" Ref="R6"  Part="1" 
F 0 "R3" H 7270 5846 50  0000 L CNN
F 1 "470" H 7270 5755 50  0000 L CNN
F 2 "" V 7130 5800 50  0000 C CNN
F 3 "" H 7200 5800 50  0000 C CNN
	1    7200 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 750  2000 4000
Wire Wire Line
	1600 3850 5200 3850
Wire Wire Line
	4650 3850 4650 4050
Wire Wire Line
	2550 4000 2550 3850
Connection ~ 2550 3850
Wire Wire Line
	5200 3850 5200 4050
Connection ~ 4650 3850
Wire Wire Line
	2650 900  2650 4000
Wire Wire Line
	2650 3400 7200 3400
Wire Wire Line
	5300 3400 5300 4050
Wire Wire Line
	2250 4000 2250 3600
Wire Wire Line
	2250 3600 5000 3600
Wire Wire Line
	5000 3600 5000 4050
Wire Wire Line
	2800 950  2800 4000
Wire Wire Line
	2800 3200 5450 3200
Wire Wire Line
	2900 900  2900 4000
Wire Wire Line
	2900 2950 5550 2950
Wire Wire Line
	5550 2950 5550 4050
Wire Wire Line
	5200 2550 5200 2750
Wire Wire Line
	5200 2750 2000 2750
Connection ~ 2000 3850
Wire Wire Line
	2500 1150 4550 1150
Connection ~ 2900 2950
Wire Wire Line
	4900 2550 4900 2550
Wire Wire Line
	4900 2550 4900 4050
Wire Wire Line
	7200 3400 7200 3800
Connection ~ 5300 3400
Wire Wire Line
	6400 5600 6750 5600
Wire Wire Line
	6400 1100 6400 5600
Connection ~ 2000 2750
Wire Wire Line
	5450 3200 5450 4050
Connection ~ 2800 3200
Connection ~ 2650 3400
Wire Wire Line
	4550 2550 2900 2550
Connection ~ 2900 2550
Connection ~ 2650 1150
Wire Wire Line
	2200 1150 2000 1150
Connection ~ 2000 1150
Wire Wire Line
	7200 5600 7200 5650
Wire Wire Line
	5500 5450 5500 5550
Wire Wire Line
	2250 5400 2250 5550
Wire Wire Line
	1600 5950 7200 5950
Wire Wire Line
	1600 5950 1600 3850
Wire Wire Line
	5500 5850 5500 5950
Connection ~ 5500 5950
Wire Wire Line
	2250 5850 2250 5950
Connection ~ 2250 5950
Wire Wire Line
	5400 5450 5400 5950
Connection ~ 5400 5950
Wire Wire Line
	5300 5450 5300 5950
Connection ~ 5300 5950
Wire Wire Line
	5200 5450 5200 5950
Connection ~ 5200 5950
Wire Wire Line
	5000 5450 5000 5950
Connection ~ 5000 5950
Wire Wire Line
	4900 5450 4900 5950
Connection ~ 4900 5950
Wire Wire Line
	4800 5450 4800 5950
Connection ~ 4800 5950
Wire Wire Line
	4700 5450 4700 5950
Connection ~ 4700 5950
Wire Wire Line
	2850 5400 2850 5950
Connection ~ 2850 5950
Wire Wire Line
	2750 5400 2750 5950
Connection ~ 2750 5950
Wire Wire Line
	2650 5400 2650 5950
Connection ~ 2650 5950
Wire Wire Line
	2550 5400 2550 5950
Connection ~ 2550 5950
Wire Wire Line
	2350 5400 2350 5950
Connection ~ 2350 5950
Wire Wire Line
	2150 5400 2150 5950
Connection ~ 2150 5950
Wire Wire Line
	2050 5400 2050 5950
Connection ~ 2050 5950
Wire Wire Line
	5500 5450 6050 5450
Wire Wire Line
	6050 5450 6050 3600
Wire Wire Line
	6050 3600 7050 3600
Wire Wire Line
	7050 3600 7050 3800
Wire Wire Line
	6750 3800 6200 3800
Wire Wire Line
	6200 3800 6200 5500
Wire Wire Line
	6200 5500 2250 5500
Connection ~ 2250 5500
Connection ~ 5500 5450
NoConn ~ 4750 4050
NoConn ~ 2100 4000
NoConn ~ 2350 4000
$EndSCHEMATC
