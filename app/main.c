#include <stdint.h>
#include "platform.h"
#include "io_config.h"
#include "audio_hw.h"
#include "user_audio_config.h"

static struct user_audio_config_t user_audio_config_array[] = USER_AUDIO_CONFIG;
uint8_t get_output_io_1(void)
{
    return USER_AUDIO_OUTPUT_IO_1;
}
uint8_t get_output_io_2(void)
{
    return USER_AUDIO_OUTPUT_IO_2;
}
int main(void)
{
    sys_init_none();
    audio_hw_init();
    audio_start(user_audio_config_array[0].base, user_audio_config_array[0].length);
    while (1);    
}
