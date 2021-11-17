#pragma once
#include <ctypes.h>



namespace gx {
void __GXXfVtxSpecs(void);
void GXSetVtxDesc(GXAttr param_1,GXAttrType param_2);
void __GXSetVCD(void);
void __GXCalculateVLim(void);
void GXClearVtxDesc(void);
void GXSetVtxAttrFmt(GXVtxFmt param_1,GXAttr param_2,GXCompCnt param_3,GXCompType param_4,byte frac);
void GXSetVtxAttrFmtv(uint param_1,int *param_2);
void __GXSetVAT(void);
void GXGetVtxAttrFmt(int param_1,undefined4 param_2,uint *param_3,uint *param_4,byte *param_5);
void GXGetVtxAttrFmtv(undefined4 param_1,int *param_2);
void GXSetArray(GXAttr attr,uint dataPointer,uint dataSize);
void GXInvalidateVtxCache(void);
void GXSetTexCoordGen2(GXTexCoordID dst_coord,GXTexGenType func,GXTexGenSrc src_param,GXTexMtx mtx,bool normalize,GXPTTexMtx postmtx);
void GXSetNumTexGens(uint param_1);
}
