#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace d_save {
//[Data] Expected size is 0x000022
extern undefined2 l_holdEventReg$7593;

//[Data] Expected size is 0x00000a
extern undefined2 l_onEventBit$7604;

//[Data] Expected size is 0x000005
extern undefined l_defaultName$6963;

//[BSS] Expected size is 0x00000c
extern struct cXyz l_offsetPos$7549;
//[BSS] Expected size is 0x000001
extern byte init$7551;
}

namespace dStage_roomControl_c {
int getZoneNo(int roomNo);
}
