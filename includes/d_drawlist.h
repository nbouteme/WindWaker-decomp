#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <Demangler/_GXTexObj.h>
#include <dDlst_2DT2_c.h>

//Expected size is 0x000020
extern struct _GXTexObj dDlst_shadowControl_c;


namespace d_drawlist {
//Expected size is 0x00000c
extern struct cXyz l_p1Offset$5970;

//Expected size is 0x00000c
extern struct cXyz l_p2Offset$5974;

}
//Expected size is 0x000044
extern struct dDlst_2DT2_c dDlst_list_c;


namespace d_drawlist {
//Expected size is 0x000001
extern undefined1 init$5972;

//Expected size is 0x000001
extern undefined1 init$5976;

}
//Expected size is 0x000004
extern struct ResTIMG * dDlst_list_c;

//Expected size is 0x000004
extern struct ResTIMG * dDlst_list_c;

//Expected size is 0x000001
extern byte dDlst_list_c;

//Expected size is 0x000004
extern float dDlst_list_c;

//Expected size is 0x000004
extern float dDlst_list_c;


namespace dDlst_alphaModel_c {
dDlst_alphaModel_c * create(int param_1);
}

namespace d_drawlist {
J3DDrawBuffer * J3DDrawBuffer__create__FUl(ulong param_1);
}

namespace d_drawlist {
undefined * psdRealCallBack(void);
void seaRealCallBack(int param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4);
undefined4 realPolygonCheck(double param_1,double param_2,float *param_3,float *param_4,undefined4 param_5);
}

namespace d_drawlist {
uint setShadowRealMtx(MTX34 *pDstView,MTX44 *pDstRenderProj,MTX34 *pDstReceiverProj,cXyz *pLightPos,cXyz *pPos,float param_6,float param_7,dDlst_shadowPoly_c *pPoly,float param_9);
}

namespace dDlst_shadowControl_c {
void setSimpleTex(void *param_1);
}

namespace d_drawlist {
void mirrorPolygonCheck(double param_1,cXyz *param_2,cXyz *param_3,undefined4 param_4);
}

namespace dDlst_list_c {
void wipeIn(float param_1,_GXColor *param_2);
void wipeIn(float param_1);
}

namespace d_drawlist {
void dDlst_texSpecmapST(cXyz *param_1,dKy_tevstr_c *param_2,J3DModelData *param_3,float param_4);
}

namespace d_drawlist {
void __sinit_d_drawlist_cpp(void);
}
