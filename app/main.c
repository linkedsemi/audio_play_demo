#include <stdint.h>
#include <stdbool.h>
#include "platform.h"
#include "io_config.h"
#include "spi_flash.h"
#include "audio_hw.h"
#include ".\audio_format\audio_format_common.h"
#include "user_audio_config.h"

static struct user_audio_config_t user_audio_config_array[] = USER_AUDIO_CONFIG;
uint8_t get_output_io_1(void)
{
    return USER_AUDIO_OUTPUT_IO_1;
}
#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL
uint8_t get_output_io_2(void)
{
    return USER_AUDIO_OUTPUT_IO_2;
}
#endif
void user_read_audio_data(uint32_t offset, uint8_t *buf, uint16_t length)
{
    spi_flash_quad_io_read(offset, buf, length);
}

static volatile bool audio_play_cplt_flag;
static void user_audio_play_cplt_func(void *param)
{
    *(bool *)param = true;
}
int main(void)
{
    sys_init_none();
    audio_hw_init();
    audio_play_cplt_flag = false;
    audio_start(user_audio_config_array[0].base, user_audio_config_array[0].length, &user_audio_play_cplt_func, (void*)&audio_play_cplt_flag);
    while(!audio_play_cplt_flag);
    audio_play_cplt_flag = false;
    audio_start(user_audio_config_array[1].base, user_audio_config_array[1].length, &user_audio_play_cplt_func, (void*)&audio_play_cplt_flag);
    
    while (1);    
}
