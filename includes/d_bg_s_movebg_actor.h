#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000028
extern undefined1 dBgS_MoveBgActor;

//[BSS] Expected size is 0x000004
extern pointer dBgS_MoveBgActor;
//[BSS] Expected size is 0x000004
extern int dBgS_MoveBgActor;
//[BSS] Expected size is 0x000004
extern pointer dBgS_MoveBgActor;

namespace d_bg_s_movebg_actor {
void CheckCreateHeap(dBgS_MoveBgActor *actor);
}
