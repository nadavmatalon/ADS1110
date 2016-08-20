/* 
  ADS1110 LIBRARY - COMPLETE USAGE EXAMPLE SKETCH
  -----------------------------------------------

  This sketch offer a simply way of testing that the ADS1110 is hooked-up and running correctly.

  The sketch requests 3 bytes from the ADS1110 (2 data bytes & 1 config byte), sorts out their content and displays it in the Serial Monitor.
  
  INPORTANT: This library uses the 'WSWire' library (https://github.com/steamfire/WSWireLib/tree/master/Library/WSWire) for I2C communication with 
  the ADS1110, so it is NECESSARY to have it installed prior to using the current libraty. Alternatively, if you wish to use the 'Wire' library 
  (https://github.com/arduino/Arduino/tree/master/hardware/arduino/avr/libraries/Wire) - or any other I2C library for that matter - simply change 
  the following line the the 'ADS1110.h' file:
      #include <WSWire.h>
  to this:
      #include <Wire.h>  // or to whatever I2C library name you are using.
  As noted above, whichever library you intend to use for this purpose must be alredy installed for the ADS1110 library to work.

  WIRING DIAGRAM
  --------------
                                       ADS1110
                                       -------
      (to Positive Input: 0-5V)  V+ --| •     |-- V- (to GND / 2.048V Reference / 'Negative' Input 0-5V)
                                      |       |
                                GND --|       |-- VCC
                                      |       |
                                SCL --|       |-- SDA
                                       -------

   PIN 1 - Connect V+ to voltage source to be measured.
   PIN 2 - Connect GND to Arduino GND.
   PIN 3 - Connect SCL to Arduino PIN A5 with a 2K2 pull-up resistor.
   PIN 4 - Conntect SDA to Arduino PIN A4 with a 2K2 pull-up resistor.
   PIN 5 - Connect VCC to Arduino 5V output.
   PIN 6 - Connect V- either to Arduino GND (for Single-Ended voltage readings ranging 0-2.048V),
           or to an external voltage reference of 2.048V (for Single-Ended voltage readings ranging 0-4.096V),
           or to 'negative' input (for differential voltage readings between positive and 'negative' inputs).
           (Note: the 'negative' input is put in brackets here because it isn't a 'real' negative voltage - 
            i.e. with relation to the circuit's common ground - only with relation to the positive input side!)
   DECOUPING: Connect a 0.1uF Ceramic Capacitor between VCC & GND PINS.

 
  I2C ADDRESSES
  -------------
  Each ADS1110 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific part number & top marking 
  on the package itself):
 
    PART               DEVICE I2C ADDRESS          PART
   NUMBER          (BIN)      (HEX)     (DEC)     MARKING
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
  This library is a free software; you can redistribute it and/or modify it under the terms of the 
  GNU General Public License as published by the Free Software Foundation; either version 3.0 of 
  the License, or any later version.This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
  PARTICULAR PURPOSE. See the GNU General Public License for more details.

*/

#include <ADS1110.h>

byte rawData[3] = {0};                      // Container for the data recieved from the ADS1110
byte configByte;                            // Container for the single Config byte
int  dataBytes;                             // Container for the two Data bytes
int  voltage;                               // Container for conversion of reading to voltage (mV)
byte percent;                               // Container for conversion of reading to percent (0-100%)
byte num_bytes;                             // Container for the numebr of bytes recieved

void setup() {
    Serial.begin(9600);                     // Initiallize the Serial Port at 9600bd
    Wire.begin();                           // Initiallize the I2C communications bus
    while(!Serial);                         // Wait for Serial Port to initialize
    delay(750);                             // Take a breath
    Serial.print("\nSerial Open\n");        // Let us know that the Serial Monitor has been activated
    delay(750);                             // Take another breath
 }

void loop() {
      Wire.requestFrom(0x48, 3);
      num_bytes = Wire.available();
      if (num_bytes == 3) {
          for (byte i=0; i<3; i++) rawData[i] = Wire.read();
          dataBytes  = (rawData[0] << 8) + rawData[1];
          configByte = rawData[2];
          voltage    = calcVolt(dataBytes);
          percent    = calcPercent(dataBytes);         
          printConfig(configByte);
          printData(dataBytes);
          printVoltage(voltage);
          printPercent(percent);          
      } else {
          Serial.print("Got the wrong number of bytes (");
          Serial.print(num_bytes);
          Serial.println(" bytes)");
          while (Wire.available()) Wire.read();
          for (byte i=0; i<3; i++) rawData[i] = 0;
      }
      delay(1000);
}

void printConfig(byte configByte) {
      Serial.print ("Config:  HEX: 0x0");
      Serial.print(configByte, HEX);
      Serial.print(", DEC: ");
      Serial.print(configByte, DEC);
      printBinary(configByte);
      Serial.println ();
}

void printBinary(byte byteForPrint) {
    Serial.print(", BIN: ");
    for (byte i=8; i>0; i--) Serial.print(bitRead(byteForPrint, i-1));
    Serial.println();
}

void printData(int dataInt) {
    Serial.print("DATA: ");
    Serial.println(dataInt);
}

void printVoltage(int dataInt) {
    Serial.print("VOLTAGE: ");
    Serial.print(voltage);
    Serial.println("mV");
}

void printPercent(int dataInt) {
    Serial.print("PERCENTAGE: ");
    Serial.print(percent);
    Serial.println("%");
    Serial.println();
}

int calcVolt(int dataForVolt) {
    return (dataForVolt >> 4);
}
byte calcPercent(int dataForPercent) {
  return round((float)dataForPercent * 100.0 / 32767.0);  
}

