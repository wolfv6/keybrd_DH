EESchema Schematic File Version 2
LIBS:DH_component
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
LIBS:dodohand_PCB-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 11
Title "8 shift register and 2 photo interrupt switches"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6150 1000 1    60   Input ~ 0
3.3V
Text HLabel 5500 1000 1    60   Input ~ 0
GND
Text HLabel 6400 1000 1    60   Input ~ 0
CS
Text HLabel 6300 1100 1    60   Input ~ 0
CLK
NoConn ~ 5600 1650
$Comp
L 74HC165 U5
U 1 1 5809DC59
P 5950 2350
AR Path="/5809DAC4/58184E06/5809DC59" Ref="U5"  Part="1" 
AR Path="/5809DAC4/580CDBF5/5809DC59" Ref="U6"  Part="1" 
AR Path="/5809DAC4/580F922E/5809DC59" Ref="U7"  Part="1" 
AR Path="/5809DAC4/580FCD1C/5809DC59" Ref="U8"  Part="1" 
AR Path="/580AEA89/58184E06/5809DC59" Ref="U12"  Part="1" 
AR Path="/580AEA89/580CDBF5/5809DC59" Ref="U13"  Part="1" 
AR Path="/580AEA89/580F922E/5809DC59" Ref="U14"  Part="1" 
AR Path="/580AEA89/580FCD1C/5809DC59" Ref="U15"  Part="1" 
F 0 "U8" V 5904 2928 50  0000 L CNN
F 1 "74HC165" V 5995 2928 50  0000 L CNN
F 2 "" H 5950 2350 50  0000 C CNN
F 3 "" H 5950 2350 50  0000 C CNN
	1    5950 2350
	0    1    1    0   
$EndComp
$Comp
L 2keys X4
U 1 1 580C1CC7
P 7550 5100
AR Path="/5809DAC4/58184E06/580C1CC7" Ref="X4"  Part="1" 
AR Path="/5809DAC4/580CDBF5/580C1CC7" Ref="X8"  Part="1" 
AR Path="/5809DAC4/580F922E/580C1CC7" Ref="X12"  Part="1" 
AR Path="/5809DAC4/580FCD1C/580C1CC7" Ref="X16"  Part="1" 
AR Path="/580AEA89/58184E06/580C1CC7" Ref="X20"  Part="1" 
AR Path="/580AEA89/580CDBF5/580C1CC7" Ref="X24"  Part="1" 
AR Path="/580AEA89/580F922E/580C1CC7" Ref="X28"  Part="1" 
AR Path="/580AEA89/580FCD1C/580C1CC7" Ref="X32"  Part="1" 
F 0 "X16" V 7553 4822 60  0000 R CNN
F 1 "2buttons" V 7447 4822 60  0000 R CNN
F 2 "" H 7550 5100 60  0000 C CNN
F 3 "" H 7550 5100 60  0000 C CNN
	1    7550 5100
	0    -1   -1   0   
$EndComp
$Comp
L resistor_array RA2
U 1 1 580C3691
P 6200 3650
AR Path="/5809DAC4/58184E06/580C3691" Ref="RA2"  Part="1" 
AR Path="/5809DAC4/580CDBF5/580C3691" Ref="RA4"  Part="1" 
AR Path="/5809DAC4/580F922E/580C3691" Ref="RA6"  Part="1" 
AR Path="/5809DAC4/580FCD1C/580C3691" Ref="RA8"  Part="1" 
AR Path="/580AEA89/58184E06/580C3691" Ref="RA10"  Part="1" 
AR Path="/580AEA89/580CDBF5/580C3691" Ref="RA12"  Part="1" 
AR Path="/580AEA89/580F922E/580C3691" Ref="RA14"  Part="1" 
AR Path="/580AEA89/580FCD1C/580C3691" Ref="RA16"  Part="1" 
F 0 "RA8" H 6428 3703 60  0000 L CNN
F 1 "resistor_array" H 6428 3597 60  0000 L CNN
F 2 "" H 6200 3650 60  0001 C CNN
F 3 "" H 6200 3650 60  0001 C CNN
	1    6200 3650
	1    0    0    -1  
$EndComp
Connection ~ 6150 1400
Wire Wire Line
	7700 1400 7700 4250
Wire Wire Line
	6150 1400 7700 1400
Wire Wire Line
	7250 6350 7250 6050
Connection ~ 3600 3950
Wire Wire Line
	7700 6100 7700 6050
Wire Wire Line
	3600 6100 7700 6100
Connection ~ 6350 3050
Wire Wire Line
	7550 3050 6350 3050
Wire Wire Line
	7550 4250 7550 3050
Connection ~ 6250 3150
Wire Wire Line
	7250 3150 6250 3150
Wire Wire Line
	7250 4250 7250 3150
Wire Wire Line
	6350 3050 6350 3350
Wire Wire Line
	6250 3050 6250 3350
Wire Wire Line
	6150 3050 6150 3350
Wire Wire Line
	6050 3350 6050 3050
Connection ~ 5550 3950
Connection ~ 5650 3950
Connection ~ 5750 3950
Connection ~ 5850 3950
Connection ~ 6050 3950
Connection ~ 6150 3950
Connection ~ 6250 3950
Connection ~ 6350 3950
Wire Wire Line
	3600 3950 6350 3950
Wire Wire Line
	3600 1400 3600 6100
Wire Wire Line
	5750 1650 5750 1000
Wire Wire Line
	6150 1000 6150 1650
Wire Wire Line
	5500 1000 5500 1650
Connection ~ 5500 1400
Wire Wire Line
	3600 1400 6050 1400
Text HLabel 8250 1100 1    60   Input ~ 0
strobe
Wire Wire Line
	6400 1000 6400 1650
Wire Wire Line
	6300 1100 6300 1650
Wire Wire Line
	6050 1400 6050 1650
Text HLabel 5750 1000 1    60   Input ~ 0
HQ
Wire Wire Line
	5850 1650 5850 1000
Text HLabel 5850 1000 1    60   Input ~ 0
SER
Wire Wire Line
	8250 6350 8250 1100
Wire Wire Line
	8250 6350 7250 6350
Wire Wire Line
	5850 3050 5850 3950
Wire Wire Line
	5750 3050 5750 3950
Wire Wire Line
	5650 3050 5650 3950
Wire Wire Line
	5550 3050 5550 3950
$EndSCHEMATC
