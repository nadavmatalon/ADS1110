/* 
  ADS1110 LIBRARY - COMPLETE USAGE EXAMPLE SKETCH
  -----------------------------------------------

  This sketch exposes all the functions offered by the ADS1110 library as detailed below, thereby offering a quick & easy way of testing your ADS1110.

  INPORTANT: This library utilizes the 'WSWire' library (https://github.com/steamfire/WSWireLib/tree/master/Library/WSWire) for I2C communication with 
  the ADS1110, so it is NECESSARY to have it installed prior to using the current libraty. Alternatively, if you wish to use the 'Wire' library 
  (https://github.com/arduino/Arduino/tree/master/hardware/arduino/avr/libraries/Wire) - or any other I2C library for that matter - simply change 
  the following line the the 'ADS1110.h' file:
  
      #include <WSWire.h>
      
  to this:
  
      #include <Wire.h>  // or to whatever I2C library name you are using
      
  As noted above, whichever library you intend to use for this purpose must alredy be installed for the ADS1110 library to work.

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

   PIN 1 - Connect V+ to voltage source to be measured
   PIN 2 - Connect GND to Arduino GND
   PIN 3 - Connect SCL to Arduino PIN A5 with a 2K2 pull-up resistor
   PIN 4 - Conntect SDA to Arduino PIN A4 with a 2K2 pull-up resistor
   PIN 5 - Connect VCC to Arduino 5V output
   PIN 6 - Connect V- either to Arduino GND (for Single-Ended voltage readings ranging 0-2.048V)
           or to an external voltage reference of 2.048V (for Single-Ended voltage readings ranging 0-4.096V)
           or to 'negative' input (for differential voltage readings between positive and 'negative' inputs).
           (Note: the 'negative' input is put in brackets here because it isn't a 'real' negative voltage - 
            i.e. with relation to the circuit's common ground - only with relation to the positive input side!)
   DECOUPING: Connect a 0.1uF Ceramic Capacitor between VCC & GND PINS.

 
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

    #include <ADS1110.h>

  At this point you can construct a new ADS1110 object with the following line (place it at the top of the sketch 
  after the 'include' line):

    ADS1110 device_name(device_address);

   NOTE: replace the 'device_name' above with a name of your choice. Also, make sure to replace the variable 'device_address' with 
   the specific I2C address of your device (see I2C ADDRESSES section above).

  
  LIBRARY FUNCTIONS
  -----------------
  With the library installed & included in the sketch, and an ADS1110 object initiallized, the following functions are available 
  (see the sketch itself for actual usage examples):
  
    FUNCTION             PARAMETER/S                      DESCRIPTION                                                                 RETURNS
    --------             -----------                      -----------                                                                 -------
     ping();              ---                             Searches the I2C Bus for the device at the pre-defined address              Byte: 0 = Success / 1-6 = Error code
     getGain();           ---                             Gets the current Gain settings                                              Byte: 1 / 2 / 4 / 8
     setGain();           GAIN_1/GAIN_2/GAIN_4/GAIN_8     Sets the Gain (x1/x2/x4/x8, Default: x1)                                    ---
     getRate();           None                            Gets the current Sample Rate settings                                       Byte: 15 / 30 / 60 / 240
     setRate();           SPS_15/SPS_30/SPS_60/SPS_240    Sets the Sample Rate (15/30/60/240 Samples per second. Default: 15_SPS)     ---
     getMode();           ---                             Gets the current Conversion Mode settings                                   Byte: 0 = Continuous / 1 = Single-Shot
     setMode();           CONT/SINGLE                     Sets the Conversion Mode (CONTINUOUS/SINGLE-SHOT Default: CONTINUOUS)       ---
     getRes();            ---                             Gets the current Resolution settings                                        Byte: 12 / 14 / 15 / 16
     setRes();            12_BIT/14_BIT/15_BIT/16_BIT     Sets the Resolution level (12/14/15/16-BIT. Default: 16-BIT)                ---
     reset();             ---                             Resets the Configuration register to default settings                       --- 
     getData();           ---                             Gets the latest raw ADC reading                                             int
     getVolt();           ---                             Gets the latest ADC reading converted to mV                                 int
     getPercent();        ---                             Gets the latest ADC reading converted to Percent (0-100%)                   byte
     singleCon();         ---                             Initiates a single conversion and returns the ADC reading                   int
     getComResult();      ---                             Gets the result of the latest I2C communication with the device             Byte: 0 = Success / 1-6 = Error code
     configStr();         ---                             Generates a printable String with all current Configuration Settings        String

  NOTE: The ADS1110's Sample Rate and Resolution settings are interdependent, that is, setting the value of either will automatically 
  cause the other setting to change accordingly (15_SPS = 16-BIT / 30_SPS = 15-BIT / 60_SPS = 14-BIT / 240_SPS = 12-BIT)

  And, finally, to destruct an existing ADS1110 object, you can use the following line to do so:

    ~ADS1110 device_name();

  I2C COMMUNICATION RESULT CODES
  ------------------------------
    0 ... Success (no error)
    1 ... Buffer overflow
    2 ... Address sent, NACK received
    3 ... Data send, NACK received
    4 ... Other error (lost bus arbitration, bus error, etc.)
    5 ... Timed-out while trying to become Bus Master
    6 ... Timed-out while waiting for data to be sent

  RUNNING THE COMPLETE USAGE EXAMPLE SKETCH
  -----------------------------------------
  1) Hook-up the ADS1110 to the Arduino as described above.
  2) If you like, connect a 10K potentiometer to the ADS1110 V+ PIN (potentimeter's first pin goes to GND, 
     middle pin to V+, and third pin to 5V).
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
  This library is a free software; you can redistribute it and/or modify it under the terms of the 
  GNU General Public License as published by the Free Software Foundation; either version 3.0 of 
  the License, or any later version.This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
  PARTICULAR PURPOSE. See the GNU General Public License for more details.

*/

