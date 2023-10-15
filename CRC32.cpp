// CRC32.cpp
#include "CRC32.h"

CRC32::CRC32() {
    for (uint16_t i = 0; i < 256; i++) {
        uint32_t c = i;
        for (uint8_t j = 0; j < 8; j++) {
            c = (c % 2 == 0) ? (c >> 1) : (0xEDB88320 ^ (c >> 1));
        }
        this->table[i] = c;
    }
}

uint32_t CRC32::calculate(uint8_t* buf, size_t len) {
    uint32_t crc = ~0;
    for (size_t i = 0; i < len; i++) {
        crc = (crc >> 8) ^ this->table[(crc ^ buf[i]) & 0xFF];
    }
    return ~crc;
}

void CRC32::calculateAndToBytes(uint8_t* buf, size_t len, uint8_t* output) {
    uint32_t crc = this->calculate(buf, len);
    output[0] = (crc >> 24) & 0xFF;
    output[1] = (crc >> 16) & 0xFF;
    output[2] = (crc >> 8) & 0xFF;
    output[3] = crc & 0xFF;
}