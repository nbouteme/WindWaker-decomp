#pragma once
#include <ctypes.h>

#include <MTX34.h>

//Expected size is 0x000030
extern struct MTX34 mDoMtx_stack_c;

//Expected size is 0x000300
extern undefined1 mDoMtx_stack_c;


namespace m_Do_mtx {
//Expected size is 0x00011c
extern undefined4 mDoMtx_quatStack;

//Expected size is 0x000001
extern undefined mDoMtx_stack;

void mDoMtx_XYZrotM(MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void mDoMtx_ZXYrotS(MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void mDoMtx_ZXYrotM(MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void mDoMtx_XrotS(float *param_1,uint param_2);
void mDoMtx_XrotM(MTX34 *param_1,short param_2);
void mDoMtx_YrotS(float *param_1,uint param_2);
void mDoMtx_YrotM(MTX34 *param_1,short param_2);
void mDoMtx_ZrotS(float *param_1,uint param_2);
void mDoMtx_ZrotM(MTX34 *param_1,short param_2);
void mDoMtx_lookAt(MTX34 *pDst,float *param_2,float *param_3,undefined4 param_4);
}

namespace m_Do_mtx {
void mDoMtx_lookAt(MTX34 *param_1,cXyz *pEye,cXyz *pCenter,cXyz *pUp,int bank);
void mDoMtx_concatProjView(MTX34 *param_1,MTX34 *param_2,MTX34 *param_3);
void mDoMtx_inverseTranspose(MTX34 *param_1,MTX34 *param_2);
void mDoMtx_QuatConcat(float *param_1,float *param_2,float *param_3);
void mDoMtx_MtxToRot(MTX34 *mtx,csXyz *outRot);
}

namespace mDoMtx_stack_c {
undefined4 push(void);
undefined4 pop(void);
void transM(float param_1,float param_2,float param_3);
void scaleM(float param_1,float param_2,float param_3);
}

namespace mDoMtx_stack_c {
void quatM(Quaternion *param_1);
}

namespace m_Do_mtx {
void __sinit_m_Do_mtx_cpp(void);
}
