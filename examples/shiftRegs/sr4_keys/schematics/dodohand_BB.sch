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
P 3750 4600
F 0 "U1" V 3828 6228 60  0000 L CNN
F 1 "TEENSY_LC" V 3722 6228 60  0000 L CNN
F 2 "" H 3950 4600 60  0000 C CNN
F 3 "" H 3950 4600 60  0000 C CNN
	1    3750 4600
	0    -1   -1   0   
$EndComp
$Sheet
S 6400 3450 1400 2100
U 5809DAC4
F0 "row_left" 60
F1 "row.sch" 60
F2 "GND" I T 6600 3450 60 
F3 "3.3V" I T 6800 3450 60 
F4 "CLK" I T 7000 3450 60 
F5 "CS" I T 7400 3450 60 
F6 "MISO" I T 7200 3450 60 
F7 "strobe" I T 7600 3450 60 
$EndSheet
NoConn ~ 2250 3750
NoConn ~ 2700 3750
NoConn ~ 2850 3750
NoConn ~ 3150 3750
NoConn ~ 3450 3750
NoConn ~ 3750 3750
NoConn ~ 4050 3750
NoConn ~ 4450 4300
NoConn ~ 4450 4450
NoConn ~ 4450 4600
NoConn ~ 4450 4750
NoConn ~ 4450 4900
NoConn ~ 2250 5400
NoConn ~ 2400 5400
NoConn ~ 2550 5400
NoConn ~ 2700 5400
NoConn ~ 2850 5400
NoConn ~ 3000 5400
NoConn ~ 3150 5400
NoConn ~ 3300 5400
NoConn ~ 3450 5400
NoConn ~ 3600 5400
NoConn ~ 3750 5400
NoConn ~ 3900 5400
NoConn ~ 4050 5400
$Comp
L GND #PWR01
U 1 1 580ABE65
P 2000 3200
F 0 "#PWR01" H 2000 2950 50  0001 C CNN
F 1 "GND" H 2005 3027 50  0000 C CNN
F 2 "" H 2000 3200 50  0000 C CNN
F 3 "" H 2000 3200 50  0000 C CNN
	1    2000 3200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 580AC03D
P 2000 2650
F 0 "#PWR02" H 2000 2500 50  0001 C CNN
F 1 "+3.3V" H 2015 2823 50  0000 C CNN
F 2 "" H 2000 2650 50  0000 C CNN
F 3 "" H 2000 2650 50  0000 C CNN
	1    2000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3000 8300 3000
Wire Wire Line
	6600 3000 6600 3450
Wire Wire Line
	2550 3750 2550 2800
Wire Wire Line
	2000 2800 8500 2800
Wire Wire Line
	6800 2800 6800 3450
Wire Wire Line
	4200 3750 4200 2600
Wire Wire Line
	4200 2600 8700 2600
Wire Wire Line
	7000 2600 7000 3450
Wire Wire Line
	3600 3750 3600 2000
Wire Wire Line
	3600 2000 7600 2000
Wire Wire Line
	4200 5400 4850 5400
Wire Wire Line
	4850 5400 4850 2400
Wire Wire Line
	4850 2400 8900 2400
Wire Wire Line
	7200 2400 7200 3450
Wire Wire Line
	7600 2000 7600 3450
Wire Wire Line
	2000 2800 2000 2650
Connection ~ 2400 3000
Connection ~ 2550 2800
Wire Wire Line
	2000 3000 2000 3200
Wire Wire Line
	2400 3750 2400 3000
$Sheet
S 8100 3450 1400 2100
U 580AEA89
F0 "row_right" 60
F1 "row.sch" 60
F2 "GND" I T 8300 3450 60 
F3 "3.3V" I T 8500 3450 60 
F4 "CLK" I T 8700 3450 60 
F5 "CS" I T 9100 3450 60 
F6 "MISO" I T 8900 3450 60 
F7 "strobe" I T 9300 3450 60 
$EndSheet
Wire Wire Line
	8300 3000 8300 3450
Wire Wire Line
	8500 2800 8500 3450
Wire Wire Line
	8700 2600 8700 3450
Wire Wire Line
	8900 2400 8900 3450
Connection ~ 7200 2400
Connection ~ 7000 2600
Connection ~ 6800 2800
Connection ~ 6600 3000
Wire Wire Line
	3000 3750 3000 1600
Wire Wire Line
	3000 1600 9300 1600
Wire Wire Line
	9300 1600 9300 3450
Wire Wire Line
	7400 2200 3900 2200
Wire Wire Line
	3900 2200 3900 3750
Wire Wire Line
	7400 2200 7400 3450
Wire Wire Line
	9100 3450 9100 1800
Wire Wire Line
	9100 1800 3300 1800
Wire Wire Line
	3300 1800 3300 3750
$EndSCHEMATC
