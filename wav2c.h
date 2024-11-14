#include <strings.h>
#include <stdio.h>

typedef struct {
char chunkID[4];
uint32_t chunkSize;
char format[4];
char subchunk1ID[4];
uint32_t subchunk1Size;
uint16_t audioFormat;
uint16_t numChannels;
uint32_t sampleRate;
uint16_t blockAlign;
uint16_t bitsPerSample;
char subchunk2ID[4];
uint32_t subchunk2Size;
} wavHeader;

typedef struct {
    wavHeader header;

    uint8_t const* data;
    uint32_t data_len;
} wavFile;