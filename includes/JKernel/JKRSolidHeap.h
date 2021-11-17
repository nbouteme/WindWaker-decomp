#pragma once
#include <ctypes.h>



namespace JKRSolidHeap {
JKRSolidHeap * create(ulong maxSize,JKRHeap *pParent,bool bReportErrors);
}
