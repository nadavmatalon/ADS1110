/*==============================================================================================================*
    ADS1110
*===============================================================================================================*

    @file     ADS1110.h
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon

    ADS1110 Driver (16-BIT Single Channel ADC with PGA and I2C Interface)

    Ver. 1.0.0 - First release (28.3.16)
    Ver. 1.1.0 - Major code refactoring (10.10.16)
    Ver. 1.2.0 - Added namespaces to prevent conflicts with other libraries (15.10.16)
    Ver. 1.3.0 - Switched from 'WSWire' library to 'Wire' library for I2C communications (24.10.16)

*===============================================================================================================*
    LICENSE
*===============================================================================================================*
 
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
 
*==============================================================================================================*/

#if 1
__asm volatile ("nop");
#endif

#include "ADS1110.h"

/*==============================================================================================================*
    CONSTRUCTOR
 *==============================================================================================================*/

ADS1110::ADS1110(byte devAddr) {
    _devAddr   = devAddr;
    _config    = DEFAULT_CONFIG;
    _vref      = INT_REF;
    _comBuffer = COM_SUCCESS;
}

/*==============================================================================================================*
    DESTRUCTOR
 *==============================================================================================================*/

ADS1110::~ADS1110() {}

/*==============================================================================================================*
    PING (0 = SUCCESS / 1-7 = I2C ERROR CODE)
 *==============================================================================================================*/

// See explication of error codes in the README

byte ADS1110::ping() {
    Wire.beginTransmission(_devAddr);
    return Wire.endTransmission();
}

/*==============================================================================================================*
    GET GAIN (1 = GAIN x1 / 2 = GAIN x2 / 4 = GAIN x4 / 8 = GAIN x8)
 *==============================================================================================================*/

byte ADS1110::getGain() {
    return (1 << (_config & GAIN_MASK));
}

/*==============================================================================================================*
    GET SAMPLE RATE (15 = 15 SPS / 30 = 30 SPS / 60 = 60 SPS / 240 = 240 SPS)
 *==============================================================================================================*/

byte ADS1110::getSampleRate() {
    switch (_config & SPS_MASK) {
        case (SPS_15):  return  15; break;
        case (SPS_30):  return  30; break;
        case (SPS_60):  return  60; break;
        case (SPS_240): return 240; break;
    }
}

/*==============================================================================================================*
    GET CONVERSION MODE (0 = CONTINUOUS / 1 = SINGLE-SHOT)
 *==============================================================================================================*/

byte ADS1110::getConMode() {
    return bitRead(_config, 4);
}

/*==============================================================================================================*
    GET RESOLUTION (12 = 12-BIT / 14 = 14-BIT / 15 = 15-BIT / 16 = 16-BIT)
 *==============================================================================================================*/

byte ADS1110::getRes() {
    switch (_config & SPS_MASK) {
        case (SPS_15):  return 16; break;
        case (SPS_30):  return 15; break;
        case (SPS_60):  return 14; break;
        case (SPS_240): return 12; break;
    }
}

/*==============================================================================================================*
    GET VOLTAGE REFERENCE (0 = INTERNAL / 2048 = EXTERNAL)
 *==============================================================================================================*/

int ADS1110::getVref() {
    return _vref;
}

/*==============================================================================================================*
    SET GAIN
 *==============================================================================================================*/

void ADS1110::setGain(gain_t newGain) {                          // PARAMS: GAIN_1 / GAIN_2 / GAIN_4 / GAIN_8
    setConfig((_config & ~GAIN_MASK) | (newGain & GAIN_MASK));
}

/*==============================================================================================================*
    SET SAMPLE RATE (IN SAMPLES PER SECOND)
 *==============================================================================================================*/

void ADS1110::setSampleRate(sample_rate_t newRate) {             // PARAMS: SPS_15 / SPS_30 / SPS_60 / SPS_240
    setConfig((_config & ~SPS_MASK) | (newRate & SPS_MASK));
}

/*==============================================================================================================*
    SET CONVERSION MODE
 *==============================================================================================================*/

void ADS1110::setConMode(con_mode_t newConMode) {                            // PARAMS: CONT / SINGLE
    setConfig(newConMode ? bitSet(_config, 4) : bitClear(_config, 4));
}

/*==============================================================================================================*
    SET RESOLUTION
 *==============================================================================================================*/

void ADS1110::setRes(res_t newRes) {                             // PARAMS: 12_BIT / 14_BIT / 15_BIT / 16_BIT
    switch (newRes) {
        case (RES_12): setConfig((_config & ~SPS_MASK) | (SPS_240 & SPS_MASK)); break;
        case (RES_14): setConfig((_config & ~SPS_MASK) | (SPS_60  & SPS_MASK)); break;
        case (RES_15): setConfig((_config & ~SPS_MASK) | (SPS_30  & SPS_MASK)); break;
        case (RES_16): setConfig((_config & ~SPS_MASK) | (SPS_15  & SPS_MASK)); break;
    }
}

/*==============================================================================================================*
    SET VOLTAGE REFERENCE
 *==============================================================================================================*/

void ADS1110::setVref(vref_t newVref) {                         // PARAMS: INT_REF / EXT_REF
    _vref = newVref;
}

/*==============================================================================================================*
    RESET
 *==============================================================================================================*/

void ADS1110::reset() {
    setConfig(DEFAULT_CONFIG);
    _vref = INT_REF;
}

