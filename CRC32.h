// CRC32.h
#ifndef CRC32_H
#define CRC32_H

#include <Arduino.h>

class CRC32 {
public:
    CRC32();
    uint32_t calculate(uint8_t* buf, size_t len);
    void calculateAndToBytes(uint8_t* buf, size_t len, uint8_t* output);
private:
    uint32_t table[256];
};

#endif