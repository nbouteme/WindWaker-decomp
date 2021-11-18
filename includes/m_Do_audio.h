#pragma once
#include <ctypes.h>

#include <JAIZelInst.h>

//[Data] Expected size is 0x000024
extern undefined1 mDoAud_zelAudio_c;

//[BSS] Expected size is 0x00004c
extern struct JAIZelInst mDoAud_zelAudio_c;

namespace m_Do_audio {
//[BSS] Expected size is 0x0020f4
extern undefined4 g_mDoAud_zelAudio;
}
//[BSS] Expected size is 0x000001
extern undefined1 mDoAud_zelAudio_c;
//[BSS] Expected size is 0x000001
extern undefined1 mDoAud_zelAudio_c;
//[BSS] Expected size is 0x000001
extern byte mDoAud_zelAudio_c;
//[BSS] Expected size is 0x000001
extern undefined1 mDoAud_zelAudio_c;

namespace m_Do_audio {
//[BSS] Expected size is 0x000004
extern undefined4 g_mDoAud_audioHeap;
//[BSS] Expected size is 0x000004
extern undefined4 mDoAud_StreamBufferPointer;
//[BSS] Expected size is 0x000001
extern undefined1 mDoAud_StreamBufferBlocks;
//[BSS] Expected size is 0x000004
extern undefined4 mDoAud_audioStreamHeap;
//[BSS] Expected size is 0x000004
extern undefined4 l_affCommand;
//[BSS] Expected size is 0x000004
extern undefined4 l_arcCommand;
}

namespace m_Do_audio {
bool mDoAud_isUsedHeapForStreamBuffer(void);
void mDoAud_allocStreamBuffer(undefined4 param_1,void *param_2);
void mDoAud_deallocStreamBuffer(void);
void mDoAud_executeStreamBuffer(void);
void mDoAud_setupStreamBuffer(undefined4 param_1,bool param_2);
void mDoAud_Create(undefined4 param_1,undefined4 param_2);
void mDoAud_Execute(void);
uint mDoAud_getTactDirection(int param_1,uint param_2);
void mDoAud_setSceneName(char *pSceneName,long startCode,long layerNo);
undefined4 mDoAud_load1stDynamicWave(void);
char cLib_calcTimer(char *param_1);
void __sinit_m_Do_audio_cpp(void);
}
