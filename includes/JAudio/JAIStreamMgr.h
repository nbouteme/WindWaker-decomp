#pragma once
#include <ctypes.h>



namespace JAInter {
//[Data] Expected size is 0x000040
extern undefined1 StreamLib;

//[Data] Expected size is 0x000020
extern undefined1 StreamLib;

//[Data] Expected size is 0x000004
extern undefined1 StreamLib;

//[Data] Expected size is 0x000004
extern undefined1 StreamLib;

//[Data] Expected size is 0x000004
extern undefined1 StreamLib;

//[BSS] Expected size is 0x00000c
extern undefined1 StreamMgr;
//[BSS] Expected size is 0x00003c
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000020
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000064
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000014
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000002
extern undefined1 StreamMgr;
//[BSS] Expected size is 0x000004
extern undefined1 StreamMgr;
//[BSS] Expected size is 0x000004
extern undefined1 StreamMgr;
//[BSS] Expected size is 0x000004
extern undefined1 StreamMgr;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000008
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000001
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
//[BSS] Expected size is 0x000004
extern undefined1 StreamLib;
}

namespace JAudio {
//[BSS] Expected size is 0x000004
extern undefined4 before$1183;
//[BSS] Expected size is 0x000001
extern undefined1 init$1184;
//[BSS] Expected size is 0x000002
extern undefined2 L1$1209;
//[BSS] Expected size is 0x000002
extern undefined2 L2$1210;
//[BSS] Expected size is 0x000002
extern undefined2 R1$1211;
//[BSS] Expected size is 0x000002
extern undefined2 R2$1212;
//[BSS] Expected size is 0x000004
extern undefined4 oldstat$1491;
//[BSS] Expected size is 0x000001
extern undefined1 init$1492;
//[BSS] Expected size is 0x000004
extern undefined4 old_dspside$1515;
//[BSS] Expected size is 0x000001
extern undefined1 init$1516;
}

namespace JAInter {

namespace StreamMgr {
void storeStreamBuffer(JAISound **param_1,Actor *param_2,ulong param_3,ulong param_4,uchar param_5,void *param_6);
}
}

namespace JAudio {
void __sinit_JAIStreamMgr_cpp(void);
}
