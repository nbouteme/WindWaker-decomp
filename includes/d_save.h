#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace d_save {
//Expected size is 0x00000c
extern struct cXyz l_offsetPos$7549;

//Expected size is 0x000001
extern byte init$7551;

}

namespace dStage_roomControl_c {
int getZoneNo(int roomNo);
}
