/*==============================================================================================================*

    @file     ADS1110InfoStr.h
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon
 
    A complemetary Device Information String Generator Debugging Function for the ADS1110 Library
 
    Ver. 1.0.0 - First release (28.3.16)
    Ver. 1.1.0 -  (10.10.16)

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

#ifndef ADS1110InfoStr_h
#define ADS1110InfoStr_h

#include <avr/pgmspace.h>
#include "utility/ADS1110ComStr.h"

const int  INFO_BUFFER_SIZE = 60;
const byte NUM_OF_INFO_STR  = 15;

const char infoStr0[]  PROGMEM = "\nADS1110 DEVICE INFORMATION";
const char infoStr1[]  PROGMEM = "\n--------------------------";
const char infoStr2[]  PROGMEM = "\nI2C ADDRESS:\t %d (%#X)";
const char infoStr3[]  PROGMEM = "\nI2C COM STATUS:\t %sCONNECTED";
const char infoStr4[]  PROGMEM = "\nCONFIG BYTE:\t B%d%d%d%d%d%d%d%d";
const char infoStr5[]  PROGMEM = "\nDEVICE MODE:\t %s";
const char infoStr9[]  PROGMEM = "\nRESOLUTION:\t %d-BIT";
const char infoStr10[] PROGMEM = "\nCONVERSION MODE: %s";
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
    infoStr11,
    infoStr12,
    infoStr13,
    errStr
};

/*==============================================================================================================*
    GENERATE DEVICE INFORMATION STRING (PRINTABLE FORMAT)
 *==============================================================================================================*/

PString ADS1110InfoStr(const ADS1110& devParams) {
    char * ptr;
    char strBuffer[338];
    int  devAddr = devParams._devAddr;
    ADS1110 ads1110(devAddr);
    byte comErrCode = ads1110.ping();
    PString resultStr(strBuffer, sizeof(strBuffer));
    char devInfoBuffer[INFO_BUFFER_SIZE];
    byte tempUnit = devParams._tempUnit;
    byte  config = devParams._singleConfig ? devParams._singleConfig : ads1110.getConfig();
    byte  fqVal = (config & 0x18) >> 2;
    float hyst = ads1110.getHyst();
    float limit = ads1110.getLimit();
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
            if (i == 5)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (config ? "STANDBY" : "ON"));
            if (i == 6)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, ((config >> 1)&1 ? "INTERRUPT": "COMPARATOR"));
            if (i == 7)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, ((config >> 2)&1 ? "HIGH": "LOW"));
            if (i == 8)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (fqVal ? fqVal : 1), (fqVal ? "S" : ""));
            if (i == 9)  snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (((config & 0x60) >> 5) + 9));
            if (i == 10) snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (config ? "SINGLE-SHOT" : "CONTINUOUS"));
            if (i == 11) snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (tempUnit ? "FAHRENHEIT" : "CELSIUS"));
            if (i == 12) snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (int)hyst, abs((int)(hyst * 10) % 10), (tempUnit ? "F" : "C"));
            if (i == 13) snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, ptr, (int)limit, abs((int)(limit * 10) % 10), (tempUnit ? "F" : "C"));
            resultStr += devInfoBuffer;
        }
    } else {
        snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, (char *) pgm_read_word(&infoStrs[14]));
        resultStr += devInfoBuffer;
        snprintf_P(devInfoBuffer, INFO_BUFFER_SIZE, (char *) pgm_read_word(&comCodes[comErrCode]));
        resultStr += devInfoBuffer;
        resultStr += "\n";
    }
    return resultStr;
}

#endif
