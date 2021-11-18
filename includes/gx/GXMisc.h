#pragma once
#include <ctypes.h>



namespace gx {
//[BSS] Expected size is 0x000004
extern undefined4 TokenCB;
//[BSS] Expected size is 0x000004
extern undefined4 DrawDoneCB;
//[BSS] Expected size is 0x000001
extern undefined1 DrawDone;
//[BSS] Expected size is 0x000008
extern undefined FinishQueue;
void GXSetMisc(int param_1,int param_2);
void GXFlush(void);
void GXAbortFrame(undefined4 param_1,uint param_2);
void GXSetDrawSync(uint param_1);
void GXSetDrawDone(void);
void GXDrawDone(void);
void GXPixModeSync(void);
void GXPokeAlphaMode(int param_1,ushort param_2);
void GXPokeAlphaRead(ushort param_1);
void GXPokeAlphaUpdate(int param_1);
void GXPokeBlendMode(int param_1,int param_2,int param_3,int param_4);
void GXPokeColorUpdate(int param_1);
void GXPokeDstAlpha(int param_1,ushort param_2);
void GXPokeDither(int param_1);
void GXPokeZMode(ushort param_1,int param_2,int param_3);
void GXPeekARGB(uint param_1,uint param_2,undefined4 *param_3);
void GXPeekZ(uint param_1,uint param_2,undefined4 *param_3);
undefined4 GXSetDrawSyncCallback(undefined4 param_1);
void GXTokenInterruptHandler(undefined4 param_1,undefined4 param_2);
undefined4 GXSetDrawDoneCallback(undefined4 param_1);
void GXFinishInterruptHandler(undefined4 param_1,undefined4 param_2);
void __GXPEInit(void);
}