/*==============================================================================================================*
    GET DATA FROM DEVICE
 *==============================================================================================================*/

int ADS1110::getData() {
    byte devConfig;
    int  devData;
    byte attemptCount = 0;
    if (bitRead(_config, 4)) {                                  // if device is in 'SINGLE-SHOT' mode...
        initCall(_config | START_CONVERSION);                   // add start conversion command to config byte 
        endCall();                                              // issue start conversion command
        delay(MIN_CON_TIME * findMinCode(_config & SPS_MASK));  // wait for conversion to complete
    }
    while (attemptCount < MAX_NUM_ATTEMPTS) {                   // make up to 3 attempts to get new data
        Wire.requestFrom(_devAddr, NUM_BYTES);                  // request 3 bytes from device
        if (Wire.available() == NUM_BYTES) {                    // if 3 bytes were recieved...
            devData = Wire.read() << 8 | Wire.read();           // read data register
            devConfig = Wire.read();                            // read config register
            if (bitRead(devConfig, 7)) {                        // check if new data available...
                delay(MIN_CON_TIME);                            // if not available yet, wait a bit longer
                attemptCount++;                                 // increment attemps count
            } else return devData;                              // if new data is available, return conversion result
        } else {                                                // if 3 bytes were not recieved...
            emptyBuffer();                                      // empty I2C buffer
            _comBuffer = ping();                                // store I2C error code to find out what went wrong
            attemptCount = MAX_NUM_ATTEMPTS;                    // exit while loop
        }
    }
    return 0;                                                   // if operation unsuccessful, return 0
}

/*==============================================================================================================*
    GET VOLTAGE (mV)
 *==============================================================================================================*/

    // Vin+ = (output_code / (my_min_code  * GAIN)) + _Vreg
    // Output_Code = raw data from device (int)
    // my_min_code = 16 (15_SPS; 16-BIT) / 8 (30_SPS; 15-BIT) / 4 (60_SPS; 14-BIT) / 1 (240_SPS; 12-BIT)
    // _Vref = Vin- (in mV, depends on whether Vin- is connected to GND or to a 2048mV reference source)
    // Vin+ = 0 - 2048mV when Pin Vin- (=_Vref) is connected to GND
    // Vin+ = 0 - 4096mV when Pin Vin- (=_Vref) is connected to an external 2.048V reference source

int ADS1110::getVolt() {
    byte gain = (1 << (_config & GAIN_MASK));
    byte minCode = findMinCode(_config & SPS_MASK);
    return (round((float)getData() / (float)(minCode * gain)) + _vref);
}

/*==============================================================================================================*
    GET PERCENTAGE (0-100%)
 *==============================================================================================================*/

byte ADS1110::getPercent() {
    int lowerLimit = (findMinCode(_config & SPS_MASK) << 11) * -1;
    int upperLimit = (findMinCode(_config & SPS_MASK) << 11) - 1;
    return round(mapf(getData(), lowerLimit, upperLimit, 0, 100));
}

/*==============================================================================================================*
    GET COMMUNICATION RESULT
 *==============================================================================================================*/

byte ADS1110::getComResult() {
    return _comBuffer;
}

/*==============================================================================================================*
    GET CONFIGURATION SETTINGS (FROM DEVICE)
 *==============================================================================================================*/

byte ADS1110::getConfig() {
    byte devConfig;
    Wire.requestFrom(_devAddr, NUM_BYTES);              // request 3 bytes from device
    if (Wire.available() == NUM_BYTES) {                // if 3 bytes were recieved...
        for (byte i=2; i>0; i--) Wire.read();           // skip data register bytes
        devConfig = Wire.read();                        // store device config byte
    } else {                                            // if 3 bytes were not recieved...
        emptyBuffer();                                  // empty I2C buffer
        _comBuffer = ping();                            // store I2C error code to find out what went wrong
    }
    return devConfig;                                   // return device config byte
}

/*==============================================================================================================*
    SET CONFIGURATION REGISTER
 *==============================================================================================================*/

void ADS1110::setConfig(byte newConfig) {
    initCall(newConfig);
    endCall();
    if (_comBuffer == COM_SUCCESS) _config = newConfig;
}

/*==============================================================================================================*
    FIND MINIMAL CODE (BASED ON SAMPLE RATE)
 *==============================================================================================================*/

byte ADS1110::findMinCode(sample_rate_t sampleRate) {
    switch (sampleRate) {
        case (SPS_15) : return MIN_CODE_15;  break;
        case (SPS_30) : return MIN_CODE_30;  break;
        case (SPS_60) : return MIN_CODE_60;  break;
        case (SPS_240): return MIN_CODE_240; break;
    }
}

/*==============================================================================================================*
    MAP FLOATING POINT HELPER FUNCTION (FOR PERCENT CALCULATION)
 *==============================================================================================================*/

double ADS1110::mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return ((val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

/*==============================================================================================================*
    INITIATE I2C COMMUNICATION
 *==============================================================================================================*/

void ADS1110::initCall(byte data) {
    Wire.beginTransmission(_devAddr);
    Wire.write(data);
}

/*==============================================================================================================*
    END I2C COMMUNICATION
 *==============================================================================================================*/

void ADS1110::endCall() {
    _comBuffer = Wire.endTransmission();
}

/*==============================================================================================================*
    EMPTY I2C BUFFER
 *==============================================================================================================*/

void ADS1110::emptyBuffer() {
    while (Wire.available()) Wire.read();
}
