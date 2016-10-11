
# ADS1110 AVR DRIVER LIBRARY

[![Platform Badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://www.arduino.cc/)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[![SemVer](https://img.shields.io/badge/SemVer-1.1.0-brightgreen.svg)](http://semver.org/)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

The ADS1110 is a 16-Bit Single-Channel (Single-Ended or Differential) ADC with Onboard Reference (2.048V), PGA & HW I2C capabilities.

This library contains a complete driver for the ADS1110 offering full control over its Configuration Settings, as well as the ability to recieve raw data, voltage readings (in mV, to avoid floating point math) or percentage readings in either Single-Shot or Continuous mode.

[ADS1110 DATASHEET](http://www.ti.com/lit/ds/symlink/ads1110.pdf)

## Repository Contents

- **ADS1110.h** - Library Header file.
- **ADS1110.cpp** - Library Compilation.
- **/utility** -  
  - **ADS1110InfoStr.h** - Header file containing a functional extention of the library to include generating pritable information String (see Note #9 below).
  - **ADS1110ComStr.h** - Header file containing a functional extention of the library to include generating a pritable I2C Communication Result String (see Note #10 below).
  - **PString.h** - Header file for PString class (lighter alternative to String class) 
  - **PString.cpp** - Compilation file for PString class (lighter alternative to String class) 
- **/examples** -   
  - **/ADS1110_Test/ADS1110_Test.ino** - A basic sketch for testing whether the ADS1110 is hooked-up and operating correctly.
  - **ADS1110_Usage/ADS1110_Usage.ino** - A much more extensive sketch offering a complete usage illustration, as well as a rubust testing mechanism.
  - **ADS1110_Info/ADS1110_Info.ino** - A short sketch showing how to generate a Printable Device Information String of the ADS1110's current settings (i.e. Configuration, Limit &anp; Hysteresis registers, etc.).
  - **/ADS1110_I2C_Status/ADS1110_I2C_Status.ino** - A short sketch for verifying I2C communication has been established between the controller and the ADS1110.
- **/extras** - 
  - **License.txt** - A cope of the end-user license agreement.
- **keywords.txt** - Keywords for this library which will be highlighted in sketches within the Arduino IDE. 
- **library.properties** - General library properties for the Arduino's IDE (>1.5) Library Package Manager.
- **README.md** - The readme file for this library.
- **library.json** - JSON file for the Arduino's IDE (>1.5) Package Manager.

## HOOK-UP

* __PIN 1 (Vin+)__ - Connect Vin+ to voltage source to be measured
* __PIN 2 (GND)__ - Connect GND to Arduino GND
* __PIN 3 (SCL)__ - Connect to Arduino PIN A5 with a 2K2 pull-up resistor
* __PIN 4 (SDA)__ - Connect to the Arduino's PIN A5 with a 2K2 pull-up resistor
* __PIN 5 (VCC)__ - Connect VCC to Arduino 5V output
* __PIN 6 (Vin-)__ - Connect Vin- either to Arduino GND (for Single-Ended voltage readings ranging 0-2.048V) or to an external 2.048V reference source (for Single-Ended voltage readings ranging 0-4.096V) or to 'negative' input (for differential voltage readings between positive and 'negative' inputs).
* __DECOUPING__: Connect a 0.1uF Ceramic Capacitor between the ADS1110's VCC &amp GND PINS

>__Note__: The 'negative' of input Vin- is put in brackets here because it isn't a so-called real negative voltage - that is, with relation to the circuit's common ground - rather it is negative only with relation to the positive input side Vin+.

## GENERAL NOTES

1) __I2C Communications Library__

This library uses the '[WSWire](https://github.com/steamfire/WSWireLib/tree/master/Library/WSWire)' library for I2C communication between the contoller IC (Master) and the ADS1110 (Slave), so it is __NECESSARY__ to have it installed prior to using the current libraty. 

Alternatively, if you wish to use the '[Wire](https://github.com/arduino/Arduino/tree/master/hardware/arduino/avr/libraries/Wire)' - or any other I2C library for that matter - simply change the following line the the __ADS1110.h__ file:
```
#include <WSWire.h>
```
to this:
```
#include <Wire.h>  // or to whatever I2C library name you are using.
```
As noted above, whichever library you intend to use for this purpose __must be alredy installed__ for the ADS1110 library to work.

2) __Device Measurment Range__






3) __Device Information String__

It possible to extend the ADS1110 Library to include a function for generating a pritable device information string showing all the relevant details about the devices current Configuration, Limit & Hysteresis settings. As the additional functionality comes at the cost of increased memory footprint, it was implemented as an optional add-on rather than added directly to the core ADS1110 Library. See the [ADS1110_Info](https://github.com/nadavmatalon/ADS1110/blob/master/examples/ADS1110_Info/ADS1110_Info.ino) example sketch for detailed explanation and an actual usage demo.

4) __Device I2C Communications String__

It is also possible to extend the ADS1110 Library to include a function for generating a pritable I2C Communications string showing the result of each I2C transaction in a human-friendly way, something that may be useful, for example, during debugging sessions. As the additional functionality comes at the cost of increased memory footprint, it was implemented as an optional add-on rather than added directly to the core ADS1110 Library. See the [ADS1110_I2C_Status](https://github.com/nadavmatalon/ADS1110/blob/master/examples/ADS1110_I2C_Status/ADS1110_I2C_Status.ino) example sketch for detailed explanation and an actual usage demo.

## I2C ADDRESSES

Each ADS1110 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific part number & top marking on the package itself):

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

Begin by installing the library either by using the Arduino IDE's Installation Wizard (Arduino Version >1.5) or simply download the library's ZIP folder from GITHUB, extract it, and copy the extraxcted folder to your Arduino 'libraries' folder.

Next, include the library at the top of the sketch as follows:

```
#include <ADS1110.h>
```

At this point you can construct a new ADS1110 object(s) by using the following command (at the top of the sketch after the 'include' line):

```
ADS1110 device_name(device_address);
```

>__NOTE__: replace the '__device_name__' above with a name of your choice. Also, make sure to replace the variable '__device_address__' with 
the specific I2C address of your device - see I2C ADDRESSES section above.


## LIBRARY METHODS

With the library installed & included in the sketch, and an ADS1110 object initiallized, the following functions are available (see the usage example sketch for a detailed implementation):

__Note About Methods' Return Values:__  
All 'get' methods return some sort of value (e.g. getGain(), getMode() etc.), while all 'set' methods return nothing. Nevertheless, ALL methods implicitly update the library's __I2C _comBuffer__ (=communication buffer) after each I2C transmission. The reason for this functional design is to maintain structural coherance between the 'get' and 'set' methods. As 'get' methods cannot return both the desired value and the I2C transmission's result simultaniously. Consequently, if the relevant value hasn't been obtained by a particular 'get' method, the user can simply check the content of the _comBuffer to see what error occured. Similarly, it is possible to check if a particular setting has been successfully applied via a 'set' method either by preforming the corresponding 'get' method or by checking the content of the _comBuffer (0 indicates a successful transmission, 1-6 indicate an error as listed below). 

__ping();__                                    
Parameters:&nbsp;&nbsp;&nbsp;None  
Description:&nbsp;&nbsp;&nbsp;Searches for the ADS1110 at the pre-defined I2C Bus address &amp; returns byte with the relevant success/error code, as follows:  
0 ... Success (no error)  
1 ... Buffer overflow  
2 ... Address sent, NACK received  
3 ... Data send, NACK received  
4 ... Other error (lost bus arbitration, bus error, etc.)  
5 ... Timed-out while trying to become Bus Master  
6 ... Timed-out while waiting for data to be sent
>6 ... Unlisted error (potential future implementation/s)<br>
Returns:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;byte  







__getGain();__  
Parameters: None  
Description: Gets the current Gain settings  
Returns: Byte (1 / 2 / 4 / 8, Default: x1)  
  
__setGain();__  
Parameters: GAIN_1 / GAIN_2 /GAIN_4 / GAIN_8  
Description: Sets the Gain (x1 / x2 / x4 / x8)  
Returns: None  
  
__getRate();__  
Parameters: None  
Description: Gets the current Sample Rate settings  
Returns: Byte (15 / 30 / 60 / 240, Default: 15 SPS)  
  
__setRate();__  
Parameters: SPS_15 / SPS_30 / SPS_60 / SPS_240  
Description: Sets the Sample Rate (15 / 30 / 60 / 240 Samples per Second)  
Returns: None  
  
__getMode();__  
Parameters: None  
Description: Gets the current Conversion Mode settings  
Returns: Byte (0 = Continuous / 1 = Single-Shot, Default: Continuous)  
  
__setMode();__  
Parameters: CONT / SINGLE  
Description: Sets the Conversion Mode (Continuous / Single-Shot)  
Returns: None  
  
__getRes();__  
Parameters: None  
Description: Gets the current Resolution settings  
Returns: Byte (12 / 14 / 15 / 16, Default: 16-BIT)  
  
__setRes();__  
Parameters: 12_BIT / 14_BIT / 15_BIT / 16_BIT  
Description: Sets the Resolution level ( 12 / 14 / 15 / 16-BIT)  
Returns: None  
  
__getVref();__         
Parameters: None  
Description: Gets the current Voltage Reference mode (INTERNAL / EXTERNAL, Default: INTERNAL)  
Returns: Int (0 / 2048)  
  
__setVref();__  
Parameters: INT_REF / EXT_REF  
Description: Sets the Voltage reference mode (INTERNAL / EXTERNAL)  
This setting needs to be set according to the hardware hookup of the ADS1110 Pin Vin-, namely:
If the Vin- pin is connected to GND, then the Voltage Reference (Vref) should be set to 'INTERNAL'. 
This, in turn, provides a voltage reading range of 0-2048mV. Alternatively, the Vin- pin may be 
connected to an external 2.048V source, in which case the Voltage Referece settings should be set 
to 'EXTERNAL'. The latter hookup & setting gives an extended voltage reading range of 0-4096mV.  
Returns: None  
  
__reset();__  
Parameters: None  
Description: Resets the Configuration register to its default settings  
Returns: None  
  
__getData();__  
Parameters: None  
Description: Gets the latest raw ADC reading  
Returns: Int  
  
__getVolt();__  
Parameters: None  
Description: Gets the latest ADC reading (in mV, to avoid floating point calculations)  
Returns: Int  
  
__getPercent();__  
Parameters: None  
Description: Gets the latest ADC reading in Percentage (0-100%) format  
Returns: Byte (0 - 100)  

__singleCon();__  
Parameters: None  
Description: Initiates a single conversion and returns the ADC reading  
Returns: Int  
  




__getComResult();__  
Parameters:&nbsp;&nbsp;&nbsp;None  
Description:&nbsp;&nbsp;Returns the latest I2C Communication result code (see Success/Error codes above)  
Returns:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;byte

__Destructor__  
If you want to destruct an instantiated ADS1110 object, you can use the following method to do so:

```
~ADS1110 device_name();
```
>__NOTE__: replace the '__device_name__' above with the name of your ADS1110 device.

## Extended Functionality*

(* requires an additional '\#include' of the relevant *.h file as shown in the corresponding example sketches)

__ADS1110ComStr();__  
Parameters:&nbsp;&nbsp;&nbsp;Name of an initialized ADS1110 instance  
Description:&nbsp;&nbsp;Returns printable string containing human-friendly information about the device's latest I2C communication result  
Returns:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PString

__ADS1110InfoStr();__  
Parameters:&nbsp;&nbsp;&nbsp;Name of an initialized ADS1110 instance  
Description:&nbsp;&nbsp;Returns printable string containing detailed information about the device's current settings   
Returns:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PString


>__IMPORTANT:__ To get the correct __Raw Data Reading__/__Voltage Readings__/__Percentage Readings__, it is crucial to have the __Voltage Reference (Vref)__ setting defined correctly (i.e. INTERNAL / EXTERNAL). This is done on the basis of the physical hookup of the ADS1110's pin Vin- (namely: INTERNAL if this pin goes to GND, or EXTERNAL if it goes to an 2.048V external source. The default is GND connection & INTERNAL definition).  

>__NOTE:__ The ADS1110's __Sample Rate__ and __Resolution__ settings are interdependent, that is, setting the value of one will automatically 
cause the other setting to change accordingly (15_SPS = 16-BIT / 30_SPS = 15-BIT / 60_SPS = 14-BIT / 240_SPS = 12-BIT).


## RUNNING THE EXAMPLE SKETCHES

1) Hook-up the ADS1110 to the Arduino as explained above.   
2) Upload the relevant example sketch to the Arduino.  
3) Open the Serial Communications Window (make sure the baud-rate is set to 9600 or change it in the sketch to match your Serial Port's buad-rate).  


## BUG REPORTS

Please report any issues/bugs/suggestions at the [Issues](https://github.com/nadavmatalon/ADS1110/issues) section of this Github repository.

## TODO



## VERSION HISTORY

__Ver. 1.0.0__ - First release (26.9.16)  
__Ver. 1.1.0__ -  (10.10.16)  


## LICENSE

[The MIT License (MIT)](https://opensource.org/licenses/MIT)
Copyright (c) 2016 Nadav Matalon

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

