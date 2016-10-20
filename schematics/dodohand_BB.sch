EESchema Schematic File Version 2
LIBS:dodohand-rescue
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
LIBS:dodohand-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L TEENSY_LC U1
U 1 1 580701FC
P 3000 3700
F 0 "U1" V 3078 5328 60  0000 L CNN
F 1 "TEENSY_LC" V 2972 5328 60  0000 L CNN
F 2 "" H 3200 3700 60  0000 C CNN
F 3 "" H 3200 3700 60  0000 C CNN
	1    3000 3700
	0    -1   -1   0   
$EndComp
$Sheet
S 6225 3125 2075 825 
U 580825BE
F0 "row_shiftReg_photoInterrupt_left" 60
F1 "row_shiftReg_photoInterrupt_BB.sch" 60
F2 "strobe" I T 7550 3125 60 
F3 "CLK" I T 7100 3125 60 
F4 "CS" I T 7350 3125 60 
F5 "MISO" I T 6450 3125 60 
F6 "3.3V" I T 6900 3125 60 
F7 "GND" I T 6650 3125 60 
$EndSheet
Wire Wire Line
	7350 1700 7350 3100
Wire Wire Line
	3000 1700 7550 1700
Wire Wire Line
	3000 1700 3000 2850
Wire Wire Line
	6650 3100 6650 2500
Wire Wire Line
	1100 2500 9250 2500
Wire Wire Line
	1650 2500 1650 2850
Wire Wire Line
	6900 3150 6900 2250
Wire Wire Line
	1800 2250 9500 2250
Wire Wire Line
	1800 2250 1800 2850
Wire Wire Line
	7100 3100 7100 2000
Wire Wire Line
	3450 2000 9650 2000
Wire Wire Line
	3450 2000 3450 2850
Wire Wire Line
	7550 1700 7550 3100
Connection ~ 7350 1700
Wire Wire Line
	2850 2850 2850 1450
Wire Wire Line
	2850 1450 10100 1450
Wire Wire Line
	9900 1450 9900 3100
Wire Wire Line
	10100 1450 10150 3100
Connection ~ 9900 1450
Wire Wire Line
	6450 3150 6450 2750
Wire Wire Line
	4350 2750 9050 2750
Wire Wire Line
	4350 2750 4350 4600
Wire Wire Line
	4350 4600 3450 4600
Wire Wire Line
	3450 4600 3450 4500
Wire Wire Line
	9050 2750 9050 3100
Connection ~ 6450 2750
Wire Wire Line
	9650 2000 9650 3100
Connection ~ 7100 2000
Wire Wire Line
	9500 2250 9500 3100
Connection ~ 6900 2250
Wire Wire Line
	9250 2500 9250 3100
Connection ~ 6650 2500
$Sheet
S 8800 3100 2075 825 
U 580A7E8C
F0 "row_shiftReg_photoInterrupt_right" 60
F1 "row_shiftReg_photoInterrupt_BB.sch" 60
F2 "strobe" I T 10125 3100 60 
F3 "CLK" I T 9675 3100 60 
F4 "CS" I T 9925 3100 60 
F5 "MISO" I T 9025 3100 60 
F6 "3.3V" I T 9475 3100 60 
F7 "GND" I T 9225 3100 60 
$EndSheet
NoConn ~ 3300 2850
NoConn ~ 3150 2850
NoConn ~ 2700 2850
NoConn ~ 2550 2850
NoConn ~ 2400 2850
NoConn ~ 2250 2850
NoConn ~ 2100 2850
NoConn ~ 1950 2850
NoConn ~ 1500 2850
NoConn ~ 3700 3400
NoConn ~ 3700 3550
NoConn ~ 3700 3700
NoConn ~ 3700 3850
NoConn ~ 3700 4000
NoConn ~ 3300 4500
NoConn ~ 3150 4500
NoConn ~ 3000 4500
NoConn ~ 2850 4500
NoConn ~ 2700 4500
NoConn ~ 2550 4500
NoConn ~ 2400 4500
NoConn ~ 2250 4500
NoConn ~ 2100 4500
NoConn ~ 1950 4500
NoConn ~ 1800 4500
NoConn ~ 1650 4500
NoConn ~ 1500 4500
$Comp
L GND #PWR01
U 1 1 580B282D
P 1100 2500
F 0 "#PWR01" H 1100 2250 50  0001 C CNN
F 1 "GND" H 1105 2327 50  0000 C CNN
F 2 "" H 1100 2500 50  0000 C CNN
F 3 "" H 1100 2500 50  0000 C CNN
	1    1100 2500
	1    0    0    -1  
$EndComp
Connection ~ 1650 2500
$Comp
L VCC #PWR02
U 1 1 580B3FCB
P 1800 2250
F 0 "#PWR02" H 1800 2100 50  0001 C CNN
F 1 "VCC" H 1817 2423 50  0000 C CNN
F 2 "" H 1800 2250 50  0000 C CNN
F 3 "" H 1800 2250 50  0000 C CNN
	1    1800 2250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
