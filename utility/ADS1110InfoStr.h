/*==============================================================================================================*
 
    @file     ADS1110InfoStr.h
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon

    A complemetary Device Information String Generator Debugging Function for the ADS1110 Library

    Ver. 1.0.0 - First release (26.9.16)
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

#ifndef ADS1110InfoStr_h
#define ADS1110InfoStr_h

#include <avr/pgmspace.h>
#include "utility/ADS1110ComStr.h"

namespace Ads1110 {

    const int  INFO_BUFFER_SIZE = 60;
    const byte NUM_OF_INFO_STR  = 12;

    const char infoStr0[]  PROGMEM = "\nADS1110 DEVICE INFORMATION";
    const char infoStr1[]  PROGMEM = "\n--------------------------";
    const char infoStr2[]  PROGMEM = "\nI2C ADDRESS:\t %d (%#X)";
    const char infoStr3[]  PROGMEM = "\nI2C COM STATUS:\t %sCONNECTED";
    const char infoStr4[]  PROGMEM = "\nCONFIG BYTE:\t B%d%d%d%d%d%d%d%d";
    const char infoStr5[]  PROGMEM = "\nDEVICE MODE:\t %s";
    const char infoStr6[]  PROGMEM = "\nGAIN:\t\t x%d";
    const char infoStr7[]  PROGMEM = "\nRESOLUTION:\t %d-BIT";
    const char infoStr8[]  PROGMEM = "\nSAMPLE RATE:\t %d SPS";
    const char infoStr9[]  PROGMEM = "\nCONVERSION MODE: %s";
    const char infoStr10[] PROGMEM = "\nVOLTAGE REF:\t %s";
    const char errStr[]    PROGMEM = "\nI2C ERROR:\t ";

    const char * const infoStrs[NUM_OF_INFO_STR] PROGMEM = {
        infoStr0,
        infoStr1,
        infoStr2,
        infoStr3,
        infoStr4,
        infoStr5,
        infoStr6,
        infoStr7,
        infoStr8,
        infoStr9,
        infoStr10,
        errStr
    };

/*==============================================================================================================*
    GENERATE DEVICE INFORMATION STRING (PRINTABLE FORMAT)
 *==============================================================================================================*/

    ADS1110_PString ADS1110InfoStr(const ADS1110& devParams) {
        char * ptr;
        char  strBuffer[260];
        int   devAddr = devParams._devAddr;
        ADS1110 ads1110(devAddr);
        byte  config = ads1110.getConfig();
        byte  comErrCode = ads1110.ping();
        byte  res, rate;
        switch (config & SPS_MASK) {
            case (SPS_15):  res = 16; rate =  15; break;
            case (SPS_30):  res = 15; rate =  30; break;
            case (SPS_60):  res = 14; rate =  60; break;
            case (SPS_240): res = 12; rate = 240; break;
        }
        ADS1110_PString resultStr(strBuffer, sizeof(strBuffer));
        char  devInfoBuffer[INFO_BUFFER_SIZE];
        for (byte i=0; i<4; i++) {
            ptr = (char *) pgm_read_word(&infoStrs[i]);
            if (i < 2)   snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr);
            if (i == 2)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, devAddr, devAddr);
            if (i == 3)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (comErrCode ? "NOT " : ""));
            resultStr += devInfoBuffer;
        }
        if (!comErrCode) {
            for (byte i=4; i<(NUM_OF_INFO_STR - 1); i++) {
                ptr = (char *) pgm_read_word(&infoStrs[i]);
                if (i == 4)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (config >> 7)&1, (config >> 6)&1, (config >> 5)&1,
                                        (config >> 4)&1, (config >> 3)&1, (config >> 2)&1, (config >> 1)&1, config&1);
                if (i == 5)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (bitRead(config, 4)) ? "STANDBY" : "ON");
                if (i == 6)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (1 << (config & GAIN_MASK)));
                if (i == 7)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, res);
                if (i == 8)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, rate);
                if (i == 9)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (bitRead(config, 4)) ? "SINGLE-SHOT" : "CONTINUOUS");
                if (i == 10) snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (devParams._vref ? "EXTERNAL" : "INTERNAL"));
                resultStr += devInfoBuffer;
            }
        } else {
            snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, (char *) pgm_read_word(&infoStrs[11]));
            resultStr += devInfoBuffer;
            snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, (char *) pgm_read_word(&comCodes[comErrCode]));
            resultStr += devInfoBuffer;
            resultStr += "\n";
        }
        return resultStr;
    }
}

using namespace Ads1110;

#endif
