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
Sheet 1 3
Title "breadboard with 2 rows of shift registers"
Date ""
Rev ""
Comp "wolfv"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TEENSY_LC U1
U 1 1 5809D22C
P 2950 3500
F 0 "U1" V 3028 5128 60  0000 L CNN
F 1 "TEENSY_LC" V 2922 5128 60  0000 L CNN
F 2 "" H 3150 3500 60  0000 C CNN
F 3 "" H 3150 3500 60  0000 C CNN
	1    2950 3500
	0    -1   -1   0   
$EndComp
$Sheet
S 5600 2350 1400 2100
U 5809DAC4
F0 "row_left" 60
F1 "row.sch" 60
F2 "GND" I T 5800 2350 60 
F3 "3.3V" I T 6000 2350 60 
F4 "CLK" I T 6200 2350 60 
F5 "CS" I T 6600 2350 60 
F6 "MISO" I T 6400 2350 60 
F7 "strobe" I T 6800 2350 60 
$EndSheet
NoConn ~ 1450 2650
NoConn ~ 1900 2650
NoConn ~ 2050 2650
NoConn ~ 2200 2650
NoConn ~ 2350 2650
NoConn ~ 2500 2650
NoConn ~ 2650 2650
NoConn ~ 3100 2650
NoConn ~ 3250 2650
NoConn ~ 3650 3200
NoConn ~ 3650 3350
NoConn ~ 3650 3500
NoConn ~ 3650 3650
NoConn ~ 3650 3800
NoConn ~ 1450 4300
NoConn ~ 1600 4300
NoConn ~ 1750 4300
NoConn ~ 1900 4300
NoConn ~ 2050 4300
NoConn ~ 2200 4300
NoConn ~ 2350 4300
NoConn ~ 2500 4300
NoConn ~ 2650 4300
NoConn ~ 2800 4300
NoConn ~ 2950 4300
NoConn ~ 3100 4300
NoConn ~ 3250 4300
$Comp
L GND #PWR01
U 1 1 580ABE65
P 1200 2100
F 0 "#PWR01" H 1200 1850 50  0001 C CNN
F 1 "GND" H 1205 1927 50  0000 C CNN
F 2 "" H 1200 2100 50  0000 C CNN
F 3 "" H 1200 2100 50  0000 C CNN
	1    1200 2100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 580AC03D
P 1200 1550
F 0 "#PWR02" H 1200 1400 50  0001 C CNN
F 1 "+3.3V" H 1215 1723 50  0000 C CNN
F 2 "" H 1200 1550 50  0000 C CNN
F 3 "" H 1200 1550 50  0000 C CNN
	1    1200 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1900 7500 1900
Wire Wire Line
	5800 1900 5800 2350
Wire Wire Line
	1750 2650 1750 1700
Wire Wire Line
	1200 1700 7700 1700
Wire Wire Line
	6000 1700 6000 2350
Wire Wire Line
	3400 2650 3400 1500
Wire Wire Line
	3400 1500 7900 1500
Wire Wire Line
	6200 1500 6200 2350
Wire Wire Line
	2950 2650 2950 900 
Wire Wire Line
	2950 900  6800 900 
Wire Wire Line
	6600 900  6600 2350
Wire Wire Line
	3400 4300 4050 4300
Wire Wire Line
	4050 4300 4050 1300
Wire Wire Line
	4050 1300 8100 1300
Wire Wire Line
	6400 1300 6400 2350
Wire Wire Line
	6800 900  6800 2350
Connection ~ 6600 900 
Wire Wire Line
	1200 1700 1200 1550
Connection ~ 1600 1900
Connection ~ 1750 1700
Wire Wire Line
	1200 1900 1200 2100
Wire Wire Line
	1600 2650 1600 1900
$Sheet
S 7300 2350 1400 2100
U 580AEA89
F0 "row_right" 60
F1 "row.sch" 60
F2 "GND" I T 7500 2350 60 
F3 "3.3V" I T 7700 2350 60 
F4 "CLK" I T 7900 2350 60 
F5 "CS" I T 8300 2350 60 
F6 "MISO" I T 8100 2350 60 
F7 "strobe" I T 8500 2350 60 
$EndSheet
Wire Wire Line
	7500 1900 7500 2350
Wire Wire Line
	7700 1700 7700 2350
Wire Wire Line
	7900 1500 7900 2350
Wire Wire Line
	8100 1300 8100 2350
Connection ~ 6400 1300
Connection ~ 6200 1500
Connection ~ 6000 1700
Connection ~ 5800 1900
Wire Wire Line
	2800 2650 2800 650 
Wire Wire Line
	2800 650  8500 650 
Wire Wire Line
	8500 650  8500 2350
Wire Wire Line
	8300 2350 8300 650 
Connection ~ 8300 650 
$EndSCHEMATC
