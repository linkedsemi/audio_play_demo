#include "audio_definition.h"
#ifndef USER_AUDIO_CONFIG_H_
#define USER_AUDIO_CONFIG_H_

#define USER_AUDIO_FORMAT AUDIO_PCM

#define USER_AUDIO_OUTPUT_MODE AUDIO_OUTPUT_MODE_DIFFERENTIAL
#define USER_AUDIO_SAMPLERATE AUDIO_SAMPLERATE_8K
#define USER_AUDIO_RESOLUTION AUDIO_RESOLUTION_8BIT
#define USER_AUDIO_PCM_FORMAT AUDIO_PCM_UNSIGNED

#define USER_AUDIO_OUTPUT_IO_1 PA08
#if USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_DIFFERENTIAL
#define USER_AUDIO_OUTPUT_IO_2 PA09
#elif USER_AUDIO_OUTPUT_MODE == AUDIO_OUTPUT_MODE_SINGLE_END

#endif

struct user_audio_config_t
{
    uint32_t base;
    uint32_t length;
};
#if USER_AUDIO_FORMAT == AUDIO_ADPCM
#define USER_AUDIO_CONFIG {                         \
        [0] = {                                     \
            .base = 0xa000,                         \
            .length = 34816,                        \
        },                                          \
        [1] = {                                     \
            .base = 0x13000,                        \
            .length = 34816,                        \
        },                                          \
}
#elif USER_AUDIO_FORMAT == AUDIO_PCM
#define USER_AUDIO_CONFIG {                         \
        [0] = {                                     \
            .base = 0xa000,                         \
            .length = 0x35b0,                       \
        },                                          \
        [1] = {                                     \
            .base = 0x35b0,                         \
            .length = 0x39c2,                       \
        },                                          \
}
#endif
#endif
