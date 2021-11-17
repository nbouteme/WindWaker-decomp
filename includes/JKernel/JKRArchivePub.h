#pragma once
#include <ctypes.h>



namespace JKRArchive {
undefined * check_mount_already(long param_1);
}

namespace JKRArchive {
int mount(long param_1,EMountMode mountMode,JKRHeap *param_3,EMountDirection param_4);
}

namespace JKRArchive {
int getGlbResource(ulong param_1,char *param_2,JKRArchive *param_3);
}

namespace JKRArchive {
int readTypeResource(void *pDst,ulong size,ulong param_3,char *pFilename,JKRArchive *pArc);
}
