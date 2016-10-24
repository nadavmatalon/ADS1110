/* 
  ADS1110 LIBRARY - BASIC DEVICE TESTING EXAMPLE
  ----------------------------------------------
  
  INTRODUCTION
  ------------
  This sketch offers a quick & simple code for testing that the ADS1110 is hooked-up and operating correctly.

  The sketch begins by searching for the ADS1110 on the I2C Bus. I then moves on to get the content of the data and configuration registers 
  available from the device.
  
  INPORTANT: The ADS1110 library depends on the Arduino IDE's native 'Wire' library for I2C communication between the Arduino (Master) and the ADS1110 (Slave).

  WIRING DIAGRAM
  --------------
                                       ADS1110
                                       -------
    (to Positive Input: 0V-VCC)  V+ --| •     |-- V- (to GND / 2.048V Reference / 'Negative' Input 0V-VCC)
                                      |       |
                                GND --|       |-- VCC
                                      |       |
                                SCL --|       |-- SDA
                                       -------

  PIN 1 (Vin+) - Connect to voltage source to be measured
  PIN 2 (GND)  - Connect to Arduino GND
  PIN 3 (SCL)  - Connect to Arduino PIN A5 with a 2K2 pull-up resistor
  PIN 4 (SDA)  - Connect to the Arduino's PIN A5 with a 2K2 pull-up resistor
  PIN 5 (VCC)  - Connect VCC to Arduino 5V output
  PIN 6 (Vin-) - Connect Vin- either to Arduino GND (for Single-Ended voltage readings ranging 0-2.048V) or to an external 2.048V reference source 
                (for Single-Ended voltage readings ranging 0-4.096V) or to 'negative'* input (for differential voltage readings between positive 
                and 'negative' inputs).
  DECOUPING: Connect a 0.1uF Ceramic Capacitor between the ADS1110's VCC & GND PINS.
  
  *Note: The 'negative' of input Vin- is put in brackets here because it actually differential in nature and not a so-called real negative voltage, 
         that is, it's negative only with relation to the positive input side of Vin+.

  I2C ADDRESSES
  -------------
  Each ADS1110 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific part number & top marking 
  on the package itself):
 
    PART               DEVICE I2C ADDRESS          PART
   NUMBER           BIN        HEX        DEC     MARKING
  ---------       -------      ----       ---     -------
  ADS1110A0       1001000      0x48       72        ED0
  ADS1110A1       1001001      0x49       73        ED1
  ADS1110A2       1001010      0x4A       74        ED2
  ADS1110A3       1001011      0x4B       75        ED3
  ADS1110A4       1001100      0x4C       76        ED4
  ADS1110A5       1001101      0x4D       77        ED5
  ADS1110A6       1001110      0x4E       78        ED6
  ADS1110A7       1001111      0x4F       79        ED7

  BUG REPORTS
  -----------
  
  Please report any bugs/issues/suggestions at the GITHUB Repository of this library at: https://github.com/nadavmatalon/ADS1110

  LICENSE
  -------

  The MIT License (MIT)
  Copyright (c) 2016 Nadav Matalon
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
  documentation files (the "Software"), to deal in the Software without restriction, including without
  limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so, subject to the following
  conditions:
  
  The above copyright notice and this permission notice shall be included in all copies or substantial
  portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
  LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ADS1110.h"

const byte DEV_ADDR = 0x48;                   // DEC: 72 - I2C address of the ADS1110 (Change as needed)

ADS1110 ads1110(DEV_ADDR);

void setup() {
    Serial.begin(9600);
    Wire.begin();
    while(!Serial);
    printDivider();
    Serial.print(F("\nADS1110 DEVICE TESTING\n"));    
    printDivider();
    Serial.print(F("\nINITIATING SERIAL COMMUNICATION\n"));  
    Serial.print(F("\nSerial Port is "));
    Serial.print(Serial ? "Open\n" : "Could not be opened\n"); 
    printDivider();
    ads1110.reset();
    quickDelay();
    Serial.print(F("\nINITIALIZING TESTS\n"));
    testPingDevice();
    testGetData();
}
  
void loop() {}

void testPingDevice() {
    Serial.print(F("\nSearching for device...Device "));
    ads1110.ping() ? Serial.print(F("Not Found\n")) : Serial.print(F("Found!\n"));
    quickDelay();
}

void testGetData() {
    Serial.print(F("\nCURRENT DATA:\t"));
    int data = ads1110.getData();
    Serial.print(data);
    Serial.print(F("\n\n"));
    printDivider(); 
}

void printDivider() {
    Serial.print(F("\n-------------------------------------\n"));
}

void quickDelay() {
    delay(50);
}
