#pragma once
#include <ctypes.h>



namespace JAInter {

namespace Const {
//Expected size is 0x00000c
extern undefined1 nullCamera;

//Expected size is 0x000010
extern undefined1 nullActor;

//Expected size is 0x000030
extern undefined1 camMtx;

//Expected size is 0x00000c
extern undefined1 camTrans;

//Expected size is 0x00000c
extern undefined1 camPreTrans;

//Expected size is 0x000004
extern undefined1 random;

}
}

namespace JAudio {
void __sinit_JAIConst_cpp(void);
}
