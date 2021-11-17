#pragma once
#include <ctypes.h>



namespace d_bg_s {
void dBgS_ChangeAttributeCode(int param_1,uint *param_2);
}

namespace d_bg_s {
uint dBgS_GetRoomPathPntNo(uint param_1);
}

namespace d_bg_s {
void dBgS_MoveBGProc_Typical(dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,csXyz *param_6,csXyz *param_7);
void dBgS_MoveBGProc_RotY(dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,csXyz *param_6,csXyz *param_7);
void dBgS_MoveBGProc_TypicalRotY(dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,csXyz *param_6,csXyz *param_7);
void dBgS_MoveBGProc_Trans(cBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,cXyz *param_6,csXyz *param_7);
}
