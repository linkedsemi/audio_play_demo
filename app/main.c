#include <stdint.h>
#include "platform.h"
#include "audio_hw.h"
#include "user_audio_config.h"

static struct user_audio_config_t user_audio_config_array[] = USER_AUDIO_CONFIG;
int main(void)
{
    sys_init_none();
    audio_hw_init();
    audio_start(user_audio_config_array[0].base, user_audio_config_array[0].length);
    while (1);    
}
