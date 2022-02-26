#include <stdint.h>
#ifndef USER_AUDIO_API_H_
#define USER_AUDIO_API_H_
/**
 ****************************************************************************************
 * \brief Audio start play function.
 * 
 * \param[in]  audio_base         Buffer address for user audio.
 * \param[in]  audio_length       Audio data length in units of byte.
 * \param[in]  play_cplt_cb       Audio play complete callback function defined by user.
 *                                The function will be called in interrupt;
 * \param[in]  param              Parameter for play_cplt_cb.
 * 
 ****************************************************************************************
 */
void audio_start(uint32_t audio_base, uint32_t audio_length, void (*play_cplt_cb)(void *), void *param);
/**
 ****************************************************************************************
 * \brief Stop audio play.
 * 
 ****************************************************************************************
 */
void audio_stop(void);
/**
 ****************************************************************************************
 * \brief Hardware initialization for audio play.
 * 
 ****************************************************************************************
 */
void audio_hw_init(void);
/**
 ****************************************************************************************
 * \brief Hardware deinitialization for audio play.
 * 
 ****************************************************************************************
 */
void audio_hw_deinit(void);
#endif
