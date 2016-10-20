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
Sheet 3 4
Title "row of shift registers and photointerrupters for breadboard"
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
U 1 1 5804EF41
P 3300 5050
AR Path="/5806FB2B/580825BE/5804EF41" Ref="U2"  Part="1" 
AR Path="/5806FB2B/580A7E8C/5804EF41" Ref="U5"  Part="1" 
F 0 "U2" V 3254 5628 50  0000 L CNN
F 1 "74HC165" V 3345 5628 50  0000 L CNN
F 2 "" H 3300 5050 50  0000 C CNN
F 3 "" H 3300 5050 50  0000 C CNN
	1    3300 5050
	0    1    1    0   
$EndComp
$Comp
L 74HC165 U4
U 1 1 5804EFAE
P 5450 5050
AR Path="/5806FB2B/580825BE/5804EFAE" Ref="U4"  Part="1" 
AR Path="/5806FB2B/580A7E8C/5804EFAE" Ref="U7"  Part="1" 
F 0 "U4" V 5404 5628 50  0000 L CNN
F 1 "74HC165" V 5495 5628 50  0000 L CNN
F 2 "" H 5450 5050 50  0000 C CNN
F 3 "" H 5450 5050 50  0000 C CNN
	1    5450 5050
	0    1    1    0   
$EndComp
$Comp
L photo2 X1
U 1 1 5804F47C
P 8000 4950
AR Path="/5806FB2B/580825BE/5804F47C" Ref="X1"  Part="1" 
AR Path="/5806FB2B/580A7E8C/5804F47C" Ref="X2"  Part="1" 
F 0 "X1" V 8003 4622 60  0000 R CNN
F 1 "photo2" V 7897 4622 60  0000 R CNN
F 2 "" H 8000 4950 60  0000 C CNN
F 3 "" H 8000 4950 60  0000 C CNN
	1    8000 4950
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 58061304
P 8150 6100
AR Path="/5806FB2B/580825BE/58061304" Ref="R3"  Part="1" 
AR Path="/5806FB2B/580A7E8C/58061304" Ref="R6"  Part="1" 
F 0 "R3" H 8220 6146 50  0000 L CNN
F 1 "470" H 8220 6055 50  0000 L CNN
F 2 "" V 8080 6100 50  0000 C CNN
F 3 "" H 8150 6100 50  0000 C CNN
	1    8150 6100
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5806EA6A
P 3100 6100
AR Path="/5806FB2B/580825BE/5806EA6A" Ref="R1"  Part="1" 
AR Path="/5806FB2B/580A7E8C/5806EA6A" Ref="R4"  Part="1" 
F 0 "R1" H 3170 6146 50  0000 L CNN
F 1 "4.7k" H 3170 6055 50  0000 L CNN
F 2 "" V 3030 6100 50  0000 C CNN
F 3 "" H 3100 6100 50  0000 C CNN
	1    3100 6100
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 58071BD4
P 5850 6100
AR Path="/5806FB2B/580825BE/58071BD4" Ref="R2"  Part="1" 
AR Path="/5806FB2B/580A7E8C/58071BD4" Ref="R5"  Part="1" 
F 0 "R2" H 5920 6146 50  0000 L CNN
F 1 "4.7k" H 5920 6055 50  0000 L CNN
F 2 "" V 5780 6100 50  0000 C CNN
F 3 "" H 5850 6100 50  0000 C CNN
	1    5850 6100
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 58086E5C
P 4100 900
AR Path="/5806FB2B/580825BE/58086E5C" Ref="C1"  Part="1" 
AR Path="/5806FB2B/580A7E8C/58086E5C" Ref="C2"  Part="1" 
F 0 "C1" H 4215 946 50  0000 L CNN
F 1 "0.1u" H 4215 855 50  0000 L CNN
F 2 "" H 4138 750 50  0000 C CNN
F 3 "" H 4100 900 50  0000 C CNN
	1    4100 900 
	0    1    1    0   
$EndComp
NoConn ~ 5100 4350
NoConn ~ 2950 4350
NoConn ~ 3200 4350
$Comp
L SN74AHC1G125 U3
U 1 1 5807DA61
P 5250 1500
AR Path="/5806FB2B/580825BE/5807DA61" Ref="U3"  Part="1" 
AR Path="/5806FB2B/580A7E8C/5807DA61" Ref="U6"  Part="1" 
F 0 "U3" V 5046 922 50  0000 R CNN
F 1 "SN74AHC1G125" V 4955 922 50  0000 R CNN
F 2 "" H 5250 1500 50  0000 C CNN
F 3 "" H 5250 1500 50  0000 C CNN
	1    5250 1500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3750 4350 3750 4150
