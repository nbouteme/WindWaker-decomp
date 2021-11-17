#pragma once
#include <ctypes.h>



namespace d_path {
dPath__Point * dPath_GetPnt(dPath *pPath,int idx);
dPath * dPath_GetRoomPath(int pathIndex,int roomNo);
dPath * dPath_GetNextRoomPath(dPath *pInPath,int roomNo);
undefined4 dPath_GetPolyRoomPathVec(cBgS_PolyInfo *param_1,cXyz *param_2,uint *param_3);
}
