/* 
  MCP9802 LIBRARY - BASIC DEVICE TESTING EXAMPLE
  ----------------------------------------------
  
  INTRODUCTION
  ------------
  This sketch offers a quick & simple code for testing that the MCP9802 is hooked-up and operating correctly.

  The sketch begins by searching for the MCP9802 on the I2C Bus. I then moves on to get the various Register data available from the device 
  (Ambient Temperature, Limit, and Hysteresis). And finally, it verifies that the Alert functionality is working as it should (at least, 
  in default mode).
  
  INPORTANT: This library uses the 'WSWire' library (https://github.com/steamfire/WSWireLib/tree/master/Library/WSWire) for I2C communication with 
  the MCP9802, so it is NECESSARY to have it installed prior to using the current libraty. Alternatively, if you wish to use the 'Wire' library 
  (https://github.com/arduino/Arduino/tree/master/hardware/arduino/avr/libraries/Wire) - or any other I2C library for that matter - simply change 
  the following line the the 'MCP9802.h' file:
      #include <WSWire.h>
  to this:
      #include <Wire.h>  // or to whatever I2C library name you are using.
  As noted above, whichever library you intend to use for this purpose must be alredy installed for the ADS1110 library to work.

  WIRING DIAGRAM
  --------------
                                       MCP9802
                                       -------
                                VCC --| •     |-- SDA
                                      |       |
                                GND --|       |
                                      |       |
                              ALERT --|       |-- SCL
                                       -------

   PIN 1 -    Connect VCC to the Arduino's 5V output
   PIN 2 -    Connect GND to the Arduino's GND
   PIN 3 -    Connect ALERT to the Arduino's Digital Pin 2
   PIN 4 -    Conntect SCL to the Arduino's PIN A5 with a 2K2 pull-up resistor
   PIN 5 -    Conntect SDA to the Arduino's PIN A4 with a 2K2 pull-up resistor
   DECOUPING: Connect a 0.1uF Ceramic Capacitor between the MCP9802's VCC & GND PINS

  I2C ADDRESSES
  -------------
  Each MCP9802 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific part number & top marking 
  on the package itself):
 
    PART               DEVICE I2C ADDRESS          PART
   NUMBER          (BIN)      (HEX)     (DEC)     MARKING
  MCP9802A0       1001000      0x48       72       JKNN
  MCP9802A1       1001001      0x49       73       JLNN
  MCP9802A2       1001010      0x4A       74       JMNN
  MCP9802A3       1001011      0x4B       75       JPNN
  MCP9802A4       1001100      0x4C       76       JQNN
  MCP9802A5       1001101      0x4D       77       JRNN
  MCP9802A6       1001110      0x4E       78       JSNN
  MCP9802A7       1001111      0x4F       79       JTNN

  BUG REPORTS
  -----------
  Please report any bugs/issues/suggestions at the GITHUB Repository of this library at: https://github.com/nadavmatalon/MCP9802

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

#include "MCP9802.h"

const int  MCP9802_ADDR = 0x48;                   // DEC: 72 - I2C address of the MCP9802 (Change as needed)
const byte PIN_D2 = 2;                            // Arduino Digital Pin PIN 2 (connected to the MCP9802 ALERT Pin)
float temp, limit, hyst;                          // Containers for register data

typedef enum:byte {
    OFF = 0,
    ON  = 1
} alert_state_t;

MCP9802 MCP9802(MCP9802_ADDR);

void setup() {
    pinMode(PIN_D2, INPUT_PULLUP);
    Serial.begin(9600);
    Wire.begin();
    while(!Serial);
    printDivider();
    Serial.print(F("\nMCP9802 DEVICE TESTING\n"));    
    printDivider();
    Serial.print(F("\nINITIATING SERIAL COMMUNICATION\n"));  
    Serial.print(F("\nSerial Port is "));
    Serial.print(Serial ? "Open\n" : "Could not be opened\n"); 
    printDivider();
    MCP9802.reset();
    quickDelay();
    Serial.print(F("\nINITIALIZING TESTS\n"));
    runTests();
}
  
void loop() {}

void runTests() {
    testPingDevice();
    testGetConditions();
    testAlert();
}

void testPingDevice() {
    Serial.print(F("\nSearching for device...Device "));
    MCP9802.ping() ? Serial.print(F("Not Found\n")) : Serial.print(F("Found!\n"));
    printDivider(); 
    quickDelay();
}

void testGetConditions() {
     testGetTemp();
     testGetLimit();
     testGetHyst();
     testGetAlertMode();
}

void testGetTemp() {
     Serial.print(F("\nCURRENT TEMP:\t\t"));
     temp = MCP9802.getTemp();
     Serial.print(temp, 1);
     Serial.print(F("C\n"));
}

void testGetLimit() {
     Serial.print(F("\nCURRENT LIMIT:\t\t"));
     limit = MCP9802.getLimit();
     Serial.print(limit, 1);
     Serial.print(F("C\n"));
     quickDelay();
}

void testGetHyst() {    
     Serial.print(F("\nCURRENT HYST:\t\t"));
     hyst = MCP9802.getHyst();
     Serial.print(hyst, 1);
     Serial.print(F("C\n"));
     quickDelay();
}

void testGetAlertMode() {
     Serial.print(F("\nALERT MODE:\t\tACTIVE-"));
     Serial.print(MCP9802.getAlertMode() ? "HIGH\n" : "LOW\n");
     quickDelay();
     printDivider(); 
}

void testAlert() {
     Serial.print(F("\nTESTING ALERT FUNCTIONALITY\n"));
     testAlertState(OFF);
     printDivider(); 
     Serial.print(F("\nSimulating Alert Conditions..."));
     MCP9802.setLimit(temp - 10);
     MCP9802.setHyst(temp - 20);
     Serial.print(F("DONE\n"));
     Serial.print(F("\nCurrent Conditions:\n"));
     testGetConditions();
     testAlertState(ON); 
     printDivider(); 
}

void testSetAlertMode() {
    Serial.print(F("\nSetting Alert Mode to:\tACTIVE-HIGH..."));
    MCP9802.setAlertMode(ACTIVE_HIGH);
    Serial.print(F("...DONE\n"));
    testGetAlertMode();
    quickDelay();
}

void testAlertState(alert_state_t alertState) {
     Serial.print(F("\nEXPECTED PIN D2 STATE:\t"));
     Serial.print(alertState == OFF ? "HIGH (ALARM OFF)\n" : "LOW (ALARM ON)\n");
     Serial.print(F("\nACTUAL PIN D2 STATE:\t"));
     Serial.print(digitalRead(PIN_D2) ? "HIGH (ALARM OFF)\n" : "LOW (ALARM ON)\n");
}

void printDivider() {
    Serial.print(F("\n-----------------------------------------\n"));
}

void quickDelay() {
    delay(50);
}
