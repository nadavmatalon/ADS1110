/*
ADS1110_PString.cpp - Lightweight printable string class
Original Code by: Mikal Hart (http://arduiniana.org/libraries/PString/)
*/

#if 1
__asm volatile ("nop");
#endif

#include "ADS1110_PString.h"

void ADS1110_PString::begin() {
    _cur = _buf;
    if (_size > 0)
        _buf[0] = '\0';
}

#if defined(ARDUINO) && ARDUINO >= 100
    size_t ADS1110_PString::write(uint8_t b)
    #else
    void ADS1110_PString::write(uint8_t b)
#endif
{
    if (_cur + 1 < _buf + _size) {
        *_cur++ = (char)b;
        *_cur = '\0';
        #if defined(ARDUINO) && ARDUINO >= 100
            return 1;
        #endif
    }
    #if defined(ARDUINO) && ARDUINO >= 100
        return 0;
    #endif
}

int ADS1110_PString::format(char *str, ...) {
    va_list argptr;
    va_start(argptr, str);
    int ret = vsnprintf(_cur, _size - (_cur - _buf), str, argptr);
    if (_size)
        while (*_cur)
            ++_cur;
    return ret;
}
