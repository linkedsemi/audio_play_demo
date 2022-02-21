# audio_play_demo


**- For engineers of LS, before debugging & development, please follow the steps below to compile:**

1. Git clone audio_play_demo locally based on internal repository url.

1. Use command "git submodule update --init" to fetch submodules (LS_SDK & audio_play) with corresponding versions.

1. Modify user_audio_config.h(including audio_hw.h if RESOLUTION_DEFAULT need to be modified). _**Do not make any modification for the head files in the following steps!!!**_

1. Enter audio_play portfolio and execute "Scons install" to generate lib file in target directory(LS_SDK/soc/arm_cm/le501x/bin).

1. Enter app portfolio and execute "Scons" to generate production hex file.

1. Erase flash and download audio files to flash by JFlash or other programming tools. Before programming, ensure that the start address for of the audio files required by JFlash should be equal with the base address configuration in user_audio_config.h.

1. Download production hex file to flash. **Do not erase flash anymore in this step!!!**

**- For clients, please follow the steps below to compile:**

1. Download the audio_play_demo zip file then unzip it. Another way is fetching audio_play_demo with the repository url by git. 

1. Unzip the zip file of LS_SDK in the root directory of audio_play_demo.

1. Modify user_audio_config.h, and copy the corresponding lib file(app/libs/lib_audio_play_xxx.o) to "LS_SDK/soc/arm_cm/le501x/bin", if can be found. Remember renaming it to "lib_audio_play.o" after copy. Try to contact the AE/FAE if no corresponding lib file can be found.

_If you are using VS Code & ARMGCC:_

4. Enter app portfolio and execute "Scons" to generate production hex file.

_If you are using Keil:_

4. Enter audio_play_demo\app\le501x\uvision5, open Keil project, then compile the default application.

_Then:_

5. Erase flash and download audio files to flash by JFlash or other programming tools. Before programming, ensure that the start address for of the audio files required by JFlash should be equal with the base address configuration in user_audio_config.h.

1. Download production hex file to flash. **Do not erase flash anymore in this step!!!**