#include <ADS1110.h>                          // Include the ADS1110 Library code in the sketch

const int ADS1110_ADDR = 0x48;                // Decimal: 72 - I2C address of a the specific ADC1110 used (CHANGE VALUE AS NEEDED)
const unsigned int DELAY_TIME = 750;          // 750mS pause between testing of various methods
const unsigned int SHORT_DELAY_TIME = 200;    // 200mS pause between testing of various methods

ADS1110 ADS1110(ADS1110_ADDR);                // Construct the ADS1110 object with the pre-defined I2C address

String testResult;                            // Container of test feedback for printing in the Serial Monitor

void setup() {
    Serial.begin(9600);                       // Initiallize the Serial Port at 9600bd
    Wire.begin();                             // Join the the I2C Bus
    while(!Serial);                           // Wait for Serial Port to initialize
    takeAbreak();                             // Short pause
    ADS1110.reset();
    Serial.print(F("\nSerial Open\n"));       // Let us know Serial Port initialized
    Serial.print(F("\nSTART TESTING\n"));     // Let us know testing is done
    testPing();                               // Pings the ADS1110 to verify I2C communication has been established
    testGain();
    testRate();
    testMode();
    testRes();
    testReset();
    testVref();
    testConfigStr(); 
    testGetData();
    testGetVolt();
    testGetPercent();
    testSingleCon();
    testGetComResult(); 
    Serial.print(F("\nDONE TESTING\n"));         // Let us know testing is done
}

void loop() {}

void testPing() {
    Serial.println(F("\n\nTESTING PING"));
    Serial.print(F("\nPinging device... "));
    testResult = (ADS1110.ping() ? " No Response" : " Pong!");
    Serial.println(testResult);
    Serial.println(F("\n"));
    takeAbreak();
}

