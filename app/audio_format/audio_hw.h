#include "compile_flag.h"
#include "..\app_config.h"
#include "user_audio_config.h"
#include "user_audio_config_for_lib.h"
#ifndef AUDIO_HW_H_
#define AUDIO_HW_H_

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

/**
 ****************************************************************************************
 * \brief Get address of PCM buffer_0.
 * 
 * \return The address of PCM buffer_0.
 * 
 ****************************************************************************************
 */
uint8_t *get_pcm_buf0(void);
/**
 ****************************************************************************************
 * \brief Get address of PCM buffer_1.
 * 
 * \return The address of PCM buffer_1.
 * 
 ****************************************************************************************
 */
uint8_t *get_pcm_buf1(void);
/**
 ****************************************************************************************
 * \brief Get address of PCM buffer_2.
 * 
 * \return The address of PCM buffer_2.
 * 
 ****************************************************************************************
 */
uint8_t *get_pcm_buf2(void);
/**
 ****************************************************************************************
 * \brief Get address of PCM buffer_3.
 * 
 * \return The address of PCM buffer_3.
 * 
 ****************************************************************************************
 */
uint8_t *get_pcm_buf3(void);
/**
 ****************************************************************************************
 * \brief Function to handle raw PCM data.
 * 
 * \param[out]  dst_pcm_buf1         Buffer to contain handled PCM data for channel 1.
 * \param[out]  dst_pcm_buf2         Buffer to contain handled PCM data for channel 2.
 * \param[in]   raw_pcm_buf          Buffer to contain input raw PCM data.
 * 
 ****************************************************************************************
 */
void audio_handle_pcm(void *dst_pcm_buf1, void *dst_pcm_buf2, const pcm_src_item_size_t *raw_pcm_buf);
/**
 ****************************************************************************************
 * \brief Set stop flag for audio play.
 * 
 ****************************************************************************************
 */
void audio_set_stop_flag(void);
/**
 ****************************************************************************************
 * \brief Function to initialize audio play for specific format.
 * 
 * \param[in]  base         Base address of audio file to play.
 * \param[in]  length       Length of audio file to play.
 * 
 ****************************************************************************************
 */
void audio_play_init(uint32_t base, uint32_t length);
/**
 ****************************************************************************************
 * \brief Function to prepare pcm audio for next half buffer.
 * 
 * \param[in]  current_alt  Flag for dma pingpong buffer.
 * 
 ****************************************************************************************
 */
void audio_prepare_next_half(bool current_alt);
/**
 ****************************************************************************************
 * \brief Get value of SINGLE_BUF_SIZE.
 * 
 * \return Value of SINGLE_BUF_SIZE.
 * 
 ****************************************************************************************
 */
uint16_t get_single_buf_size(void);
/**
 ****************************************************************************************
 * \brief Get value of PCM_BUF_SIZE.
 * 
 * \return Value of PCM_BUF_SIZE.
 * 
 ****************************************************************************************
 */
uint16_t get_pcm_buf_size(void);

#endif
