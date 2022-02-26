#include <stdint.h>
#include "lsdmac.h"
#include "audio_hw.h"

static DMA_RAM_ATTR uint8_t Buf0[SINGLE_BUF_SIZE];
static DMA_RAM_ATTR uint8_t Buf1[SINGLE_BUF_SIZE];
#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL 
static DMA_RAM_ATTR uint8_t Buf2[SINGLE_BUF_SIZE];
static DMA_RAM_ATTR uint8_t Buf3[SINGLE_BUF_SIZE];
#endif

uint8_t *get_pcm_buf0(void)
{
    return &Buf0[0];
}
uint8_t *get_pcm_buf1(void)
{
    return &Buf1[0];
}

uint8_t *get_pcm_buf2(void)
{
#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL
    return &Buf2[0];
#else
    return NULL;
#endif
}
uint8_t *get_pcm_buf3(void)
{
#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL
    return &Buf3[0];
#else
    return NULL;
#endif
}

uint16_t get_single_buf_size(void)
{
    return SINGLE_BUF_SIZE;
}

uint16_t get_pcm_buf_size(void)
{
    return PCM_BUF_SIZE;
}
