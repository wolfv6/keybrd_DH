EESchema Schematic File Version 2
LIBS:dodohand_PCB-rescue
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
LIBS:strobe_buffer
LIBS:dodohand_PCB-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 11
Title "Row of shift registers with 26 keys"
Date ""
Rev "1"
Comp "wolfv"
Comment1 "74HC165 with unconnected SER pin has unused input pins."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3950 1250 1    60   Input ~ 0
3.3V
Text HLabel 5250 1200 1    60   Input ~ 0
MISO
Text HLabel 2350 1250 1    60   Input ~ 0
strobe
Text HLabel 3300 1100 1    60   Input ~ 0
GND
Text HLabel 4200 1300 1    60   Input ~ 0
CS
Text HLabel 4100 1300 1    60   Input ~ 0
CLK
$Comp
L C C2
U 1 1 580B7854
P 3600 1750
AR Path="/5809DAC4/580B7854" Ref="C2"  Part="1" 
AR Path="/580AEA89/580B7854" Ref="C4"  Part="1" 
F 0 "C4" V 3348 1750 50  0000 C CNN
F 1 "C" V 3439 1750 50  0000 C CNN
F 2 "" H 3638 1600 50  0000 C CNN
F 3 "" H 3600 1750 50  0000 C CNN
	1    3600 1750
	0    1    1    0   
$EndComp
$Sheet
S 9400 5400 1400 500 
U 58184E06
F0 "shiftReg_8keys_0" 60
F1 "shiftReg_8keys.sch" 60
F2 "strobe" I T 10650 5400 60 
F3 "GND" I T 9550 5400 60 
F4 "HQ" I T 10000 5400 60 
F5 "SER" I T 9800 5400 60 
F6 "3.3V" I T 10200 5400 60 
F7 "CLK" I T 10350 5400 60 
F8 "CS" I T 10450 5400 60 
$EndSheet
Wire Wire Line
	3950 2000 5050 2000
Connection ~ 4200 3900
Wire Wire Line
	4200 1300 4200 5400
Connection ~ 3950 2000
Connection ~ 3950 4400
Connection ~ 4100 4150
Wire Wire Line
	6150 4150 6150 5400
Connection ~ 6000 4400
Connection ~ 3300 4900
Wire Wire Line
	6250 3900 6250 5400
Wire Wire Line
	4200 3900 10450 3900
Wire Wire Line
	4100 4150 10350 4150
Wire Wire Line
	4100 1300 4100 5400
Wire Wire Line
	5600 4650 5600 5400
Wire Wire Line
	3750 4650 5600 4650
Wire Wire Line
	3750 5400 3750 4650
Wire Wire Line
	6000 4400 6000 5400
Wire Wire Line
	3950 4400 10200 4400
Wire Wire Line
	3950 1250 3950 5400
Connection ~ 5350 4900
Wire Wire Line
	5350 4900 5350 5400
Wire Wire Line
	3300 1100 3300 5400
Wire Wire Line
	5250 3150 5250 2900
Wire Wire Line
	3300 1750 3450 1750
Connection ~ 3300 1750
Wire Wire Line
	5050 2900 4200 2900
Connection ~ 4200 2900
Wire Wire Line
	2350 1250 2350 3650
Wire Wire Line
	3300 3150 5250 3150
Connection ~ 3300 3150
Wire Wire Line
	4400 3650 4400 5400
NoConn ~ 3550 5400
$Sheet
S 5200 5400 1400 500 
U 580CDBF5
F0 "shiftReg_8keys_1" 60
F1 "shiftReg_8keys.sch" 60
F2 "strobe" I T 6450 5400 60 
F3 "GND" I T 5350 5400 60 
F4 "HQ" I T 5800 5400 60 
F5 "SER" I T 5600 5400 60 
F6 "3.3V" I T 6000 5400 60 
F7 "CLK" I T 6150 5400 60 
F8 "CS" I T 6250 5400 60 
$EndSheet
Wire Wire Line
	5150 2900 5150 3400
Wire Wire Line
	5150 3400 10000 3400
Wire Wire Line
	6450 3650 6450 5400
Connection ~ 4400 3650
$Sheet
S 7400 5400 1400 500 
U 580F922E
F0 "shiftReg_8keys_2" 60
F1 "shiftReg_8keys.sch" 60
F2 "strobe" I T 8650 5400 60 
F3 "GND" I T 7550 5400 60 
F4 "HQ" I T 8000 5400 60 
F5 "SER" I T 7800 5400 60 
F6 "3.3V" I T 8200 5400 60 
F7 "CLK" I T 8350 5400 60 
F8 "CS" I T 8450 5400 60 
$EndSheet
$Sheet
S 3150 5400 1400 500 
U 580FCD1C
F0 "shiftReg_2keys_3" 60
F1 "shiftReg_2keys.sch" 60
F2 "strobe" I T 4400 5400 60 
F3 "GND" I T 3300 5400 60 
F4 "HQ" I T 3750 5400 60 
F5 "SER" I T 3550 5400 60 
F6 "3.3V" I T 3950 5400 60 
F7 "CLK" I T 4100 5400 60 
F8 "CS" I T 4200 5400 60 
$EndSheet
Wire Wire Line
	5800 5400 5800 4650
Wire Wire Line
	5800 4650 7800 4650
Wire Wire Line
	7800 4650 7800 5400
Wire Wire Line
	8000 5400 8000 4650
Wire Wire Line
	8000 4650 9800 4650
Wire Wire Line
	9800 4650 9800 5400
Wire Wire Line
	9550 4900 9550 5400
Wire Wire Line
	7550 4900 7550 5400
Connection ~ 7550 4900
Wire Wire Line
	10200 4400 10200 5400
Wire Wire Line
	10350 4150 10350 5400
Connection ~ 6150 4150
Wire Wire Line
	10450 3900 10450 5400
Connection ~ 6250 3900
Wire Wire Line
	10650 3650 10650 5400
Connection ~ 6450 3650
Wire Wire Line
	10000 3400 10000 5400
Wire Wire Line
	8200 4400 8200 5400
Connection ~ 8200 4400
Wire Wire Line
	8350 5400 8350 4150
Connection ~ 8350 4150
Wire Wire Line
	8450 5400 8450 3900
Connection ~ 8450 3900
Wire Wire Line
	8650 3650 8650 5400
Connection ~ 8650 3650
Wire Wire Line
	2350 3650 10650 3650
Wire Wire Line
	3300 4900 9550 4900
$Comp
L 74AHC1G126 U11
U 1 1 582FA7A2
P 5150 2450
AR Path="/5809DAC4/582FA7A2" Ref="U11"  Part="1" 
AR Path="/580AEA89/582FA7A2" Ref="U16"  Part="1" 
F 0 "U16" V 5196 2222 50  0000 R CNN
F 1 "74AHC1G126" V 5105 2222 50  0000 R CNN
F 2 "" H 5000 2200 50  0000 C CNN
F 3 "" H 5000 2200 50  0000 C CNN
	1    5150 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5250 2000 5250 1200
Wire Wire Line
	3750 1750 3950 1750
Connection ~ 3950 1750
$EndSCHEMATC
