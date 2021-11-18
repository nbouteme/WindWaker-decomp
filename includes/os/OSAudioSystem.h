#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x000080
extern undefined DSPInitCode;

void __OSInitAudioSystem(void);
void __OSStopAudioSystem(void);
}
