#include <stdint.h>
#include <string.h>
#include "platform.h"
#include "audio_play_pcm.h"
#include "..\..\audio_hw.h"
#include "..\audio_format_common.h"

#if USER_AUDIO_FORMAT == AUDIO_PCM

static uint32_t audio_flash_offset;
static uint32_t audio_flash_base;
static uint32_t audio_flash_length;

void audio_prepare_next_half(bool current_alt)
{
    uint8_t pcm_buff[PCM_BUF_SIZE];
    user_read_audio_data(audio_flash_base + audio_flash_offset, &pcm_buff[0], PCM_BUF_SIZE);
    uint8_t *target_buf1;
    uint8_t *target_buf2;
    if (current_alt)
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
    audio_flash_offset += PCM_BUF_SIZE;
    if (audio_flash_offset > audio_flash_length)
    {
        // audio_stop();   
        audio_set_stop_flag();  
        uint32_t fill_zero_bytes = audio_flash_offset - audio_flash_length;
        if (audio_flash_offset > 0)
        {
            uint32_t length = fill_zero_bytes * (RESOLUTION_ACTUAL > 8 ? 2: 1);
            memset(&target_buf1[SINGLE_BUF_SIZE - length], 0, length);
            if (target_buf2 != NULL)
            {
                memset(&target_buf2[SINGLE_BUF_SIZE - length], 0, length);
            }
        }     
    }
}
void audio_play_init(uint32_t base, uint32_t length)
{
    audio_flash_offset = 0;
    audio_flash_base = base;
    audio_flash_length = length;
}
#endif