Wire Wire Line
	3750 4150 5900 4150
Wire Wire Line
	5900 850  5900 4350
Wire Wire Line
	3650 4350 3650 3950
Wire Wire Line
	3650 3950 5800 3950
Wire Wire Line
	5800 2850 5800 4350
Wire Wire Line
	3500 3750 8150 3750
Wire Wire Line
	3500 3750 3500 4350
Wire Wire Line
	5550 3450 2350 3450
Wire Wire Line
	3100 4350 3100 4250
Wire Wire Line
	3100 4250 5350 4250
Wire Wire Line
	5350 4250 5350 4350
Connection ~ 5650 3750
Connection ~ 5900 4150
Connection ~ 5800 3950
Wire Wire Line
	5250 2450 5250 4350
Wire Wire Line
	7250 5900 7700 5900
Wire Wire Line
	2350 6250 8150 6250
Wire Wire Line
	7700 4100 6750 4100
Wire Wire Line
	6750 4100 6750 5750
Wire Wire Line
	6750 5750 5850 5750
Wire Wire Line
	8000 3900 6550 3900
Wire Wire Line
	6550 3900 6550 5850
Wire Wire Line
	6550 5850 3100 5850
Wire Wire Line
	3100 5750 3100 5950
Wire Wire Line
	5850 5750 5850 5950
Wire Wire Line
	2900 5750 2900 6250
Connection ~ 2900 6250
Wire Wire Line
	3000 5750 3000 6250
Connection ~ 3000 6250
Wire Wire Line
	3200 5750 3200 6250
Connection ~ 3200 6250
Wire Wire Line
	3400 5750 3400 6250
Connection ~ 3400 6250
Wire Wire Line
	3500 5750 3500 6250
Connection ~ 3500 6250
Wire Wire Line
	3600 5750 3600 6250
Connection ~ 3600 6250
Wire Wire Line
	3700 5750 3700 6250
Connection ~ 3700 6250
Wire Wire Line
	5050 5750 5050 6250
Connection ~ 5050 6250
Wire Wire Line
	5150 5750 5150 6250
Connection ~ 5150 6250
Wire Wire Line
	5250 5750 5250 6250
Connection ~ 5250 6250
Wire Wire Line
	5350 5750 5350 6250
Connection ~ 5350 6250
Wire Wire Line
	5550 5750 5550 6250
Connection ~ 5550 6250
Wire Wire Line
	5650 5750 5650 6250
Connection ~ 5650 6250
Wire Wire Line
	5750 5750 5750 6250
Connection ~ 5750 6250
Connection ~ 3400 3450
Connection ~ 2850 3450
Connection ~ 2350 3450
Wire Wire Line
	2850 3450 2850 4350
Wire Wire Line
	2350 3450 2350 6250
Wire Wire Line
	5000 4350 5000 3450
Connection ~ 5000 3450
Wire Wire Line
	3400 4350 3400 3450
Connection ~ 5550 3450
Wire Wire Line
	7250 5900 7250 1000
Connection ~ 3100 5850
Wire Wire Line
	8150 5900 8150 5950
Wire Wire Line
	8000 3900 8000 4100
Connection ~ 5850 6250
Connection ~ 3100 6250
Wire Wire Line
	8150 3750 8150 4100
Wire Wire Line
	4900 2600 4900 2450
Wire Wire Line
	5550 2450 5550 4350
Wire Wire Line
	4900 2600 5900 2600
Wire Wire Line
	5650 2850 5650 4350
Wire Wire Line
	5650 2850 4400 2850
Wire Wire Line
	4400 2850 4400 1050
Wire Wire Line
	4400 1050 4900 1050
Connection ~ 4900 2600
Wire Wire Line
	6600 2850 5800 2850
Wire Wire Line
	6600 850  6600 2850
Connection ~ 5900 2600
Wire Wire Line
	3700 3100 5550 3100
Wire Wire Line
	3700 750  3700 3100
Connection ~ 5550 3100
Connection ~ 5850 5750
Connection ~ 4900 1050
Wire Wire Line
	4250 900  4900 900 
Wire Wire Line
	4900 1050 4900 750 
Wire Wire Line
	3950 900  3700 900 
Connection ~ 3700 900 
Text HLabel 7250 1000 1    60   Input ~ 0
strobe
Text HLabel 6600 850  1    60   Input ~ 0
CLK
Text HLabel 5900 850  1    60   Input ~ 0
CS
Text HLabel 5550 1050 1    60   Input ~ 0
MISO
Text HLabel 4900 750  1    60   Input ~ 0
3.3V
Connection ~ 4900 900 
Text HLabel 3700 750  1    60   Input ~ 0
GND
$EndSCHEMATC
