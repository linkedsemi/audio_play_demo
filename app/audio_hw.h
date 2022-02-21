#include "compile_flag.h"
#include "user_audio_config.h"
#ifndef AUDIO_HW_H_
#define AUDIO_HW_H_

#define RESOLUTION_DEFAULT 8

_Static_assert(RESOLUTION_DEFAULT <= USER_AUDIO_RESOLUTION*8, "The resolution is not supported!!!");

#if USER_AUDIO_FORMAT == AUDIO_ADPCM
#define PCM_BUF_SIZE 1010

#elif USER_AUDIO_FORMAT == AUDIO_PCM
#define PCM_BUF_SIZE 512
#elif USER_AUDIO_FORMAT == AUDIO_SBC

#elif USER_AUDIO_FORMAT == AUDIO_OPUS

#endif

#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL
#define RESOLUTION_ACTUAL (RESOLUTION_DEFAULT - 1)
#else // AUDIO_OUTPUT_MODE_SINGLE_END
#define RESOLUTION_ACTUAL RESOLUTION_DEFAULT
#endif

#if RESOLUTION_ACTUAL > 8
#define SINGLE_BUF_SIZE PCM_BUF_SIZE
#else 
#define SINGLE_BUF_SIZE (PCM_BUF_SIZE/(USER_AUDIO_RESOLUTION))
#endif

#define TIMER_REPETITION_COUNTER_INIT ((SDK_HCLK_MHZ * 1000000) / (USER_AUDIO_SAMPLERATE * (1 << RESOLUTION_ACTUAL)))
#define TIMER_REPETITION_COUNTER_REMAINDER ((SDK_HCLK_MHZ * 1000000) % (USER_AUDIO_SAMPLERATE * (1 << RESOLUTION_ACTUAL)))
_Static_assert(TIMER_REPETITION_COUNTER_INIT > 0, "Incorrect configuration!!!");
#if USER_AUDIO_RESOLUTION == AUDIO_RESOLUTION_16BIT
#if USER_AUDIO_PCM_FORMAT == AUDIO_PCM_UNSIGNED
typedef uint16_t pcm_src_item_size_t;
#else
typedef int16_t pcm_src_item_size_t;
#endif
#else
#if USER_AUDIO_PCM_FORMAT == AUDIO_PCM_UNSIGNED
typedef uint8_t pcm_src_item_size_t;
#else
typedef int8_t pcm_src_item_size_t;
#endif
#endif
#if RESOLUTION_ACTUAL > 8
typedef uint16_t pcm_buf_item_size_t;
#else
typedef uint8_t pcm_buf_item_size_t;
#endif

#define UNSIGNED_MSB (1 << ((USER_AUDIO_RESOLUTION)*8 - 1))

uint8_t get_output_io_1(void);
uint8_t get_output_io_2(void);
uint8_t *get_pcm_buf0(void);
uint8_t *get_pcm_buf1(void);
uint8_t *get_pcm_buf2(void);
uint8_t *get_pcm_buf3(void);
void audio_handle_pcm(void *dst_pcm_buf1, void *dst_pcm_buf2, const pcm_src_item_size_t *raw_pcm_buf);
void audio_set_stop_flag(void);
void audio_start(uint32_t audio_base, uint32_t audio_length);
void audio_stop(void);
void audio_hw_init(void);
void audio_hw_deinit(void);
#endif
