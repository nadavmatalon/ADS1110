/*==============================================================================================================*
    ADS1110
*===============================================================================================================*

    @file     ADS1110.h
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon

    ADS1110 Driver (16-BIT Single Channel ADC with PGA and I2C Interface)
 
    Ver. 1.0.0 - First release (28.3.16)
    Ver. 1.1.0 -  (10.10.16)

*===============================================================================================================*
    INTRODUCTION
*===============================================================================================================*

    The ADS1110 is a 16-Bit Single-Channel Temperature Sensor with Hysteresis & Alert capabilities,
    as well as a hardware I2C interface.
 
    This library contains a complete driver for the ADS1110 offering full control over its Configuration 
    Settings, as well as the ability to recieve raw data, voltage readings (in mV, to avoid floating point 
    math) or percentage readings in either Single-Shot or Continuous mode.
 
*===============================================================================================================*
    I2C ADDRESSES
*===============================================================================================================*

    Each ADS1110 has 1 of 8 possible I2C addresses (factory hardwired & recognized by its specific
    part number & top marking on the package itself):

    PART               DEVICE I2C ADDRESS          PART
    NUMBER           BIN        HEX       DEC      MARKING
    ---------       -------      ----      ---      -------
    ADS1110A0       1001000      0x48       72        ED0
    ADS1110A1       1001001      0x49       73        ED1
    ADS1110A2       1001010      0x4A       74        ED2
    ADS1110A3       1001011      0x4B       75        ED3
    ADS1110A4       1001100      0x4C       76        ED4
    ADS1110A5       1001101      0x4D       77        ED5
    ADS1110A6       1001110      0x4E       78        ED6
    ADS1110A7       1001111      0x4F       79        ED7

*===============================================================================================================*
    POWER-UP DEFAULTS
*===============================================================================================================*

    CONFIG BYTE:        B00000000
    ALERT OUTPUT TYPE:  COMPARATOR
    ALERT OUTPUT MODE:  ACTIVE-LOW
    FAULT-QUEUE:        1 FAULT
    RESOLUTION:         9-BIT
    CONVERSION MODE:    CONTINUOUS

*===============================================================================================================*
    CONFIGURATION REGISTER
*===============================================================================================================*

    BITS 0 & 1: GAIN (PGA1 & PGA0)

    GAIN_1           0x80           PGA 1                           B00000000 (Default)
    GAIN_2           0x81           PGA 2                           B00000001
    GAIN_4           0x82           PGA 4                           B00000010
    GAIN_8           0x83           PGA 8                           B00000011

    BITS 2 & 3: DATA RATE (DR1 & DR0)

    SPS_15           0x8C           15 Samples per Second           B00001100 (Default)
    SPS_30           0x88           30 Samples per Second           B00001000
    SPS_60           0x84           60 Samples per Second           B00000100
    SPS_240          0x80          240 Samples per Second           B00000000

    BIT 4: CONVERSION MODE (SC)

    CONT             0x80           Continuous Mode                 B10000000 (Default)
    SINGLE           0x90           Single-Shot Mode                B10010000

    BITS 5 & 6: RESERVED

    BIT 7 (READ): DATA STATUS (ST) - NOT IMPLEMENTED

    NEW_DATA         0x00           New data ready to be read       B00000000
    NO_DATA          0x80           No new data avialable           B10000000 (Default)

    BIT 7 (WRITE): START CONVERSION (DRDY)

    SC               0x80           Start Conversion (Single-Shot Mode Only)      B10000000

*===============================================================================================================*
    MINIMAL DATA VALUES (BASED ON SAMPLE RATE)
*===============================================================================================================*

    MIN_CODE_15    0x01     -1 * Minimum data value for 15  / 2048 (16-Bit)
    MIN_CODE_30    0x04     -1 * Minimum data value for 30  / 2048 (15-Bit)
    MIN_CODE_60    0x08     -1 * Minimum data value for 60  / 2048 (14-Bit)
    MIN_CODE_240   0x10     -1 * Minimum data value for 240 / 2048 (12-Bit)

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

#ifndef ADS1110_h
#define ADS1110_h

#if defined(ARDUINO_ARCH_AVR)
#include <Arduino.h>
#include "WSWire.h"
#include "utility/PString.h"
#else
#error “The ADS1110 library only supports AVR processors.”
#endif

const byte DEFAULT_SETTINGS = 0x8C;      // B10001100 (16-BIT, 15 SPS, GAIN x1, CONTINUOUS)
const byte START_CONVERSION = 0x80;      // B10000000 (For 'Single-Shot' Mode Only)
const byte CONVERSION_TIME  =   70;      // ADC Comversion time (in mS)
const int  NUM_BYTES        =    3;      // Fixed number of bytes requested from the device

typedef enum:byte {
    GAIN_MASK = 0x03,      // B00000011
    GAIN_1    = 0x00,      // B00000000 (Default)
    GAIN_2    = 0x01,      // B00000001
    GAIN_4    = 0x02,      // B00000010
    GAIN_8    = 0x03       // B00000011
} gain_t;

typedef enum:byte {
    SPS_MASK = 0x0C,       // B00001100
    SPS_15   = 0x0C,       // 12 - B00001100 (Default)
    SPS_30   = 0x08,       //  8 - B00001000
    SPS_60   = 0x04,       //  4 - B00000100
    SPS_240  = 0x00        //  0 - B00000000
} rate_t;

typedef enum:byte {
    MODE_MASK = 0x10,      // B00010000
    CONT      = 0x00,      // B00000000 (Defualt)
    SINGLE    = 0x10       // B00010000
} mode_t;

typedef enum:byte {
    MIN_CODE_240 = 0x01,   //  1 - Minimal Data Value for 240_SPS / -2048  (12-BIT)
    MIN_CODE_60  = 0x04,   //  4 - Minimal Data Value for 60_SPS  / -2048  (14-BIT)
    MIN_CODE_30  = 0x08,   //  8 - Minimal Data Value for 30_SPS  / -2048  (15-BIT)
    MIN_CODE_15  = 0x10    // 16 - Minimal Data Value for 15_SPS  / -2048  (16-BIT) (Default)
} min_code_t;

typedef enum:byte {
    RES_12,                // 12-BIT Resolution
    RES_14,                // 14-BIT Resolution
    RES_15,                // 15-BIT Resolution
    RES_16                 // 16-BIT Resolution (Default)
} res_t;

typedef enum:int {
    INT_REF =    0,        // Inernal Reference: Pin Vin- is connected to GND (Default)
    EXT_REF = 2048         // External Reference: Pin Vin- is connected to 2.048V source
} vref_t;

class ADS1110 {
    public:
        ADS1110(int address);
        ~ADS1110();
        byte   ping();
        byte   getGain();
        void   setGain(gain_t newGain);
        byte   getRate();
        void   setRate(rate_t newRate);
        byte   getMode();
        void   setMode(mode_t newMode);
        byte   getRes();
        void   setRes(res_t newRes);
        int    getVref();
        void   setVref(vref_t newVref);
        void   reset();
        int    getData();
        int    getVolt();
        byte   getPercent();
        int    singleCon();
        byte   getComResult();
        String configStr();
    private:
        int    _devAddr;
        byte   _comBuffer;
        int    _vref;
        byte   getConfig();
        void   setConfig(byte newConfig);
        byte   findMinCode(byte sampleRate);
        void   initCall(byte data);
        void   endCall();
        byte   requestData();
        void   emptyBuffer();
};

#endif
