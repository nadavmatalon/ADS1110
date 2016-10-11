/*==============================================================================================================*
    ADS1110
*===============================================================================================================*

    @file     ADS1110.h
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon

    ADS1110 Driver (16-BIT Single Channel ADC with PGA and I2C Interface)

    Ver. 1.0.0 - First release (28.3.16)
    Ver. 1.1.0 - (10.10.16)

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

#include "ADS1110.h"

/*==============================================================================================================*
    CONSTRUCTOR
 *==============================================================================================================*/

ADS1110::ADS1110(int address) {
    _devAddr = address;
    _vref = INT_REF;
}

/*==============================================================================================================*
    DESTRUCTOR
 *==============================================================================================================*/

ADS1110::~ADS1110() {}

/*==============================================================================================================*
    PING (0 = SUCCESS / 1-6 = ERROR CODE)
 *==============================================================================================================*/

byte ADS1110::ping() {
    Wire.beginTransmission(_devAddr);
    endCall();
    return _comBuffer;
}

/*==============================================================================================================*
    GET GAIN (1 = GAIN_1 / 2 = GAIN_2 / 4 = GAIN_4 / 8 = GAIN_8)
 *==============================================================================================================*/

byte ADS1110::getGain() {
    return (1 << (getConfig() & GAIN_MASK));
}

/*==============================================================================================================*
    SET GAIN (GAIN_1 / GAIN_2 / GAIN_4 / GAIN_8)
 *==============================================================================================================*/

void ADS1110::setGain(gain_t newGain) {
    setConfig((getConfig() & ~GAIN_MASK) | (newGain & GAIN_MASK));
}

/*==============================================================================================================*
    GET SAMPLE RATE (15 = SPS_15 / 30 = SPS_30 / 60 = SPS_60 / 240 = SPS_240)
 *==============================================================================================================*/

byte ADS1110::getRate() {
    switch (getConfig() & SPS_MASK) {
        case (SPS_15):  return  15; break;
        case (SPS_30):  return  30; break;
        case (SPS_60):  return  60; break;
        case (SPS_240): return 240; break;
    }
}

/*==============================================================================================================*
    SET SAMPLE RATE (SPS_15 / SPS_30 / SPS_60 / SPS_240)
 *==============================================================================================================*/

void ADS1110::setRate(rate_t newRate) {
    setConfig((getConfig() & ~SPS_MASK) | (newRate & SPS_MASK));
}

/*==============================================================================================================*
    GET MODE (0 = CONTINUOUS / 1 = SINGLE-SHOT)
 *==============================================================================================================*/

byte ADS1110::getMode() {
    return ((getConfig() & MODE_MASK) >> 4);
}

/*==============================================================================================================*
    SET MODE (CONT / SINGLE)
 *==============================================================================================================*/

void ADS1110::setMode(mode_t newMode) {
    setConfig((getConfig() & ~MODE_MASK) | (newMode & MODE_MASK));
}

/*==============================================================================================================*
    GET RESOLUTION (12 = 12-BIT / 14 = 14-BIT / 15 = 15-BIT / 16 = 16-BIT)
 *==============================================================================================================*/

byte ADS1110::getRes() {
    switch (getConfig() & SPS_MASK) {
        case (SPS_15):  return 16; break;
        case (SPS_30):  return 15; break;
        case (SPS_60):  return 14; break;
        case (SPS_240): return 12; break;
    }
}

/*==============================================================================================================*
    SET RESOLUTION (12_BIT / 14_BIT / 15_BIT / 16_BIT)
 *==============================================================================================================*/

void ADS1110::setRes(res_t newRes) {
    switch (newRes) {
        case (RES_12): setConfig((getConfig() & ~SPS_MASK) | (SPS_240 & SPS_MASK)); break;
        case (RES_14): setConfig((getConfig() & ~SPS_MASK) | (SPS_60  & SPS_MASK)); break;
        case (RES_15): setConfig((getConfig() & ~SPS_MASK) | (SPS_30  & SPS_MASK)); break;
        case (RES_16): setConfig((getConfig() & ~SPS_MASK) | (SPS_15  & SPS_MASK)); break;
    }
}

/*==============================================================================================================*
    GET VOLTAGE REFERENCE (0 = INTERNAL / 2048 = EXTERNAL)
 *==============================================================================================================*/

int ADS1110::getVref() {
    return _vref;
}

/*==============================================================================================================*
    SET VOLTAGE REFERENCE (INT_REF / EXT_REF)
 *==============================================================================================================*/

void ADS1110::setVref(vref_t newVref) {
    _vref = newVref;
}