void testGain() {
    byte gain;
    gain_t gains[4] = { GAIN_2, GAIN_4, GAIN_8, GAIN_1 };
    byte gainsStr[4] = { 2, 4, 8, 1 };
    Serial.println(F("\nTESTING GAIN"));
    for (byte i=0; i<4; i++) {
        gain = ADS1110.getGain();
        Serial.print(F("\nCurrent Gain:  x"));
        Serial.println(gain);
        Serial.print(F("\nSet Gain to:   x"));
        Serial.println(gainsStr[i]);
        takeAbreak();
        ADS1110.setGain(gains[i]);
    }
    takeAbreak();
    gain = ADS1110.getGain();
    Serial.print(F("\nCurrent Gain:  x"));
    Serial.println(gain);
    Serial.print(F("\n"));
}

void testRate() {
    byte rate;
    rate_t rates[4] = { SPS_30, SPS_60, SPS_240, SPS_15 };
    byte ratesStr[4] = { 30, 60, 240, 15 };
    Serial.println(F("\nTESTING SAMPLE RATE\n"));
    for (byte i=0; i<4; i++) {
        rate = ADS1110.getRate();
        Serial.print(F("Current Sample Rate:  "));
        Serial.print(rate);
        Serial.println(F(" SPS\n"));
        Serial.print(F("Set Sample Rate to:   "));
        Serial.print(ratesStr[i]);
        Serial.println(F(" SPS\n"));
        takeAbreak();
        ADS1110.setRate(rates[i]);
    }
    takeAbreak();
    rate = ADS1110.getRate();
    Serial.print(F("Current Sample Rate:  "));
    Serial.print(rate);
    Serial.println(F(" SPS\n"));
}

void testMode() {
    String currentModeStr;
    Serial.println(F("\nTESTING CONVERSION MODE"));
    currentModeStr = ADS1110.getMode() ? "SINGLE-SHOT" : "CONTINUOUS";
    Serial.print(F("\nCurrent Mode:  "));
    Serial.println(currentModeStr);
    Serial.println(F("\nSet Mode to:   SINGLE-SHOT"));
    ADS1110.setMode(SINGLE);
    takeAbreak();
    currentModeStr = ADS1110.getMode() ? "SINGLE-SHOT" : "CONTINUOUS";
    Serial.print(F("\nCurrent Mode:  "));
    Serial.println(currentModeStr);
    Serial.println(F("\nSet Mode to:   CONTINUOUS"));
    ADS1110.setMode(CONT);
    takeAbreak();
    currentModeStr = ADS1110.getMode() ? "SINGLE-SHOT" : "CONTINUOUS";
    Serial.print(F("\nCurrent Mode:  "));
    Serial.println(currentModeStr);
    Serial.println(F(""));
    takeAbreak();
}

void testRes() {
    byte resolution;
    res_t resolutions[4] = { RES_12, RES_14, RES_15, RES_16 };
    byte resolutionsStr[4] = { 12, 14, 15, 16 };
    Serial.println(F("\nTESTING RESOLUTION\n"));
    for (byte i=0; i<4; i++) {
        resolution = ADS1110.getRes();
        Serial.print(F("Current Resolution:  "));
        Serial.print(resolution);
        Serial.println(F("-BIT\n"));
        takeAbreak();
        Serial.print(F("Set Resolution to:   "));
        Serial.print(resolutionsStr[i]);
        Serial.println(F("-BIT\n"));
        ADS1110.setRes(resolutions[i]);
    }
    takeAbreak();
    resolution = ADS1110.getRes();
    Serial.print(F("Current Resolution:  "));
    Serial.print(resolution);
    Serial.println("-BIT\n");
}

void testVref() {
    Serial.println(F("\nTESTING VOLTAGE REFERENCE"));
    Serial.print(F("\nCurrent Vref:  "));
    Serial.print(ADS1110.getVref() ? "EXTERNAL REFERENCE\n" : "INTERNAL REFERENCE\n");
    Serial.print(F("\nSet Vref to:   EXTERNAL REFERENCE\n"));
    ADS1110.setVref(EXT_REF);
    Serial.print(F("\nCurrent Vref:  "));
    Serial.print(ADS1110.getVref() ? "EXTERNAL REFERENCE\n" : "INTERNAL REFERENCE\n");
    Serial.print(F("\nSet Vref to:   INTERNAL REFERENCE\n"));
    ADS1110.setVref(INT_REF);
    Serial.print(F("\nCurrent Vref:  "));
    Serial.println(ADS1110.getVref() ? "EXTERNAL REFERENCE\n\n" : "INTERNAL REFERENCE\n\n");
}

