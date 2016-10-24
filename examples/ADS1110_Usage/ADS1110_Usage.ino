/* 
  ADS1110 LIBRARY - COMPLETE USAGE EXAMPLE SKETCH
  -----------------------------------------------

  This sketch exposes all the functions offered by the ADS1110 library as detailed below, thereby providing a quick & easy way of testing the device.


  INPORTANT: The current library depends on the Arduino IDE's native 'Wire' library for I2C communication between the Arduino (Master) and the ADS1110 (Slave).

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

  LIBRARY INSTALLATION & SETUP
  ----------------------------

  Begin by installing the library either by using the Arduino IDE's installation wizard (Ver.>1.5) 
  or simply download the library's ZIP folder from Github Repository (https://github.com/nadavmatalon/ADS1110), 
  extract it, and copy the extraxcted folder into your Arduino 'Libraries' folder.
  
  Next, include the ADS1110 library at the top of the sketch as follows:

    #include "ADS1110.h"

  At this point you can construct a new ADS1110 object with the following line (place it at the top of the sketch 
  after the 'include' line):

    ADS1110 device_name(device_address);

   NOTE: replace 'device_name' with a name of your choice. Also, make sure to replace the variable 'device_address' with the specific I2C address of your device (see I2C ADDRESSES section above).

  RUNNING THE COMPLETE USAGE EXAMPLE SKETCH
  -----------------------------------------
  1) Hook-up the ADS1110 to the Arduino as described above.
  2) If you like, connect a 10K potentiometer to the ADS1110 Vin+ PIN (potentimeter's first pin goes to GND, 
     middle pin to Vin+, and third pin to 5V).
  3) Upload the sketch to the Arduino.
  4) Open the Serial Communications Window (make sure the baud-rate is set to 9600).
  5) You should be able to see detailed feedback from running each of the possible functions of the library 
     (when you get to the part where readings are carried out, play with the potentiomer to check out changes 
     in the readings based on the input voltage).

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

#include <ADS1110.h>                          

const byte DEV_ADDR = 0x48;            // DEC: 72 - I2C address of the ADC1110 (CHANGE AS NEEDED)

ADS1110 ads1110(DEV_ADDR);

void setup() {
    Serial.begin(9600);
    Wire.begin();
    while(!Serial); 
    ads1110.reset();
    runTests();
}

void runTests() {
    printDivider();
    Serial.print(F("\nMCP9802 LIBRARY TESTING\n"));
    printDivider();
    testPing();
    testConMode();
    testRes();
    testSampleRate();
    testVref();
    testReset();
    testGetData();
    testGetVolt();
    testGetPercent();
    testGetComResult(); 
    Serial.print(F("\nDONE TESTING\n"));
    printDivider();
}

void loop() {}

void testPing() {
    String testResult;
    Serial.print(F("\nTESTING PING\n"));
    Serial.print(F("\nSearching for device... Device "));
    testResult = (ads1110.ping() ? "Not Found\n" : " Found!\n");
    Serial.print(testResult);
    printDivider();
    quickDelay();
}

void testConMode() {
    con_mode_t mode[2] = { SINGLE, CONT };
    String modeStr[2] = { "SINGLE-SHOT", "CONTINUOUS" };
    Serial.print(F("\nTESTING CONVERSION MODE\n"));
    for (byte i=0; i<2; i++) {
        Serial.print(F("\nSet Conversion Mode to:\t "));
        Serial.print(modeStr[i]);
        Serial.print(F("\n"));
        ads1110.setConMode(mode[i]);  
        testGetConMode();
    }
    printDivider();
    quickDelay();
}

void testRes() {
    res_t res[4] = { RES_12, RES_14, RES_15, RES_16 };
    byte resVal[4] = { 12, 14, 15, 16 };
    Serial.print(F("\nTESTING RESOLUTION\n"));
    for (byte i=0; i<4; i++) {
        Serial.print(F("\nSet Resolution to:\t "));
        Serial.print(resVal[i]);
        Serial.print(F("-BIT\n"));
        ads1110.setRes(res[i]);
        testGetRes();
    }
    printDivider();
    quickDelay(); 
}

void testSampleRate() {
    sample_rate_t rate[4] = { SPS_30, SPS_60, SPS_240, SPS_15 };
    byte rateVal[4] = { 30, 60, 240, 15 };
    Serial.print(F("\nTESTING SAMPLE RATE\n"));
    for (byte i=0; i<4; i++) {
        Serial.print(F("\nSet Sample Rate to:\t "));
        Serial.print(rateVal[i]);
        Serial.print(F(" SPS\n"));
        ads1110.setSampleRate(rate[i]);
        testGetSampleRate();
    }
    printDivider();
    quickDelay();
}

void testVref() {
    vref_t vRef[2] = { EXT_REF, INT_REF };
    String vRefStr[2] = { "EXTERNAL", "INTERNAL" };
    Serial.print(F("\nTESTING VOLTAGE REFERENCE\n"));
    for (byte i=0; i<2; i++) {
        Serial.print(F("\nSet Voltage Reference to: "));
        Serial.print(vRefStr[i]);
        Serial.print(F("\n"));
        ads1110.setVref(vRef[i]);
        testGetVref();
    }
    printDivider();
    quickDelay(); 
}

void testReset() {
    Serial.print(F("\nTESTING RESET\n"));
    Serial.print(F("\nChanging configuration to: SINGLE-SHOT, 14-BIT RESOLUTION, 60 SPS, EXTERNAL VOLTAGE REFERENCE..."));
    ads1110.setConMode(SINGLE);
    quickDelay(); 
    ads1110.setRes(RES_14);
    quickDelay();     
    ads1110.setVref(EXT_REF);
    Serial.print(F(" DONE!\n\nCurent Settings:\n"));
    testGetSettings();
    Serial.print(F("\nResetting Device..."));
    ads1110.reset();
    Serial.print(F(" DONE!\n\nCurent Settings:\n"));
    testGetSettings();
    printDivider();
}

void testGetSettings() {
    testGetConMode();
    testGetRes();
    testGetSampleRate();
    testGetVref();
}

void testGetConMode() {
    String currentMode = (ads1110.getConMode() ? "SINGLE-SHOT" : "CONTINUOUS");
    Serial.print(F("\nConversion Mode:\t "));
    Serial.print(currentMode);
    Serial.print(F("\n"));
}

void testGetRes() {
    byte currentRes = ads1110.getRes();
    Serial.print(F("\nResolution:\t\t "));
    Serial.print(currentRes);
    Serial.print(F("-BIT\n"));
}

void testGetSampleRate() {
    byte currentRate = ads1110.getSampleRate();
    Serial.print(F("\nSample Rate:\t\t "));
    Serial.print(currentRate);
    Serial.print(F(" SPS\n"));
}

void testGetVref() {
    String currentVref = (ads1110.getVref() ? "EXTERNAL\n" : "INTERNAL\n");  
    Serial.print(F("\nVoltage Reference:\t "));
    Serial.print(currentVref);
    Serial.print(F("\n"));
}

void testGetData() {
    int currentData;
    Serial.print(F("\nTESTING RAW DATA\n"));
    for (byte i=0; i<20; i++) {
        currentData = ads1110.getData();
        Serial.print(F("\nRaw Data\t\t "));
        Serial.print(currentData);
        Serial.print(F("\n"));
        longDelay(); 
    }
    printDivider();
}

void testGetVolt() {
    int mVolts;
    Serial.print(F("\nTESTING VOLTAGE READING\n"));
    for (byte i=0; i<20; i++) {
        mVolts = ads1110.getVolt();
        Serial.print(F("\nVoltage:\t\t "));
        Serial.print(mVolts);
        Serial.print(F("mV\n"));
    longDelay(); 
    }
    printDivider();
}

void testGetPercent() {
    byte percent;
    Serial.print(F("\nTESTING PERCENTAGE READING\n"));
    for (byte i=0; i<20; i++) {
        percent = ads1110.getPercent();
        Serial.print(F("\nPercentage:\t\t "));
        Serial.print(percent);
        Serial.print(F("%\n"));
    longDelay(); 
    }
    printDivider();
}

void testGetComResult() {
    byte comResult = ads1110.ping();
    Serial.print(F("\nTESTING I2C COMMUNICATION RESULT\n\nCalling device... "));
    Serial.print(F("Got I2C Communication Code: "));
    Serial.print(comResult);
    Serial.print(F("\n"));
    printDivider(); 
}

void printDivider() {
    Serial.print(F("\n--------------------------------------\n"));
}

void quickDelay() {
    delay(50);
}

void longDelay() {
    delay(750);
}
