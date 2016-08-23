
# ADS1110 AVR DRIVER LIBRARY

The __ADS1110__ is a 16-Bit Single-Channel (Single-Ended or Differential) ADC IC with Onboard Reference (2.048V), PGA & HW I2C capabilities
in a SOT-23-6 package.

This library contains a complete driver for the ADS1110 offering full control over its Configuration Settings, as well as the ability 
to recieve raw data, voltage readings (in mV, to avoid floating point caclulations) or percentage readings in either Single-Shot or 
Continuous mode.


## Repository Contents

* **ADS1110.h** - Header file of the library
* **ADS1110.cpp** - Compilation file of the library
* **/examples** - Contains a simple testing sketch to verify that the ic is working correctly, and an example sketch which illustrates usage 
of all the Configuration Settings & Reading Methods provided by the library.
* **/extras** - Complementary documentation (End-User License, etc.)
* **keywords.txt** - Keywords for this library which will be highlighted in sketches written in the Arduino IDE. 
* **library.properties** - General library properties for the Arduino package manager.
* **README.md** - The readme file for this library.
* **library.json** - JSON file for the Arduino package manager (Ver.>1.5).


## HOOK-UP

* PIN 1 - Connect Vin+ to voltage source to be measured
* PIN 2 - Connect GND to Arduino GND
* PIN 3 - Connect SCL to Arduino PIN A5 with a 2K2 pull-up resistor
* PIN 4 - Conntect SDA to Arduino PIN A4 with a 2K2 pull-up resistor
* PIN 5 - Connect VCC to Arduino 5V output
* PIN 6 - Connect Vin- either to Arduino GND (for Single-Ended voltage readings ranging 0-2.048V) or to an external 2.048V reference source 
(for Single-Ended voltage readings ranging 0-4.096V) or to 'negative' input (for differential voltage readings between positive and 'negative' inputs).

>__Note__: The 'negative' input is put in brackets here because it isn't a 'real' negative voltage - 
i.e. with relation to the circuit's common ground - only with relation to the positive input side!

* __DECOUPING__: Connect a 0.1uF Ceramic Capacitor between VCC & GND PINS.


## I2C COMMUNICATION

>__INPORTANT__: This library uses the '[WSWire](https://github.com/steamfire/WSWireLib/tree/master/Library/WSWire)' library for I2C communication 
between the contoller IC (Master) and thethe ADS1110 (Slave), so it is NECESSARY to have it installed prior to using the current libraty. 
>
>Alternatively, if you wish to use the '[Wire](https://github.com/arduino/Arduino/tree/master/hardware/arduino/avr/libraries/Wire)' - or any other I2C library for that matter - simply change the following line the the 'ADS1110.h' file:
```
#include <WSWire.h>
```
> to this:
```
#include <Wire.h>  // or to whatever I2C library name you are using.
```

> As noted above, whichever library you intend to use for this purpose __must be alredy installed__ for the ADS1110 library to work.


## I2C ADDRESSES

Each ADS1110 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific part number & top marking 
on the package itself):

| PART NO.  | BIN     | HEX  | DEC | MARKING |
|-----------|---------|------|-----|---------|
| ADS1110A0 | 1001000 | 0x48 | 72  | ED0     |
| ADS1110A1 | 1001001 | 0x49 | 73  | ED1     |
| ADS1110A2 | 1001010 | 0x4A | 74  | ED2     |
| ADS1110A3 | 1001011 | 0x4B | 75  | ED3     |
| ADS1110A4 | 1001100 | 0x4C | 76  | ED4     |
| ADS1110A5 | 1001101 | 0x4D | 77  | ED5     |
| ADS1110A6 | 1001110 | 0x4E | 78  | ED6     |
| ADS1110A7 | 1001111 | 0x4F | 79  | ED7     |


## LIBRARY INSTALLATION & SETUP

Begin by installing the library either by using the Arduino IDE's Installation Wizard (Arduino IDE >1.5) or simply download the library's ZIP folder from this GITHUB repository, extract it, and copy the extraxcted folder to your Arduino 'libraries' folder.

Next, include the library at the top of the sketch as follows:

```
#include <ADS1110.h>
```

At this point you can construct a new ADS1110 object use the following line (at the top of the sketch after the 'include' line):

```
ADS1110 device_name(device_address);
```

>__NOTE__: replace the '__device_name__' above with a name of your choice. Also, make sure to replace the variable '__device_address__' with 
the specific I2C address of your device - see I2C ADDRESSES section above.


## LIBRARY FUNCTIONS

With the library installed & included in the sketch, and an ADS1110 object initiallized, the following functions are available 
(see the sketch itself for actual usage examples):

