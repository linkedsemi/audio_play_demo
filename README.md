# audio_play_demo


**- For engineers of LS, before debugging & development, please follow the steps below to compile:**

1. Git clone audio_play_demo locally based on internal repository url.

1. Use command "git submodule update --init" to fetch submodules (LS_SDK & audio_play) with corresponding versions.

1. Modify user_audio_config.h(including audio_hw.h if RESOLUTION_DEFAULT need to be modified). _**Do not make any modification for the head files in the following steps!!!**_

1. Enter audio_play portfolio and execute "Scons install" to generate lib file in target directory(LS_SDK/soc/arm_cm/le501x/bin).

1. Enter app portfolio and execute "Scons" to generate production hex file.

1. Download audio files & production hex file to flash.

**For clients, please follow the steps below to compile.**

1. Git clone audio_play_demo locally based on user repository url.

1. Use command "git submodule update --init --depth=1" to fetch other submodule(LS_SDK).

1. Modify user_audio_config.h, and copy the corresponding lib file(app/libs/lib_audio_play_xxx.o) to "LS_SDK/soc/arm_cm/le501x/bin", if can be found. Remember renaming it to "lib_audio_play.o" after copy. Try to contact the AE/FAE if no corresponding lib file can be found.

1. Enter app portfolio and execute "Scons" to generate production hex file.

1. Download audio files & production hex file to flash.
