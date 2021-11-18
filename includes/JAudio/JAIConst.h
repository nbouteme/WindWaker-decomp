#pragma once
#include <ctypes.h>



namespace JAInter {

namespace Const {
//[Data] Expected size is 0x00000c
extern undefined1 dummyZeroVec;

//[Data] Expected size is 0x000020
extern undefined1 sCInfos_0;

//[BSS] Expected size is 0x00000c
extern undefined1 nullCamera;
//[BSS] Expected size is 0x000010
extern undefined1 nullActor;
//[BSS] Expected size is 0x000030
extern undefined1 camMtx;
//[BSS] Expected size is 0x00000c
extern undefined1 camTrans;
//[BSS] Expected size is 0x00000c
extern undefined1 camPreTrans;
//[BSS] Expected size is 0x000004
extern undefined1 random;
}
}

namespace JAudio {
void __sinit_JAIConst_cpp(void);
}