__ping();__                                  
Parameters: None  
Description: Searches the I2C Bus for the device at the pre-defined address 
Returns: Byte (0 = Success / 1-6 = Error Code: see Section 'I2C Communication Result Codes' below)

__getGain();__
Parameters: None
Description: Gets the current Gain settings
Returns: Byte (1 / 2 / 4 / 8)

__setGain();__
Parameters: GAIN_1 / GAIN_2 /GAIN_4 / GAIN_8
Description: Sets the Gain (x1 / x2 / x4 / x8; Default: x1)
Returns: None

__getRate();__
Parameters: None
Description: Gets the current Sample Rate settings
Returns: Byte (15 / 30 / 60 / 240)

__setRate();__
Parameters: SPS_15 / SPS_30 / SPS_60 / SPS_240
Description: Sets the Sample Rate (15 / 30 / 60 / 240 Samples per Second; Default: 15_SPS)
Returns: None

__getMode();__
Parameters: None
Description: Gets the current Conversion Mode settings
Returns: Byte (0 = Continuous / 1 = Single-Shot)

__setMode();__
Parameters: CONT / SINGLE
Description: Sets the Conversion Mode (Continuous / Single-Shot; Default: Continuous)
Returns: None

__getRes();__
Parameters: None
Description: Gets the current Resolution settings
Returns: Byte (12 / 14 / 15 / 16)

__setRes();__
Parameters: 12_BIT / 14_BIT / 15_BIT / 16_BIT
Description: Sets the Resolution level ( 12 / 14 / 15 / 16-BIT; Default: 16-BIT)
Returns: None

__getVref();__           
Parameters: None
Description: Gets the current Voltage Reference mode (INTERNAL / EXTERNAL, Default: INTERNAL)
Returns: Int (0 / 2048)

__setVref();__           
Parameters: INT_REF / EXT_REF
This setting needs to be set according to the hardware hookup of the ADS1110 Pin Vin-, namely:
If the Vin- pin is connected to GND, then the Voltage Reference (Vref) should be set to 'INTERNAL'. 
This, in turn, provides a voltage reading range of 0-2048mV. Alternatively, the Vin- pin may be 
connected to an external 2.048V source, in which case the Voltage Referece settings should be set 
to 'EXTERNAL'. The latter hookup & setting gives an extended voltage reading range of 0-4096mV.
Description: Sets the Voltage reference mode (INTERNAL / EXTERNAL)
Returns: None

__reset();__ 
Parameters: None
Description: Resets the Configuration register to its default settings
Returns: None

__getData();__           
Parameters: None
Description: Gets the latest raw ADC reading
Returns: int

__getVolt();__
Parameters: None
Description: Gets the latest ADC reading in mV
Returns: int

__getPercent();__
Parameters: None
Description: Gets the latest ADC reading in Percentage (0-100%) format
Returns: byte (0 - 100)

__singleCon();__
Parameters: None
Description: Initiates a single conversion and returns the ADC reading
Returns: int

__getComResult();__
Paramters: None
Description: Gets the result of the latest I2C communication with the device
Returns: Byte (0 = Success / 1-6 = Error Code: see Section 'I2C Communication Result Codes' below)

__configStr();__
Parameters: None
Description: Generates a printable String with all current Configuration Settings
Returns: String

NOTE: The ADS1110's Sample Rate and Resolution settings are interdependent, that is, setting the value of either will automatically 
cause the other setting to change accordingly (15_SPS = 16-BIT / 30_SPS = 15-BIT / 60_SPS = 14-BIT / 240_SPS = 12-BIT)

And, lastly, if for whatever reason you wish to destruct an existing ADS1110 object, you can use the following line to do so:

```
~ADS1110 device_name();
```


## I2C COMMUNICATION RESULT CODES

0 ... Success (no error)
1 ... Buffer overflow
2 ... Address sent, NACK received
3 ... Data send, NACK received
4 ... Other error (lost bus arbitration, bus error, etc.)
5 ... Timed-out while trying to become Bus Master
6 ... Timed-out while waiting for data to be sent


## RUNNING THE EXAMPLE SKETCH

1) Hook-up the ADS1110 to the Arduino as explained above.
2) If you like, connect a 10K potentiometer to the ADS1110 V+ PIN (the pot's first pin goes to GND, 
middle pin to V+, and third pin to 5V).
3) Upload the sketch to the Arduino.
4) Open the Serial Communications Window (make sure the baud-rate is set to 9600).
5) You should be able to see detailed feedback from running each of the possible methods of the library 
(when you get to the part where readings are carried out, play with the potentiomer to check out changes 
in the readings based on the input voltage).


## BUG REPORTS

Please report any issues/bugs/suggestions at the 'Issues' section of this Github repository.


## LICENSE

This library is a free software; you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation; either version 3.0 of 
the License, or any later version.This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. See the GNU General Public License for more details.


