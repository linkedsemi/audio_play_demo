#include <stdint.h>
#include "platform.h"
#include "audio_play_adpcm.h"
#include "audio_format_adpcm.h"
#include "..\audio_hw.h"
#include "..\..\api_implemented_by_user.h"

#if USER_AUDIO_FORMAT == AUDIO_ADPCM
#define ADPCM_BlOCK_SIZE 256

static uint32_t audio_flash_offset;
static uint32_t audio_flash_base;
static uint32_t audio_flash_length;

void audio_prepare_next_half(bool current_alt)
{
    uint8_t pcm_buff[PCM_BUF_SIZE];
    uint8_t Flash_ADPCM_Buff[ADPCM_BlOCK_SIZE];
    user_read_audio_data(audio_flash_base + audio_flash_offset, &Flash_ADPCM_Buff[0], ADPCM_BlOCK_SIZE);
    audio_flash_offset += ADPCM_BlOCK_SIZE;
    if (audio_flash_offset >= audio_flash_length)
    {
        // audio_stop();   
        audio_set_stop_flag();  
        uint32_t fill_zero_bytes = audio_flash_offset - audio_flash_length;
        if (fill_zero_bytes > 0)
        {
            memset(&Flash_ADPCM_Buff[ADPCM_BlOCK_SIZE - fill_zero_bytes], 0, fill_zero_bytes);
        }
    }
    Adpcm_Decode_Block((pcm_src_item_size_t *)&pcm_buff, (const uint8_t *)&Flash_ADPCM_Buff[0], ADPCM_BlOCK_SIZE, 1);
    uint8_t *target_buf1;
    uint8_t *target_buf2;
    if (current_alt) // alt half is working, try to update data of prim
    {
        target_buf1 = get_pcm_buf0();
        target_buf2 = get_pcm_buf2();
    }
    else
    {
        target_buf1 = get_pcm_buf1();
        target_buf2 = get_pcm_buf3();   
    }

    audio_handle_pcm(target_buf1, target_buf2, (const pcm_src_item_size_t*)&pcm_buff[0]);
}

void audio_play_init(uint32_t base, uint32_t length)
{
    audio_flash_offset = 0;
    audio_flash_base = base;
    audio_flash_length = length;
}
#endif