/*==============================================================================================================*
    RESET
 *==============================================================================================================*/

void ADS1110::reset() {
    setConfig(DEFAULT_SETTINGS);
}

/*==============================================================================================================*
    GET DATA
 *==============================================================================================================*/

int ADS1110::getData() {
    union Data { int i; byte b[2]; } data;
    if (requestData() == NUM_BYTES)  {
        data.b[1] = Wire.read();
        data.b[0] = Wire.read();
        Wire.read();
    } else emptyBuffer();
    return data.i;
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
    byte config, gain, minCode;
    int voltage;
    union Data { int i; byte b[2]; } data;
    if (requestData() == NUM_BYTES) {
        data.b[1] = Wire.read();
        data.b[0] = Wire.read();
        config = Wire.read();
        gain = (1 << (config & GAIN_MASK));
        minCode = findMinCode(config & SPS_MASK);
        voltage = round((float)data.i / (float)(minCode * gain)) + _vref;
    }
    return voltage;
}

/*==============================================================================================================*
    GET PERCENTAGE (0-100%) (SINGLE-ENDED READING ONLY)
 *==============================================================================================================*/

byte ADS1110::getPercent() {
    byte config, gain, percent;
    unsigned int upperLimit;
    union Data { int i; byte b[2]; } data;
    if (requestData() == NUM_BYTES) {
        data.b[1] = Wire.read();
        data.b[0] = Wire.read();
        config = Wire.read();
        upperLimit = (findMinCode(config & SPS_MASK) << 11) - 1;
        percent = round(data.i * 100.0 / (float)upperLimit);
    }
    return percent;
}

/*==============================================================================================================*
    PERFORM A SINGLE CONVERSION (IN 'SINGLE-SHOT' MODE ONLY)
 *==============================================================================================================*/

int ADS1110::singleCon() {
    initCall(START_CONVERSION);
    endCall();
    delay(CONVERSION_TIME);             // change to match different resolutions
    return getData();
}

/*==============================================================================================================*
    GET COMMUNICATION RESULT
 *==============================================================================================================*/

byte ADS1110::getComResult() {
    return _comBuffer;
}

/*==============================================================================================================*
    CONFIGURATION INFO
 *==============================================================================================================*/

String ADS1110::configStr() {
    byte config, rate, res, vref;
    config = getConfig();
    switch (getConfig() & SPS_MASK) {
        case (SPS_15):  rate =  15; res = 16; break;
        case (SPS_30):  rate =  30; res = 15; break;
        case (SPS_60):  rate =  60; res = 14; break;
        case (SPS_240): rate = 240; res = 12; break;
    }
    return "\nADS1110 CONFIGURATION DATA \nI2C Address:  " + String(_devAddr) +
    "\nGAIN:         x" + String(1 << (config & GAIN_MASK)) +
    "\nSAMPLE RATE:  "   + String(rate) + " SPS" +
    "\nMODE:         "   + (((config & MODE_MASK) >> 4) ? "SINGLE-SHOT" : "CONTINUOUS") +
    "\nRESOLUTION:   "   + String(res) + "-BIT" +
    "\nVOLTAGE REF:  "   + (getVref() ? "EXTERNAL" : "INTERNAL");
}

/*==============================================================================================================*
    GET CONFIGURATION REGISTER
 *==============================================================================================================*/

byte ADS1110::getConfig() {
    byte config;
    if (requestData() == NUM_BYTES) {
        for (byte i=2; i>0; i--) Wire.read();
        config = Wire.read();
    } else emptyBuffer();
    return config;
}

/*==============================================================================================================*
    SET CONFIGURATION REGISTER
 *==============================================================================================================*/

void ADS1110::setConfig(byte newConfig) {
    initCall(newConfig);
    endCall();
}

/*==============================================================================================================*
    FIND MINIMAL CODE (BASED ON SAMPLE RATE)
 *==============================================================================================================*/

byte ADS1110::findMinCode(byte sampleRate) {
    switch (sampleRate) {
        case (SPS_15) : return MIN_CODE_15;  break;
        case (SPS_30) : return MIN_CODE_30;  break;
        case (SPS_60) : return MIN_CODE_60;  break;
        case (SPS_240): return MIN_CODE_240; break;
    }
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
    REQUEST DATA
 *==============================================================================================================*/

byte ADS1110::requestData() {
    Wire.requestFrom(_devAddr, NUM_BYTES);
    return Wire.available();
}

/*==============================================================================================================*
    EMPTY I2C BUFFER
 *==============================================================================================================*/

void ADS1110::emptyBuffer() {
    while (Wire.available()) Wire.read();
}
