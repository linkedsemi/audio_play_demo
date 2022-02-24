#include <stdint.h>
#ifndef AUDIO_FORMAT_COMMON_H_
#define AUDIO_FORMAT_COMMON_H_
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