void testReset() {
    byte gain, rate, mode, resolution;
    String currentModeStr;
    Serial.println(F("\nTESTING RESET\n"));
    Serial.print(F("Changing Settings to: GAIN x4, 60 SPS, SINGLE-SHOT, 14-BIT..."));
    ADS1110.setGain(GAIN_4);
    takeAquickBreak();
    ADS1110.setRate(SPS_60);
    takeAquickBreak();
    ADS1110.setMode(SINGLE);
    takeAquickBreak();
    Serial.println(F(" DONE!\n"));
    Serial.println(ADS1110.configStr());  
    Serial.print(F("\nRESETTING CONFIGURATION..."));
    ADS1110.reset();
    Serial.println(F(" DONE!\n"));
    takeAquickBreak();
    Serial.println(ADS1110.configStr());  
    takeAquickBreak();
}

void testConfigStr() {
    Serial.println(F("\nTESTING CONFIGURATION STRING"));
    Serial.print(F("\nGetting data and pringing config string...\n"));
    Serial.println(ADS1110.configStr());
    Serial.println(F(""));
    takeAquickBreak();
}

void testGetData() {
    int data;
    Serial.println(F("\nTESTING RAW DATA"));
    for (byte i=0; i<10; i++) {
        data = ADS1110.getData();
        Serial.print(F("\nRaw Data: "));
        Serial.println(data);
        takeAbreak();
    }
    Serial.println(F("\n"));
}

void testGetVolt() {
    int mVolt;
    Serial.println(F("\nTESTING VOLTAGE READING"));
    for (byte i=0; i<10; i++) {
        mVolt = ADS1110.getVolt();
        Serial.print(F("\nVoltage: "));
        Serial.print(mVolt);
        Serial.println(F("mV"));
        takeAbreak();
    }
    Serial.println(F("\n"));
}

void testGetPercent() {
    byte percent;
    Serial.println(F("\nTESTING PERCENTAGE READING"));
    for (byte i=0; i<10; i++) {
        percent = ADS1110.getPercent();
        Serial.print(F("\nPercentage: "));
        Serial.print(percent);
        Serial.println(F("%"));
        takeAbreak();
    }
    Serial.println(F("\n"));
}

void testSingleCon() {
    int singleConversion;
    Serial.println(F("\nTESTING SINGLE CONVERSION\n"));
    ADS1110.setMode(SINGLE);
    for (byte i=0; i<10; i++) {
        singleConversion = ADS1110.singleCon();
        Serial.print(F("\Raw Data: "));
        Serial.print(singleConversion);
        Serial.println(F("\n"));
        takeAbreak();
    }
    ADS1110.setMode(CONT);
}

void testGetComResult() {
      byte comResult;
      Serial.print(F("\nTESTING I2C COMMUNICATION RESULT\n\nCalling device..."));
      comResult = ADS1110.ping();
      Serial.print(F(" Got response: "));
      Serial.print(comResult);
      Serial.print(F(" ("));
      switch (comResult) {
          case(0): Serial.println(F("OK)")); break;
          case(1): Serial.println(F("ERROR: Buffer overflow)")); break;
          case(2): Serial.println(F("ERROR: Address sent, NACK received)")); break;
          case(3): Serial.println(F("ERROR: Data send, NACK received")); break;
          case(4): Serial.println(F("ERROR: Other error: lost bus arbitration, bus error, etc.)")); break;
          case(5): Serial.println(F("ERROR: Timed-out while trying to become Bus Master)")); break;
          case(6): Serial.println(F("ERROR: Timed-out while waiting for data to be sent)")); break;
      }
}

void takeAbreak() {
    delay(DELAY_TIME);
}

void takeAquickBreak() {
    delay(SHORT_DELAY_TIME);
}

