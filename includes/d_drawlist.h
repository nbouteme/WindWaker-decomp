#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <Demangler/_GXTexObj.h>
#include <dDlst_2DT2_c.h>
#include <GXStruct.h/_GXColor.h>


namespace d_drawlist {
//[Data] Expected size is 0x000041
extern undefined l_backRevZMat;

//[Data] Expected size is 0x00003c
extern undefined l_frontZMat;

//[Data] Expected size is 0x00002a
extern undefined l_frontNoZSubMat;

//[Data] Expected size is 0x0001f8
extern float l_bonboriPos[133];

//[Data] Expected size is 0x0000a7
extern undefined l_bonboriDL;

//[Data] Expected size is 0x0001e0
extern undefined l_s_beam_checkPos;

//[Data] Expected size is 0x0000f8
extern undefined l_s_beam_checkDL;

//[Data] Expected size is 0x000060
extern undefined l_cubePos;

//[Data] Expected size is 0x00004a
extern undefined l_cubeDL;

//[Data] Expected size is 0x000408
extern undefined l_bonbori2Pos;

//[Data] Expected size is 0x0002a8
extern undefined l_bonbori2DL;

//[Data] Expected size is 0x000064
extern undefined l_matDL$5108;

//[Data] Expected size is 0x000010
extern undefined l_vtxDescList$5111;

//[Data] Expected size is 0x000020
extern undefined l_vtxAttrFmtList$5112;

//[Data] Expected size is 0x000060
extern undefined l_shadowVolPos;

//[Data] Expected size is 0x00004a
extern undefined l_shadowVolDL;

//[Data] Expected size is 0x000055
extern undefined l_shadowProjMat;

//[Data] Expected size is 0x00005a
extern undefined l_shadowVolMat;

//[Data] Expected size is 0x000055
extern undefined l_clearMat;

//[Data] Expected size is 0x000055
extern undefined l_frontMat;

//[Data] Expected size is 0x00003c
extern undefined l_backSubMat;

//[Data] Expected size is 0x0000a8
extern undefined l_simpleShadowPos;

//[Data] Expected size is 0x000058
extern undefined l_shadowVolumeDL;

//[Data] Expected size is 0x000055
extern undefined l_shadowSealTexDL;

//[Data] Expected size is 0x000055
extern undefined l_shadowSealTex2DL;

//[Data] Expected size is 0x000069
extern undefined l_shadowSealDL;

//[Data] Expected size is 0x000084
extern undefined l_matDL$5761;

//[Data] Expected size is 0x000055
extern undefined l_mirrorProjMat;

//[Data] Expected size is 0x00006c
extern undefined l_backMat$6018;

//[Data] Expected size is 0x000030
extern undefined mtx_adj$6259;

}
//[Data] Expected size is 0x000018
extern undefined1 dDlst_alphaInvVolPacket;

//[Data] Expected size is 0x000018
extern undefined1 dDlst_alphaVolPacket;

//[Data] Expected size is 0x000018
extern undefined1 dDlst_mirrorPacket;

//[Data] Expected size is 0x00000c
extern undefined1 ShdwDrawPoly_c;

//[Data] Expected size is 0x00000c
extern undefined1 cBgS_ShdwDraw;

//[Data] Expected size is 0x000014
extern pointer dDlst_shadowPoly_c;

//[Data] Expected size is 0x000014
extern pointer dDlst_shadowRealPoly_c;

//[Data] Expected size is 0x000018
extern undefined1 dDlst_alphaModelPacket;

//[Data] Expected size is 0x000010
extern pointer dDlst_effectLine_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2D_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DMt_c;

//[Data] Expected size is 0x000010
extern pointer dDlst_2Dm_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DM_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DT2_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DT_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DPoint_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DTri_c;


namespace d_drawlist {
//[Data] Expected size is 0x000004
extern undefined4 l_color$4348;

//[Data] Expected size is 0x000004
extern undefined4 l_color$5298;

//[Data] Expected size is 0x000004
extern undefined4 l_color$5690;

//[Data] Expected size is 0x000004
extern undefined4 clearColor$5775;

//[Data] Expected size is 0x000004
extern undefined4 l_color$5884;

}
//[Data] Expected size is 0x000004
extern struct _GXColor dDlst_list_c;

//[BSS] Expected size is 0x000020
extern struct _GXTexObj dDlst_shadowControl_c;

namespace d_drawlist {
//[BSS] Expected size is 0x00000c
extern struct cXyz l_p1Offset$5970;
//[BSS] Expected size is 0x00000c
extern struct cXyz l_p2Offset$5974;
}
//[BSS] Expected size is 0x000044
extern struct dDlst_2DT2_c dDlst_list_c;

namespace d_drawlist {
//[BSS] Expected size is 0x000001
extern undefined1 init$5972;
//[BSS] Expected size is 0x000001
extern undefined1 init$5976;
}
//[BSS] Expected size is 0x000004
extern struct ResTIMG * dDlst_list_c;
//[BSS] Expected size is 0x000004
extern struct ResTIMG * dDlst_list_c;
//[BSS] Expected size is 0x000001
extern byte dDlst_list_c;
//[BSS] Expected size is 0x000004
extern float dDlst_list_c;
//[BSS] Expected size is 0x000004
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
