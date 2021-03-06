#include <stdint.h>
#include "lsdmac.h"
#include "reg_timer_type.h"
#ifndef USER_AUDIO_API_H_
#define USER_AUDIO_API_H_
/**
  * @brief Audio hardware config struct.
  */
struct audio_hw_config
{
    DMA_Controller_HandleTypeDef* dmac_inst_ptr;    /*!< Dmac instance*/
    uint8_t dma_channel1;                           /*!< Dmac channel 1*/
    uint8_t dma_channel2;                           /*!< Dmac channel 2*/
    uint8_t timer_irq;                              /*!< Timer irq*/
    DMA_ChnSig_TypeDef handshake;                   /*!< Dmac timer handshake*/
    reg_timer_t* timer_inst;                        /*!< Timer instance*/
};

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
 * \param[in]  config            Pointer to audio_hw_config struct.
 * 
 ****************************************************************************************
 */
void audio_hw_init(struct audio_hw_config* config);
/**
 ****************************************************************************************
 * \brief Hardware deinitialization for audio play.
 * 
 ****************************************************************************************
 */
void audio_hw_deinit(void);
#endif
