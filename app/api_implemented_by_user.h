#include <stdint.h>
#include "compile_flag.h"
#include "lsdmac.h"
#include "lstimer.h"
#ifndef AUDIO_FORMAT_COMMON_H_
#define AUDIO_FORMAT_COMMON_H_
/**
 ****************************************************************************************
 * \brief Get audio output channel 1. The function should be implemented by user!!!
 * 
 * \return The GPIO of output IO 1.
 * 
 ****************************************************************************************
 */
uint8_t get_output_io_1(void);
/**
 ****************************************************************************************
 * \brief Get audio output channel 2. The function should be implemented by user under 
 * differential mode!!!
 * 
 * \return The GPIO of output IO 2.
 * 
 ****************************************************************************************
 */
uint8_t get_output_io_2(void);
/**
 ****************************************************************************************
 * \brief Get audio play volume setting
 * 
 * \return Volume setting.
 * 
 ****************************************************************************************
 */
uint8_t get_volume_setting(void);
/**
 ****************************************************************************************
 * \brief Read user audio data. This function is supposed to be implemented by user.
 * 
 * \param[in]  offset      Offset of audio data to be read.
 * \param[out] buf         Buffer to contain data to read.
 * \param[in]  length      Length of the data to read in units of byte.
 * 
 ****************************************************************************************
 */
void user_read_audio_data(uint32_t offset, uint8_t *buf, uint16_t length);
#endif
