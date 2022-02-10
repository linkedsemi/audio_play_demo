#include <stdint.h>
#include <string.h>
#ifndef AUDIO_FORMAT_ADPCM_H_
#define AUDIO_FORMAT_ADPCM_H_

int Adpcm_Decode_Block(int16_t *outbuf, const uint8_t *inbuf, size_t inbufsize, int channels);
#endif
