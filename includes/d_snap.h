#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000084
extern undefined1 dSnap_packet;

//[Data] Expected size is 0x000018
extern undefined1 dSnap_packet;

//[Data] Expected size is 0x00000c
extern undefined1 dSnap_RegistObjElm;


namespace d_snap {
//[BSS] Expected size is 0x000ee8
extern undefined4 l_snap;
int dSnap_PhotoIndex2TableIndex(int param_1);
byte dSnap_GetFigRoomId(int figure);
}

namespace d_snap {
void dSnap_MatDl(void);
void dSnap_AlphaClearDL(void);
}

namespace d_snap {
void dSnap_Create(void);
void dSnap_ReleaseShutter(void);
void dSnap_Execute(void);
undefined4 dSnap_GetResult(void);
undefined dSnap_GetResultDetail(void);
void dSnap_RegistSnapObj(dSnap_Obj *param_1);
void dSnap_RegistFig(double param_1,double param_2,double param_3,byte param_4,fopAc_ac_c *param_5);
void dSnap_RegistFig(byte param_1,fopAc_ac_c *param_2,cXyz *param_3,short param_4,float param_5,float param_6,float param_7);
void dSnap_DebugDraw(void);
void dSnap_Delete(void);
}

namespace d_snap {
void __sinit_d_snap_cpp(void);
}
