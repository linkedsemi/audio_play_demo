#include <stdint.h>
#include <stdbool.h>
#include "platform.h"
#include "le501x.h"
#include "compile_flag.h"
#include "io_config.h"
#include "spi_flash.h"
#include "lsdmac.h"
#include "user_audio_config_for_lib.h"
#include "user_audio_config.h"
#include "api_implemented_by_user.h"
#include "user_audio_api.h"

DEF_DMA_CONTROLLER(dmac1_inst, DMAC1);

struct audio_hw_config user_audio_hw_config = 
{
    .dmac_inst_ptr = &dmac1_inst,
    .dma_channel1 = 1,
    .dma_channel2 = 2,
    .timer_irq = GPTIMC1_IRQn,
    .handshake = CH_LSGPTIM1_UP,
    .timer_inst = LSGPTIMC,
};

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
uint8_t get_volume_setting(void)
{
    return AUDIO_PCM_VOLUME_1_2;
}
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
    DMA_CONTROLLER_INIT(dmac1_inst);
    audio_hw_init(&user_audio_hw_config);
    audio_play_cplt_flag = false;
    audio_start(user_audio_config_array[0].base, user_audio_config_array[0].length, &user_audio_play_cplt_func, (void*)&audio_play_cplt_flag);
    while(!audio_play_cplt_flag);
    audio_play_cplt_flag = false;
    audio_start(user_audio_config_array[1].base, user_audio_config_array[1].length, &user_audio_play_cplt_func, (void*)&audio_play_cplt_flag);

    while (1);
}
