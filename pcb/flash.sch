EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5FEC7866
P 2000 2200
F 0 "A1" H 2000 1111 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 2000 1020 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2000 2200 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 2000 2200 50  0001 C CNN
	1    2000 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Female J1
U 1 1 5FEC848A
P 4050 2500
F 0 "J1" H 4078 2476 50  0000 L CNN
F 1 "Conn_01x06_Female" H 4078 2385 50  0000 L CNN
F 2 "Connector_FFC-FPC:Hirose_FH12-6S-0.5SH_1x06-1MP_P0.50mm_Horizontal" H 4050 2500 50  0001 C CNN
F 3 "~" H 4050 2500 50  0001 C CNN
	1    4050 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1200 3850 1200
Wire Wire Line
	3850 1200 3850 2300
Wire Wire Line
	2000 3200 2100 3200
Wire Wire Line
	3850 2400 3150 2400
Wire Wire Line
	3150 2400 3150 3200
Wire Wire Line
	3150 3200 2100 3200
Connection ~ 2100 3200
Wire Wire Line
	1500 2900 1500 3500
Wire Wire Line
	1500 3500 3550 3500
Wire Wire Line
	3550 3500 3550 2700
Wire Wire Line
	3550 2700 3850 2700
Wire Wire Line
	1500 2800 1450 2800
Wire Wire Line
	1450 2800 1450 3550
Wire Wire Line
	1450 3550 3300 3550
Wire Wire Line
	3300 3550 3300 2500
Wire Wire Line
	3300 2500 3850 2500
Wire Wire Line
	1500 2700 1400 2700
Wire Wire Line
	1400 2700 1400 3600
Wire Wire Line
	1400 3600 3400 3600
Wire Wire Line
	3400 3600 3400 2600
Wire Wire Line
	3400 2600 3850 2600
Wire Wire Line
	1500 2600 1350 2600
Wire Wire Line
	1350 2600 1350 3650
Wire Wire Line
	1350 3650 3500 3650
Wire Wire Line
	3500 3650 3500 2800
Wire Wire Line
	3500 2800 3850 2800
$EndSCHEMATC
