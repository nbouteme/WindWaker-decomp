#pragma once
#include <ctypes.h>



namespace JKRSolidHeap {
//[Data] Expected size is 0x000060
extern undefined1 __vt;

JKRSolidHeap * create(ulong maxSize,JKRHeap *pParent,bool bReportErrors);
}
